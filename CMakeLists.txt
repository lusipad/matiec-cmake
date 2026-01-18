cmake_minimum_required(VERSION 3.16)
project(matiec VERSION 0.1.0 LANGUAGES CXX C)

# Options
option(MATIEC_BUILD_SHARED "Build shared library" ON)
option(MATIEC_BUILD_STATIC "Build static library" ON)
option(MATIEC_BUILD_TOOLS "Build command-line tools (iec2c, iec2iec)" ON)
option(MATIEC_BUILD_TESTS "Build unit and integration tests" OFF)
option(MATIEC_INSTALL "Generate install targets" ON)

# C++ standard - C++17 for std::optional, std::string_view, etc.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Export compile_commands.json for IDE support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Position independent code (required for shared library)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

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
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

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

# Include directories
include_directories(${CMAKE_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add subdirectories for internal libraries
add_subdirectory(absyntax)
add_subdirectory(absyntax_utils)
add_subdirectory(stage1_2)
add_subdirectory(stage3)
add_subdirectory(stage4)

# ==============================================================================
# Library: libmatiec
# ==============================================================================

# Collect all internal library sources for the unified library
set(MATIEC_CORE_LIBS
    stage1_2
    stage3
    stage4_c
    stage4_iec
    absyntax
    absyntax_utils
)

# Library source files
set(MATIEC_LIB_SOURCES
    src/matiec_lib.cc
    src/error_reporter.cc
    main.cc
)

# Add Windows-specific source files
if(WIN32)
    list(APPEND MATIEC_LIB_SOURCES util/getopt_compat.c)
endif()

# Static library
if(MATIEC_BUILD_STATIC)
    add_library(matiec_static STATIC ${MATIEC_LIB_SOURCES})
    target_include_directories(matiec_static
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        PRIVATE
            ${CMAKE_SOURCE_DIR}
            ${CMAKE_BINARY_DIR}
    )
    target_link_libraries(matiec_static PRIVATE ${MATIEC_CORE_LIBS})
    set_target_properties(matiec_static PROPERTIES
        OUTPUT_NAME matiec
        ARCHIVE_OUTPUT_NAME matiec
    )

    # Alias for use in subdirectory builds
    add_library(matiec::static ALIAS matiec_static)
endif()

# Shared library
if(MATIEC_BUILD_SHARED)
    add_library(matiec_shared SHARED ${MATIEC_LIB_SOURCES})
    target_compile_definitions(matiec_shared PRIVATE MATIEC_BUILDING_DLL)
    target_include_directories(matiec_shared
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        PRIVATE
            ${CMAKE_SOURCE_DIR}
            ${CMAKE_BINARY_DIR}
    )
    target_link_libraries(matiec_shared PRIVATE ${MATIEC_CORE_LIBS})
    set_target_properties(matiec_shared PROPERTIES
        OUTPUT_NAME matiec
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
    )

    # Alias for use in subdirectory builds
    add_library(matiec::shared ALIAS matiec_shared)
endif()

# Default library alias (prefer shared if available)
if(MATIEC_BUILD_SHARED)
    add_library(matiec::matiec ALIAS matiec_shared)
elseif(MATIEC_BUILD_STATIC)
    add_library(matiec::matiec ALIAS matiec_static)
endif()

# ==============================================================================
# Command-line tools
# ==============================================================================

if(MATIEC_BUILD_TOOLS)
    # Tool sources
    set(TOOL_SOURCES main.cc)
    if(WIN32)
        list(APPEND TOOL_SOURCES util/getopt_compat.c)
    endif()

    # Executable: iec2c (IEC 61131-3 to C)
    add_executable(iec2c ${TOOL_SOURCES})
    target_include_directories(iec2c PRIVATE ${CMAKE_SOURCE_DIR})
    target_link_libraries(iec2c PRIVATE
        stage1_2
        stage3
        stage4_c
        absyntax
        absyntax_utils
    )

    # Executable: iec2iec (IEC 61131-3 normalizer)
    add_executable(iec2iec ${TOOL_SOURCES})
    target_include_directories(iec2iec PRIVATE ${CMAKE_SOURCE_DIR})
    target_link_libraries(iec2iec PRIVATE
        stage1_2
        stage3
        stage4_iec
        absyntax
        absyntax_utils
    )
endif()

# ==============================================================================
# Export targets for external usage (CPM, FetchContent, add_subdirectory)
# ==============================================================================

if(NOT CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    # Being used as a subdirectory - export variables to parent scope
    set(MATIEC_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib PARENT_SCOPE)
    set(MATIEC_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)

    if(MATIEC_BUILD_TOOLS)
        set(MATIEC_IEC2C_EXECUTABLE $<TARGET_FILE:iec2c> PARENT_SCOPE)
        set(MATIEC_IEC2IEC_EXECUTABLE $<TARGET_FILE:iec2iec> PARENT_SCOPE)
    endif()
endif()

# ==============================================================================
# Installation
# ==============================================================================

if(MATIEC_INSTALL)
    # Install executables
    if(MATIEC_BUILD_TOOLS)
        install(TARGETS iec2c iec2iec
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        )
    endif()

    # Install libraries
    set(INSTALL_TARGETS)
    if(MATIEC_BUILD_STATIC)
        list(APPEND INSTALL_TARGETS matiec_static)
    endif()
    if(MATIEC_BUILD_SHARED)
        list(APPEND INSTALL_TARGETS matiec_shared)
    endif()

    if(INSTALL_TARGETS)
        install(TARGETS ${INSTALL_TARGETS}
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        )
    endif()

    # Install headers
    install(DIRECTORY include/matiec
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )

    # Install IEC standard library
    install(DIRECTORY lib/
        DESTINATION ${CMAKE_INSTALL_DATADIR}/matiec/lib
        FILES_MATCHING
        PATTERN "*.txt"
        PATTERN "*.h"
    )
endif()

# ==============================================================================
# Testing
# ==============================================================================

if(MATIEC_BUILD_TESTS)
    enable_testing()

    # Fetch GoogleTest
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    # Include GoogleTest module for gtest_discover_tests
    include(GoogleTest)

    add_subdirectory(tests)
endif()

# ==============================================================================
# Print configuration summary
# ==============================================================================

message(STATUS "")
message(STATUS "matiec ${PROJECT_VERSION} configuration:")
message(STATUS "  C++ standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "  C++ compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "  Bison: ${BISON_EXECUTABLE}")
message(STATUS "  Flex: ${FLEX_EXECUTABLE}")
message(STATUS "  Build shared library: ${MATIEC_BUILD_SHARED}")
message(STATUS "  Build static library: ${MATIEC_BUILD_STATIC}")
message(STATUS "  Build tools: ${MATIEC_BUILD_TOOLS}")
message(STATUS "  Build tests: ${MATIEC_BUILD_TESTS}")
if(GIT_VERSION)
    message(STATUS "  Git version: ${GIT_VERSION}")
endif()
message(STATUS "")
