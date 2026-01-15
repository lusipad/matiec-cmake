# absyntax - Abstract Syntax Tree definitions
add_library(absyntax STATIC
    absyntax.cc
    visitor.cc
)

target_include_directories(absyntax PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
)
