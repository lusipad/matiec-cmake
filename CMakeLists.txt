cmake_minimum_required(VERSION 3.16)
project(matiec VERSION 0.1 LANGUAGES CXX C)

# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Export compile_commands.json for IDE support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# macOS Homebrew paths for flex/bison
if(APPLE)
    # Apple Silicon
    list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/opt/flex")
    list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/opt/bison")
    # Intel Mac
    list(APPEND CMAKE_PREFIX_PATH "/usr/local/opt/flex")
    list(APPEND CMAKE_PREFIX_PATH "/usr/local/opt/bison")
endif()

# Windows winflexbison auto-detection
if(WIN32)
    find_program(BISON_EXECUTABLE NAMES bison win_bison HINTS
        "C:/ProgramData/chocolatey/bin"
        "$ENV{PROGRAMFILES}/win_flex_bison"
        "$ENV{PROGRAMFILES}/WinFlexBison"
    )
    find_program(FLEX_EXECUTABLE NAMES flex win_flex HINTS
        "C:/ProgramData/chocolatey/bin"
        "$ENV{PROGRAMFILES}/win_flex_bison"
        "$ENV{PROGRAMFILES}/WinFlexBison"
    )
endif()

# Find required tools
find_package(BISON 2.4 REQUIRED)
find_package(FLEX REQUIRED)

# Compiler-specific options
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    # Clang (including clang-cl on Windows and AppleClang on macOS)
    add_compile_options(-Wall -Wpointer-arith -Wwrite-strings -Wno-unused)
    # Disable warnings that are errors in older code
    add_compile_options(-Wno-overloaded-virtual -Wno-deprecated-register)
    # Disable C++11 literal suffix warning (code uses old-style PRId64 macros)
    add_compile_options(-Wno-reserved-user-defined-literal)
    if(WIN32)
        add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    endif()
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # GCC
    add_compile_options(-Wall -Wpointer-arith -Wwrite-strings -Wno-unused)
elseif(MSVC)
    # MSVC (fallback support)
    add_compile_options(/W3)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
endif()

# Git version info (optional, replaces Mercurial)
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

# Platform feature detection
include(CheckIncludeFile)
include(CheckFunctionExists)
include(CheckTypeSize)

check_include_file(float.h HAVE_FLOAT_H)
check_include_file(limits.h HAVE_LIMITS_H)
check_include_file(stdint.h HAVE_STDINT_H)
check_include_file(stdlib.h HAVE_STDLIB_H)
check_include_file(string.h HAVE_STRING_H)
check_include_file(strings.h HAVE_STRINGS_H)
check_include_file(sys/timeb.h HAVE_SYS_TIMEB_H)
check_include_file(unistd.h HAVE_UNISTD_H)
check_include_file(stdbool.h HAVE_STDBOOL_H)
check_include_file(inttypes.h HAVE_INTTYPES_H)

check_function_exists(clock_gettime HAVE_CLOCK_GETTIME)
check_function_exists(memset HAVE_MEMSET)
check_function_exists(pow HAVE_POW)
check_function_exists(strcasecmp HAVE_STRCASECMP)
check_function_exists(strdup HAVE_STRDUP)
check_function_exists(strtoul HAVE_STRTOUL)
check_function_exists(strtoull HAVE_STRTOULL)
check_function_exists(malloc HAVE_MALLOC)
check_function_exists(realloc HAVE_REALLOC)
check_function_exists(mktime HAVE_MKTIME)

# Type checks
check_type_size(int8_t HAVE_INT8_T)
check_type_size(int16_t HAVE_INT16_T)
check_type_size(int32_t HAVE_INT32_T)
check_type_size(int64_t HAVE_INT64_T)
check_type_size(uint8_t HAVE_UINT8_T)
check_type_size(uint16_t HAVE_UINT16_T)
check_type_size(uint32_t HAVE_UINT32_T)
check_type_size(uint64_t HAVE_UINT64_T)

# Generate config.h
configure_file(
    ${CMAKE_SOURCE_DIR}/config/config.h.in
    ${CMAKE_BINARY_DIR}/config/config.h
    @ONLY
)

# Include generated config directory
include_directories(${CMAKE_BINARY_DIR})

# Add subdirectories
add_subdirectory(absyntax)
add_subdirectory(absyntax_utils)
add_subdirectory(stage1_2)
add_subdirectory(stage3)
add_subdirectory(stage4)

# Executable: iec2c (IEC 61131-3 to C)
add_executable(iec2c main.cc)
target_include_directories(iec2c PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(iec2c PRIVATE
    stage1_2
    stage3
    stage4_c
    absyntax
    absyntax_utils
)

# Executable: iec2iec (IEC 61131-3 normalizer)
add_executable(iec2iec main.cc)
target_include_directories(iec2iec PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(iec2iec PRIVATE
    stage1_2
    stage3
    stage4_iec
    absyntax
    absyntax_utils
)

# Installation rules
install(TARGETS iec2c iec2iec RUNTIME DESTINATION bin)
install(DIRECTORY lib/ DESTINATION lib
    FILES_MATCHING
    PATTERN "*.txt"
    PATTERN "*.h"
)

# Print configuration summary
message(STATUS "")
message(STATUS "matiec configuration:")
message(STATUS "  C++ compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "  Bison: ${BISON_EXECUTABLE}")
message(STATUS "  Flex: ${FLEX_EXECUTABLE}")
if(GIT_VERSION)
    message(STATUS "  Git version: ${GIT_VERSION}")
endif()
message(STATUS "")
