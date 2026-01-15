# matiec CMake 跨平台构建系统迁移计划

## 项目概述

将 matiec（IEC 61131-3 编译器）从 Autotools 构建系统迁移到 CMake，实现 Windows、Linux、macOS **全平台**跨平台构建。

### 目标配置
- **平台**: Windows + Linux + macOS 全覆盖
- **Windows 工具链**: **Clang** (clang-cl 或 LLVM 工具链)
- **Linux/macOS**: GCC / Clang

---

## 当前构建系统分析

### 现有结构
- **构建工具**: Autotools (configure.ac + Makefile.am)
- **依赖**: Bison >= 2.4, Flex, C++ 编译器
- **输出目标**: `iec2c` (IEC→C), `iec2iec` (IEC→IEC)

### 模块依赖关系
```
main.cc
  ├── libstage1_2.a  (词法/语法分析: flex + bison)
  ├── libstage3.a    (语义分析)
  ├── libstage4_c.a / libstage4_iec.a (代码生成)
  ├── libabsyntax.a  (AST 定义)
  └── libabsyntax_utils.a (AST 工具)
```

---

## 实施计划

### Phase 1: 创建根级 CMakeLists.txt

**文件**: `CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.16)
project(matiec VERSION 0.1 LANGUAGES CXX C)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# macOS Homebrew 路径支持
if(APPLE)
    list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/opt/flex")
    list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/opt/bison")
    list(APPEND CMAKE_PREFIX_PATH "/usr/local/opt/flex")
    list(APPEND CMAKE_PREFIX_PATH "/usr/local/opt/bison")
endif()

# Windows winflexbison 自动检测
if(WIN32)
    find_program(BISON_EXECUTABLE NAMES bison win_bison HINTS
        "C:/ProgramData/chocolatey/bin"
        "$ENV{PROGRAMFILES}/win_flex_bison"
    )
    find_program(FLEX_EXECUTABLE NAMES flex win_flex HINTS
        "C:/ProgramData/chocolatey/bin"
        "$ENV{PROGRAMFILES}/win_flex_bison"
    )
endif()

# 查找必要工具
find_package(BISON 2.4 REQUIRED)
find_package(FLEX REQUIRED)

# 跨平台编译选项
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wpointer-arith -Wwrite-strings -Wno-unused)
    if(WIN32)
        add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    endif()
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wall -Wpointer-arith -Wwrite-strings -Wno-unused)
elseif(MSVC)
    add_compile_options(/W3)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
endif()

# Git/Hg 版本信息（可选）
find_package(Git QUIET)
if(GIT_FOUND)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_VERSION
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET
    )
    if(GIT_VERSION)
        add_compile_definitions(HGVERSION="${GIT_VERSION}")
    endif()
endif()

# 添加子目录
add_subdirectory(absyntax)
add_subdirectory(absyntax_utils)
add_subdirectory(stage1_2)
add_subdirectory(stage3)
add_subdirectory(stage4)

# 可执行文件 iec2c
add_executable(iec2c main.cc)
target_link_libraries(iec2c PRIVATE
    stage1_2
    stage3
    stage4_c
    absyntax
    absyntax_utils
)

# 可执行文件 iec2iec
add_executable(iec2iec main.cc)
target_link_libraries(iec2iec PRIVATE
    stage1_2
    stage3
    stage4_iec
    absyntax
    absyntax_utils
)

# 安装规则
install(TARGETS iec2c iec2iec RUNTIME DESTINATION bin)
install(DIRECTORY lib/ DESTINATION lib FILES_MATCHING PATTERN "*.txt" PATTERN "*.h")
```

---

### Phase 2: 各模块 CMakeLists.txt

#### 2.1 absyntax/CMakeLists.txt
```cmake
add_library(absyntax STATIC
    absyntax.cc
    visitor.cc
)

target_include_directories(absyntax PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
)
```

#### 2.2 absyntax_utils/CMakeLists.txt
```cmake
add_library(absyntax_utils STATIC
    absyntax_utils.cc
    add_en_eno_param_decl.cc
    decompose_var_instance_name.cc
    array_dimension_iterator.cc
    case_element_iterator.cc
    function_call_iterator.cc
    function_call_param_iterator.cc
    function_param_iterator.cc
    get_sizeof_datatype.cc
    get_var_name.cc
    search_il_label.cc
    search_base_type.cc
    search_fb_instance_decl.cc
    search_fb_typedecl.cc
    search_varfb_instance_type.cc
    search_var_instance_decl.cc
    spec_init_separator.cc
    type_initial_value.cc
    debug_ast.cc
    get_datatype_info.cc
)

target_include_directories(absyntax_utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(absyntax_utils PUBLIC absyntax)
```

#### 2.3 stage1_2/CMakeLists.txt (关键 - 处理 flex/bison)
```cmake
# Bison 生成语法分析器
bison_target(IecParser
    ${CMAKE_CURRENT_SOURCE_DIR}/iec_bison.yy
    ${CMAKE_CURRENT_BINARY_DIR}/iec_bison.cc
    DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/iec_bison.hh
)

# Flex 生成词法分析器
flex_target(IecLexer
    ${CMAKE_CURRENT_SOURCE_DIR}/iec_flex.ll
    ${CMAKE_CURRENT_BINARY_DIR}/iec_flex.cc
)

# 声明依赖关系：词法分析器依赖语法分析器生成的头文件
add_flex_bison_dependency(IecLexer IecParser)

add_library(stage1_2 STATIC
    ${BISON_IecParser_OUTPUTS}
    ${FLEX_IecLexer_OUTPUTS}
    stage1_2.cc
    create_enumtype_conversion_functions.cc
)

target_compile_definitions(stage1_2 PRIVATE
    DEFAULT_LIBDIR="lib"
    YY_BUF_SIZE=65536
)

# GCC 需要 -fpermissive（代码可能有 C++ 标准兼容问题）
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(stage1_2 PRIVATE -fpermissive)
endif()

target_include_directories(stage1_2
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}  # bison/flex 生成的文件
)

target_link_libraries(stage1_2 PUBLIC absyntax)
```

#### 2.4 stage3/CMakeLists.txt
```cmake
add_library(stage3 STATIC
    stage3.cc
    flow_control_analysis.cc
    fill_candidate_datatypes.cc
    narrow_candidate_datatypes.cc
    forced_narrow_candidate_datatypes.cc
    print_datatypes_error.cc
    datatype_functions.cc
    lvalue_check.cc
    array_range_check.cc
    case_elements_check.cc
    constant_folding.cc
    declaration_check.cc
    enum_declaration_check.cc
    remove_forward_dependencies.cc
)

target_include_directories(stage3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(stage3 PUBLIC absyntax absyntax_utils)
```

#### 2.5 stage4/CMakeLists.txt
```cmake
# stage4 框架（共享的基础代码）
add_library(stage4_base OBJECT stage4.cc)
target_include_directories(stage4_base PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/absyntax
)

# C 代码生成器
add_library(stage4_c STATIC
    $<TARGET_OBJECTS:stage4_base>
    generate_c/generate_c.cc
)
target_include_directories(stage4_c PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/absyntax
)
target_link_libraries(stage4_c PUBLIC absyntax)

# IEC 代码生成器
add_library(stage4_iec STATIC
    $<TARGET_OBJECTS:stage4_base>
    generate_iec/generate_iec.cc
)
target_include_directories(stage4_iec PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/absyntax
)
target_link_libraries(stage4_iec PUBLIC absyntax)
```

---

## 需要创建的文件清单

| 文件路径 | 说明 |
|----------|------|
| `CMakeLists.txt` | 根级构建配置 |
| `absyntax/CMakeLists.txt` | AST 库 |
| `absyntax_utils/CMakeLists.txt` | AST 工具库 |
| `stage1_2/CMakeLists.txt` | 词法/语法分析（flex+bison） |
| `stage3/CMakeLists.txt` | 语义分析 |
| `stage4/CMakeLists.txt` | 代码生成框架 |

---

## 关键技术点

1. **Flex/Bison 集成**: 使用 CMake 内置的 `find_package(BISON)` 和 `find_package(FLEX)`
2. **生成文件路径**: bison/flex 输出到 `CMAKE_CURRENT_BINARY_DIR` (out-of-source build)
3. **include 路径**: 需要同时包含源目录和构建目录（生成的头文件）
4. **OBJECT 库**: stage4.cc 使用 OBJECT 库避免重复编译
5. **Windows 兼容**: 需要 winflexbison

---

## 验证步骤

### Linux
```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
./iec2c --help
./iec2iec --help
```

### macOS
```bash
# 首先安装依赖
brew install flex bison

mkdir build && cd build
cmake ..
make -j$(sysctl -n hw.ncpu)
./iec2c --help
```

### Windows (Clang - 推荐)
```powershell
# 前提：安装 LLVM/Clang 和 winflexbison
# choco install llvm ninja winflexbison3

mkdir build
cd build
cmake -G "Ninja" -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ ..
ninja
.\iec2c.exe --help
```

### Windows (MSVC - 备用)
```powershell
mkdir build
cd build
cmake -G "Visual Studio 17 2022" ..
cmake --build . --config Release
.\Release\iec2c.exe --help
```

---

## 风险和注意事项

1. **winflexbison 兼容性**: Windows 上需要安装 winflexbison，其生成代码可能与 GNU flex/bison 略有差异
2. **-fpermissive 标志**: GCC 特有标志，可能暗示代码有 C++ 标准合规问题，Clang 通常更严格
3. **路径分隔符**: `main.cc` 中有 Windows 路径处理代码，CMake 应保持兼容
4. **版本号获取**: 从 Mercurial 调整为支持 Git
5. **macOS 系统 flex/bison**: macOS 自带版本较旧，需要 Homebrew 安装新版本

---

## Windows Clang 特别说明

Windows 上使用 Clang 有两种模式：
1. **clang-cl**: 使用 MSVC 兼容模式（Visual Studio 集成）
2. **clang++**: 使用 GNU 兼容模式（推荐，与 Linux/macOS 行为一致）

推荐使用 **Ninja** 生成器配合原生 Clang，避免 VS 项目的复杂性。

---

## 依赖安装指南

### Windows
```powershell
# 使用 Chocolatey
choco install llvm ninja winflexbison3

# 或使用 Scoop
scoop install llvm ninja
scoop install main/winflexbison
```

### macOS
```bash
brew install flex bison cmake ninja
```

### Linux (Ubuntu/Debian)
```bash
sudo apt install flex bison cmake ninja-build build-essential
```
