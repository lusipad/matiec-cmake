# stage1_2 - Lexical and Syntax Analysis (flex + bison)

# Bison: Generate parser from .yy file
bison_target(IecParser
    ${CMAKE_CURRENT_SOURCE_DIR}/iec_bison.yy
    ${CMAKE_CURRENT_BINARY_DIR}/iec_bison.cc
    DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/iec_bison.hh
)

# Flex: Generate lexer from .ll file
flex_target(IecLexer
    ${CMAKE_CURRENT_SOURCE_DIR}/iec_flex.ll
    ${CMAKE_CURRENT_BINARY_DIR}/iec_flex.cc
)

# Dependency: Lexer needs parser header
add_flex_bison_dependency(IecLexer IecParser)

# Library
add_library(stage1_2 STATIC
    ${BISON_IecParser_OUTPUTS}
    ${FLEX_IecLexer_OUTPUTS}
    stage1_2.cc
    create_enumtype_conversion_functions.cc
)

# Compile definitions
target_compile_definitions(stage1_2 PRIVATE
    DEFAULT_LIBDIR="lib"
    YY_BUF_SIZE=65536
)

# GCC requires -fpermissive for this code
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(stage1_2 PRIVATE -fpermissive)
endif()

# Include directories
target_include_directories(stage1_2
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
)

# Dependencies
target_link_libraries(stage1_2 PUBLIC absyntax)
