# absyntax - Abstract Syntax Tree definitions
add_library(absyntax STATIC
    absyntax.cc
    ast_memory.cc
    visitor.cc
    generated/absyntax_nodes.gen.cc
    generated/visitor_methods.gen.cc
)

target_include_directories(absyntax PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
)
