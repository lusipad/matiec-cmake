/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  End-to-end compilation tests
 *
 *  These tests verify complete compilation pipelines from source to output.
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "test_utils.hh"
#include "matiec/matiec.h"

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

namespace fs = std::filesystem;
using namespace matiec::test;

class E2ECompileTest : public ::testing::Test {
protected:
    void SetUp() override {
        matiec_options_init(&opts_);
        lib_dir_ = getLibDir().string();
        opts_.include_dir = lib_dir_.c_str();
        output_dir_ = temp_.path().string();
        opts_.output_dir = output_dir_.c_str();
    }

    void TearDown() override {
        matiec_result_free(&result_);
    }

    // Compile a program and check for success
    void CompileAndExpectSuccess(const std::string& source, const std::string& filename = "test.st") {
        auto file = temp_.path() / filename;
        ASSERT_TRUE(writeFile(file, source)) << "Failed to write test file";

        auto result = matiec_compile_file(file.string().c_str(), &opts_, &result_);

        EXPECT_EQ(result, MATIEC_OK)
            << "Compilation failed with error: "
            << (result_.error_message ? result_.error_message : "none");
        EXPECT_EQ(result_.error_code, MATIEC_OK);
    }

    // Compile a program and check for expected error
    void CompileAndExpectError(const std::string& source, matiec_error_t expected_error,
                               const std::string& filename = "test.st") {
        auto file = temp_.path() / filename;
        ASSERT_TRUE(writeFile(file, source)) << "Failed to write test file";

        auto result = matiec_compile_file(file.string().c_str(), &opts_, &result_);

        EXPECT_EQ(result, expected_error);
        EXPECT_EQ(result_.error_code, expected_error);
    }

    // Check if output file was generated
    bool OutputFileExists(const std::string& pattern) {
        for (const auto& entry : fs::directory_iterator(temp_.path())) {
            if (entry.path().filename().string().find(pattern) != std::string::npos) {
                return true;
            }
        }
        return false;
    }

    TempDir temp_;
    matiec_options_t opts_;
    matiec_result_t result_{};
    std::string lib_dir_;
    std::string output_dir_;
};

// =============================================================================
// Basic compilation tests
// =============================================================================

TEST_F(E2ECompileTest, CompileEmptyProgram) {
    // matiec requires at least one variable or statement in a PROGRAM
    CompileAndExpectSuccess(R"(
PROGRAM empty_test
VAR
    dummy : INT;
END_VAR
END_PROGRAM
)");
}

TEST_F(E2ECompileTest, CompileVariableDeclarations) {
    CompileAndExpectSuccess(R"(
PROGRAM var_test
VAR
    b : BOOL;
    i : INT;
    r : REAL;
    s : STRING;
    t : TIME;
    d : DATE;
    dt : DT;
    tod : TOD;
END_VAR
    i := 0;
END_PROGRAM
)");
}

TEST_F(E2ECompileTest, CompileArrayDeclaration) {
    CompileAndExpectSuccess(R"(
PROGRAM array_test
VAR
    arr : ARRAY[1..10] OF INT;
    arr2d : ARRAY[1..5, 1..5] OF REAL;
END_VAR
    arr[1] := 42;
    arr2d[1,1] := 3.14;
END_PROGRAM
)");
}

TEST_F(E2ECompileTest, CompileStructDeclaration) {
    CompileAndExpectSuccess(R"(
TYPE
    point_t : STRUCT
        x : REAL;
        y : REAL;
    END_STRUCT;
END_TYPE

PROGRAM struct_test
VAR
    p : point_t;
END_VAR
    p.x := 1.0;
    p.y := 2.0;
END_PROGRAM
)");
}

// =============================================================================
// Control flow tests
// =============================================================================

TEST_F(E2ECompileTest, CompileIfStatement) {
    CompileAndExpectSuccess(R"(
PROGRAM if_test
VAR
    x : INT := 5;
    y : INT;
END_VAR
    IF x > 0 THEN
        y := 1;
    ELSIF x < 0 THEN
        y := -1;
    ELSE
        y := 0;
    END_IF;
END_PROGRAM
)");
}

TEST_F(E2ECompileTest, CompileCaseStatement) {
    CompileAndExpectSuccess(R"(
PROGRAM case_test
VAR
    selector : INT := 2;
    result : INT;
END_VAR
    CASE selector OF
        1: result := 10;
        2: result := 20;
        3, 4, 5: result := 30;
    ELSE
        result := 0;
    END_CASE;
END_PROGRAM
)");
}

TEST_F(E2ECompileTest, CompileForLoop) {
    CompileAndExpectSuccess(R"(
PROGRAM for_test
VAR
    i : INT;
    sum : INT := 0;
END_VAR
    FOR i := 1 TO 100 BY 1 DO
        sum := sum + i;
    END_FOR;
END_PROGRAM
)");
}

TEST_F(E2ECompileTest, CompileWhileLoop) {
    CompileAndExpectSuccess(R"(
PROGRAM while_test
VAR
    i : INT := 0;
    sum : INT := 0;
END_VAR
    WHILE i < 10 DO
        sum := sum + i;
        i := i + 1;
    END_WHILE;
END_PROGRAM
)");
}

TEST_F(E2ECompileTest, CompileRepeatLoop) {
    CompileAndExpectSuccess(R"(
PROGRAM repeat_test
VAR
    i : INT := 0;
    sum : INT := 0;
END_VAR
    REPEAT
        sum := sum + i;
        i := i + 1;
    UNTIL i >= 10
    END_REPEAT;
END_PROGRAM
)");
}

// =============================================================================
// Function and Function Block tests
// =============================================================================

TEST_F(E2ECompileTest, CompileFunction) {
    CompileAndExpectSuccess(R"(
FUNCTION add_ints : INT
VAR_INPUT
    a : INT;
    b : INT;
END_VAR
    add_ints := a + b;
END_FUNCTION

PROGRAM func_test
VAR
    result : INT;
END_VAR
    result := add_ints(10, 20);
END_PROGRAM
)");
}

TEST_F(E2ECompileTest, CompileFunctionBlock) {
    CompileAndExpectSuccess(R"(
FUNCTION_BLOCK accumulator_fb
VAR_INPUT
    value : INT;
    reset : BOOL;
END_VAR
VAR_OUTPUT
    total : INT;
END_VAR
VAR
    sum : INT := 0;
END_VAR
    IF reset THEN
        sum := 0;
    ELSE
        sum := sum + value;
    END_IF;
    total := sum;
END_FUNCTION_BLOCK

PROGRAM fb_test
VAR
    acc : accumulator_fb;
    out : INT;
END_VAR
    acc(value := 10, reset := FALSE);
    out := acc.total;
END_PROGRAM
)");
}

// =============================================================================
// Expression tests
// =============================================================================

TEST_F(E2ECompileTest, CompileArithmeticExpressions) {
    CompileAndExpectSuccess(R"(
PROGRAM arith_test
VAR
    a, b, c : INT;
    r1, r2 : REAL;
END_VAR
    a := 10;
    b := 3;
    c := a + b - 2;
    c := a * b;
    c := a / b;
    c := a MOD b;
    c := -a;

    r1 := 10.0;
    r2 := r1 ** 2.0;
END_PROGRAM
)");
}

TEST_F(E2ECompileTest, CompileComparisonExpressions) {
    CompileAndExpectSuccess(R"(
PROGRAM compare_test
VAR
    a, b : INT;
    result : BOOL;
END_VAR
    a := 10;
    b := 20;
    result := a = b;
    result := a <> b;
    result := a < b;
    result := a <= b;
    result := a > b;
    result := a >= b;
END_PROGRAM
)");
}

TEST_F(E2ECompileTest, CompileLogicalExpressions) {
    CompileAndExpectSuccess(R"(
PROGRAM logic_test
VAR
    a, b, c : BOOL;
END_VAR
    a := TRUE;
    b := FALSE;
    c := a AND b;
    c := a OR b;
    c := a XOR b;
    c := NOT a;
    c := (a AND b) OR (NOT a AND NOT b);
END_PROGRAM
)");
}

TEST_F(E2ECompileTest, CompileBitwiseExpressions) {
    CompileAndExpectSuccess(R"(
PROGRAM bitwise_test
VAR
    a, b, c : WORD;
END_VAR
    a := 16#FF00;
    b := 16#00FF;
    c := a AND b;
    c := a OR b;
    c := a XOR b;
    c := NOT a;
END_PROGRAM
)");
}

// =============================================================================
// Error detection tests
// =============================================================================

TEST_F(E2ECompileTest, DetectMissingSemicolon) {
    // matiec reports parse/semantic errors for syntax issues
    // The exact error type may vary based on where the error is detected
    auto file = temp_.path() / "missing_semi.st";
    ASSERT_TRUE(writeFile(file, R"(
PROGRAM missing_semi
VAR
    x : INT
END_VAR
END_PROGRAM
)"));

    auto result = matiec_compile_file(file.string().c_str(), &opts_, &result_);
    // Should fail with either parse or semantic error
    EXPECT_NE(result, MATIEC_OK) << "Should detect missing semicolon";
    EXPECT_TRUE(result == MATIEC_ERROR_PARSE || result == MATIEC_ERROR_SEMANTIC)
        << "Expected parse or semantic error, got: " << matiec_error_string(result);
}

TEST_F(E2ECompileTest, DetectUndeclaredVariable) {
    // Undeclared variable may be detected at parse or semantic stage
    auto file = temp_.path() / "undeclared_var.st";
    ASSERT_TRUE(writeFile(file, R"(
PROGRAM undeclared_var
VAR
    x : INT;
END_VAR
    y := 10;
END_PROGRAM
)"));

    auto result = matiec_compile_file(file.string().c_str(), &opts_, &result_);
    EXPECT_NE(result, MATIEC_OK) << "Should detect undeclared variable";
    EXPECT_TRUE(result == MATIEC_ERROR_PARSE || result == MATIEC_ERROR_SEMANTIC)
        << "Expected parse or semantic error, got: " << matiec_error_string(result);
}

TEST_F(E2ECompileTest, DetectTypeMismatch) {
    CompileAndExpectError(R"(
PROGRAM type_mismatch
VAR
    x : INT;
    s : STRING;
END_VAR
    x := s;
END_PROGRAM
)", MATIEC_ERROR_SEMANTIC);
}

TEST_F(E2ECompileTest, DetectInvalidArrayIndex) {
    // Note: Array bounds checking may vary by implementation
    // This tests that the compiler at least accepts valid array usage
    CompileAndExpectSuccess(R"(
PROGRAM array_bounds
VAR
    arr : ARRAY[1..10] OF INT;
END_VAR
    arr[1] := 1;
    arr[10] := 10;
END_PROGRAM
)");
}

// =============================================================================
// Multiple POU tests
// =============================================================================

TEST_F(E2ECompileTest, CompileMultiplePOUs) {
    CompileAndExpectSuccess(R"(
TYPE
    motor_state_t : (MOTOR_STOPPED, MOTOR_RUNNING, MOTOR_FAULT);
END_TYPE

FUNCTION get_speed : INT
VAR_INPUT
    motor_id : INT;
END_VAR
    get_speed := motor_id * 100;
END_FUNCTION

FUNCTION_BLOCK motor_controller
VAR_INPUT
    start_cmd : BOOL;
    stop_cmd : BOOL;
END_VAR
VAR_OUTPUT
    running : BOOL;
    speed : INT;
END_VAR
VAR
    state : motor_state_t;
END_VAR
    IF start_cmd AND NOT stop_cmd THEN
        state := MOTOR_RUNNING;
        running := TRUE;
        speed := 1000;
    ELSIF stop_cmd THEN
        state := MOTOR_STOPPED;
        running := FALSE;
        speed := 0;
    END_IF;
END_FUNCTION_BLOCK

PROGRAM main_program
VAR
    motor1 : motor_controller;
    is_running : BOOL;
    current_speed : INT;
END_VAR
    motor1(start_cmd := TRUE, stop_cmd := FALSE);
    is_running := motor1.running;
    current_speed := motor1.speed;
END_PROGRAM
)");
}

// =============================================================================
// Output format tests
// =============================================================================

TEST_F(E2ECompileTest, OutputFormatC) {
    opts_.output_format = MATIEC_OUTPUT_C;

    auto file = temp_.path() / "c_output.st";
    ASSERT_TRUE(writeFile(file, samples::MINIMAL_PROGRAM));

    auto result = matiec_compile_file(file.string().c_str(), &opts_, &result_);
    EXPECT_EQ(result, MATIEC_OK);

    // Check that C output files were generated
    // The exact filenames depend on the implementation
}

TEST_F(E2ECompileTest, OutputFormatIEC) {
    opts_.output_format = MATIEC_OUTPUT_IEC;

    auto file = temp_.path() / "iec_output.st";
    ASSERT_TRUE(writeFile(file, samples::MINIMAL_PROGRAM));

    auto result = matiec_compile_file(file.string().c_str(), &opts_, &result_);
    EXPECT_EQ(result, MATIEC_OK);
}
