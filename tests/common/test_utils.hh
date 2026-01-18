/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Test utilities for matiec test suite
 */

#ifndef MATIEC_TEST_UTILS_HH
#define MATIEC_TEST_UTILS_HH

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <string>
#include <string_view>
#include <optional>
#include <filesystem>
#include <vector>
#include <fstream>

namespace matiec::test {

/**
 * @brief Get the path to the test fixtures directory
 */
[[nodiscard]] std::filesystem::path getFixturesDir();

/**
 * @brief Get the path to the project root directory
 */
[[nodiscard]] std::filesystem::path getProjectRoot();

/**
 * @brief Get the path to the lib/ directory (IEC standard library)
 */
[[nodiscard]] std::filesystem::path getLibDir();

/**
 * @brief Create a temporary directory for test output
 * @return Path to the created temporary directory
 */
[[nodiscard]] std::filesystem::path createTempDir();

/**
 * @brief Remove a temporary directory created by createTempDir
 */
void removeTempDir(const std::filesystem::path& dir);

/**
 * @brief Read entire file contents into a string
 * @param path File path
 * @return File contents, or std::nullopt if file cannot be read
 */
[[nodiscard]] std::optional<std::string> readFile(const std::filesystem::path& path);

/**
 * @brief Write string contents to a file
 * @param path File path
 * @param content Content to write
 * @return true on success
 */
[[nodiscard]] bool writeFile(const std::filesystem::path& path, std::string_view content);

/**
 * @brief RAII wrapper for temporary directories
 */
class TempDir {
public:
    TempDir();
    ~TempDir();

    // Non-copyable, movable
    TempDir(const TempDir&) = delete;
    TempDir& operator=(const TempDir&) = delete;
    TempDir(TempDir&& other) noexcept;
    TempDir& operator=(TempDir&& other) noexcept;

    [[nodiscard]] const std::filesystem::path& path() const noexcept { return path_; }
    [[nodiscard]] operator const std::filesystem::path&() const noexcept { return path_; }

private:
    std::filesystem::path path_;
};

/**
 * @brief Create a simple ST program for testing
 * @param name Program name
 * @param body Program body
 */
[[nodiscard]] std::string makeSimpleProgram(std::string_view name, std::string_view body);

/**
 * @brief Create a simple function block for testing
 * @param name Function block name
 * @param body Function block body
 */
[[nodiscard]] std::string makeFunctionBlock(std::string_view name, std::string_view body);

/**
 * @brief Predefined valid ST programs for testing
 */
namespace samples {

// Minimal valid program
constexpr const char* MINIMAL_PROGRAM = R"(
PROGRAM test_program
VAR
    x : INT;
END_VAR
    x := 1;
END_PROGRAM
)";

// Program with basic arithmetic
constexpr const char* ARITHMETIC_PROGRAM = R"(
PROGRAM arithmetic_test
VAR
    a : INT := 10;
    b : INT := 20;
    result : INT;
END_VAR
    result := a + b * 2;
END_PROGRAM
)";

// Program with conditional
constexpr const char* CONDITIONAL_PROGRAM = R"(
PROGRAM conditional_test
VAR
    x : INT := 5;
    y : INT;
END_VAR
    IF x > 0 THEN
        y := 1;
    ELSE
        y := 0;
    END_IF;
END_PROGRAM
)";

// Program with loop
constexpr const char* LOOP_PROGRAM = R"(
PROGRAM loop_test
VAR
    i : INT;
    sum : INT := 0;
END_VAR
    FOR i := 1 TO 10 DO
        sum := sum + i;
    END_FOR;
END_PROGRAM
)";

// Simple function block
constexpr const char* SIMPLE_FUNCTION_BLOCK = R"(
FUNCTION_BLOCK counter_fb
VAR_INPUT
    reset : BOOL;
END_VAR
VAR_OUTPUT
    count : INT;
END_VAR
VAR
    internal : INT := 0;
END_VAR
    IF reset THEN
        internal := 0;
    ELSE
        internal := internal + 1;
    END_IF;
    count := internal;
END_FUNCTION_BLOCK
)";

// Invalid syntax (for error testing)
constexpr const char* INVALID_SYNTAX = R"(
PROGRAM invalid_test
VAR
    x : INT
END_VAR
    x := 1;
END_PROGRAM
)";

// Type error (for semantic testing)
constexpr const char* TYPE_ERROR = R"(
PROGRAM type_error_test
VAR
    x : INT;
    y : STRING;
END_VAR
    x := y;
END_PROGRAM
)";

} // namespace samples

} // namespace matiec::test

#endif // MATIEC_TEST_UTILS_HH
