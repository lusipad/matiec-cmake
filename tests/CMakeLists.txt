# ==============================================================================
# matiec Test Suite
# ==============================================================================

# Common test utilities library
add_library(matiec_test_utils STATIC
    common/test_utils.cc
)
target_include_directories(matiec_test_utils PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}
)
target_link_libraries(matiec_test_utils PUBLIC
    GTest::gtest
    GTest::gmock
)

# ==============================================================================
# Unit Tests
# ==============================================================================

# Library API tests
add_executable(test_matiec_api
    unit/test_matiec_api.cc
)
target_include_directories(test_matiec_api PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}
)
target_link_libraries(test_matiec_api PRIVATE
    matiec_test_utils
    matiec_static
    GTest::gtest_main
)
gtest_discover_tests(test_matiec_api
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    PROPERTIES
        LABELS "unit"
)

# Error handling tests (will be expanded in P1)
add_executable(test_error_handling
    unit/test_error_handling.cc
)
target_include_directories(test_error_handling PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}
)
target_link_libraries(test_error_handling PRIVATE
    matiec_test_utils
    matiec_static
    GTest::gtest_main
)
gtest_discover_tests(test_error_handling
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    PROPERTIES
        LABELS "unit"
)

# String utilities / legacy string boundary tests
add_executable(test_string_utils
    unit/test_string_utils.cc
)
target_include_directories(test_string_utils PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}
)
target_link_libraries(test_string_utils PRIVATE
    matiec_test_utils
    matiec_static
    GTest::gtest_main
)
gtest_discover_tests(test_string_utils
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    PROPERTIES
        LABELS "unit"
)

# Visitor result tests
add_executable(test_visitor_result
    unit/test_visitor_result.cc
)
target_include_directories(test_visitor_result PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}
)
target_link_libraries(test_visitor_result PRIVATE
    matiec_test_utils
    matiec_static
    GTest::gtest_main
)
gtest_discover_tests(test_visitor_result
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    PROPERTIES
        LABELS "unit"
)

# CompilationUnit tests
add_executable(test_compilation_unit
    unit/test_compilation_unit.cc
)
target_include_directories(test_compilation_unit PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}
)
target_link_libraries(test_compilation_unit PRIVATE
    matiec_test_utils
    matiec_static
    GTest::gtest_main
)
gtest_discover_tests(test_compilation_unit
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    PROPERTIES
        LABELS "unit"
)

# Modern AST scaffolding tests
add_executable(test_ast_modern
    unit/test_ast_modern.cc
)
target_include_directories(test_ast_modern PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}
)
target_link_libraries(test_ast_modern PRIVATE
    matiec_test_utils
    matiec_static
    GTest::gtest_main
)
gtest_discover_tests(test_ast_modern
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    PROPERTIES
        LABELS "unit"
)

# Type registry tests
add_executable(test_type_registry
    unit/test_type_registry.cc
)
target_include_directories(test_type_registry PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}
)
target_link_libraries(test_type_registry PRIVATE
    matiec_test_utils
    matiec_static
    GTest::gtest_main
)
gtest_discover_tests(test_type_registry
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    PROPERTIES
        LABELS "unit"
)

# Type inferrer tests
add_executable(test_type_inferrer
    unit/test_type_inferrer.cc
)
target_include_directories(test_type_inferrer PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}
)
target_link_libraries(test_type_inferrer PRIVATE
    matiec_test_utils
    matiec_static
    GTest::gtest_main
)
gtest_discover_tests(test_type_inferrer
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    PROPERTIES
        LABELS "unit"
)

# Semantic candidate narrowing tests
add_executable(test_semantic_candidates
    unit/test_semantic_candidates.cc
)
target_include_directories(test_semantic_candidates PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}
)
target_link_libraries(test_semantic_candidates PRIVATE
    matiec_test_utils
    matiec_static
    GTest::gtest_main
)
gtest_discover_tests(test_semantic_candidates
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    PROPERTIES
        LABELS "unit"
)

# Constant folding annotation tests
add_executable(test_constant_folding
    unit/test_constant_folding.cc
)
target_include_directories(test_constant_folding PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}
)
target_link_libraries(test_constant_folding PRIVATE
    matiec_test_utils
    matiec_static
    GTest::gtest_main
)
gtest_discover_tests(test_constant_folding
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    PROPERTIES
        LABELS "unit"
)

# Code emitter tests
add_executable(test_codegen_emitter
    unit/test_codegen_emitter.cc
)
target_include_directories(test_codegen_emitter PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}
)
target_link_libraries(test_codegen_emitter PRIVATE
    matiec_test_utils
    matiec_static
    GTest::gtest_main
)
gtest_discover_tests(test_codegen_emitter
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    PROPERTIES
        LABELS "unit"
)

# ==============================================================================
# End-to-End Tests
# ==============================================================================

# E2E compilation tests
add_executable(test_e2e_compile
    e2e/test_e2e_compile.cc
)
target_include_directories(test_e2e_compile PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}
)
target_link_libraries(test_e2e_compile PRIVATE
    matiec_test_utils
    matiec_static
    GTest::gtest_main
)
gtest_discover_tests(test_e2e_compile
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    PROPERTIES
        LABELS "e2e"
        TIMEOUT 60
)

# Syntax validation tests (using existing tests/syntax/ files)
add_executable(test_syntax_validation
    e2e/test_syntax_validation.cc
)
target_include_directories(test_syntax_validation PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}
)
target_link_libraries(test_syntax_validation PRIVATE
    matiec_test_utils
    matiec_static
    GTest::gtest_main
)
gtest_discover_tests(test_syntax_validation
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    PROPERTIES
        LABELS "e2e"
        TIMEOUT 60
)

# Codegen regression tests
add_executable(test_codegen_regression
    e2e/test_codegen_regression.cc
)
target_include_directories(test_codegen_regression PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}
)
target_link_libraries(test_codegen_regression PRIVATE
    matiec_test_utils
    matiec_static
    GTest::gtest_main
)
gtest_discover_tests(test_codegen_regression
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    PROPERTIES
        LABELS "e2e"
        TIMEOUT 60
)

# ==============================================================================
# Test data
# ==============================================================================

# Copy test fixture files to build directory
file(COPY
    ${CMAKE_CURRENT_SOURCE_DIR}/fixtures/
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/fixtures/
)

# ==============================================================================
# Custom test targets
# ==============================================================================

add_custom_target(test_unit
    COMMAND ${CMAKE_CTEST_COMMAND} -L unit --output-on-failure
    DEPENDS test_matiec_api test_error_handling test_string_utils
            test_visitor_result test_compilation_unit
            test_ast_modern
            test_type_registry test_type_inferrer
            test_semantic_candidates test_constant_folding
            test_codegen_emitter
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running unit tests..."
)

add_custom_target(test_e2e
    COMMAND ${CMAKE_CTEST_COMMAND} -L e2e --output-on-failure
    DEPENDS test_e2e_compile test_syntax_validation
            test_codegen_regression
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running end-to-end tests..."
)
