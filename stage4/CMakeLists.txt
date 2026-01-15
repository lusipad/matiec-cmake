# stage4 - Code Generation

# Shared base object (stage4.cc is used by both generators)
add_library(stage4_base OBJECT stage4.cc)
target_include_directories(stage4_base PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/absyntax
    ${CMAKE_SOURCE_DIR}
)

# C code generator (iec2c)
add_library(stage4_c STATIC
    $<TARGET_OBJECTS:stage4_base>
    generate_c/generate_c.cc
)
target_include_directories(stage4_c PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/generate_c
    ${CMAKE_SOURCE_DIR}/absyntax
    ${CMAKE_SOURCE_DIR}
)
target_link_libraries(stage4_c PUBLIC absyntax)

# IEC code generator (iec2iec)
add_library(stage4_iec STATIC
    $<TARGET_OBJECTS:stage4_base>
    generate_iec/generate_iec.cc
)
target_include_directories(stage4_iec PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/generate_iec
    ${CMAKE_SOURCE_DIR}/absyntax
    ${CMAKE_SOURCE_DIR}
)
target_link_libraries(stage4_iec PUBLIC absyntax)
