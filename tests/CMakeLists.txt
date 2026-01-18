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
    DEPENDS test_matiec_api test_error_handling
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running unit tests..."
)

add_custom_target(test_e2e
    COMMAND ${CMAKE_CTEST_COMMAND} -L e2e --output-on-failure
    DEPENDS test_e2e_compile test_syntax_validation
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running end-to-end tests..."
)
