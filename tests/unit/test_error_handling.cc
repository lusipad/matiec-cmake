/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Unit tests for error handling (placeholder for P1 implementation)
 *
 *  This file will be expanded in Phase P1 when the error handling
 *  infrastructure is modernized.
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "test_utils.hh"
#include "matiec/error.hpp"

TEST(ErrorReporterTest, CollectsMultipleErrors) {
    matiec::ErrorReporter reporter;
    reporter.reportParseError("syntax error");
    reporter.reportSemanticError("semantic error");

    EXPECT_EQ(reporter.errorCount(), 2);
    ASSERT_EQ(reporter.errors().size(), 2u);
    EXPECT_EQ(reporter.errors()[0].category(), matiec::ErrorCategory::Syntax);
    EXPECT_EQ(reporter.errors()[1].category(), matiec::ErrorCategory::Semantic);
}

TEST(ErrorReporterTest, PreservesErrorLocation) {
    matiec::ErrorReporter reporter;
    matiec::SourceLocation loc;
    loc.filename = "test.st";
    loc.line = 12;
    loc.column = 3;

    reporter.reportParseError("unexpected token", loc);

    ASSERT_EQ(reporter.errors().size(), 1u);
    ASSERT_TRUE(reporter.errors()[0].location().has_value());
    EXPECT_EQ(reporter.errors()[0].location()->filename, "test.st");
    EXPECT_EQ(reporter.errors()[0].location()->line, 12);
    EXPECT_EQ(reporter.errors()[0].location()->column, 3);
}

TEST(ErrorReporterTest, CategorizesErrorSeverity) {
    matiec::ErrorReporter reporter;
    reporter.reportWarning("deprecated syntax");
    reporter.reportParseError("missing ';'");

    EXPECT_EQ(reporter.warningCount(), 1);
    EXPECT_EQ(reporter.errorCount(), 1);
    ASSERT_EQ(reporter.errors().size(), 2u);
    EXPECT_EQ(reporter.errors()[0].severity(), matiec::ErrorSeverity::Warning);
    EXPECT_EQ(reporter.errors()[1].severity(), matiec::ErrorSeverity::Error);
}

TEST(ErrorReporterTest, SupportsErrorCallback) {
    matiec::ErrorReporter reporter;
    int calls = 0;

    reporter.setCallback([&](const matiec::CompilerError& err) {
        ++calls;
        EXPECT_EQ(err.message(), "callback test");
    });

    reporter.reportParseError("callback test");
    EXPECT_EQ(calls, 1);
}

TEST(ErrorReporterTest, DetailedErrorsPreserveTypeDetails) {
    matiec::ErrorReporter reporter;
    matiec::SourceLocation loc;
    loc.filename = "test.st";
    loc.line = 4;
    loc.column = 2;

    reporter.reportTypeError("type mismatch", loc, "INT", "BOOL");

    ASSERT_EQ(reporter.errors().size(), 1u);

    const auto& detailed = reporter.detailedErrors();
    ASSERT_EQ(detailed.size(), 1u);
    ASSERT_NE(detailed[0], nullptr);
    EXPECT_EQ(detailed[0]->category(), matiec::ErrorCategory::Type);

    const std::string formatted = detailed[0]->format();
    EXPECT_THAT(formatted, ::testing::HasSubstr("type mismatch"));
    EXPECT_THAT(formatted, ::testing::HasSubstr("expected: INT"));
    EXPECT_THAT(formatted, ::testing::HasSubstr("got: BOOL"));
}

TEST(CompilerErrorTest, HasCorrectErrorCategory) {
    matiec::CompilerError err(matiec::ErrorSeverity::Error,
                              matiec::ErrorCategory::Semantic,
                              "undefined variable");
    EXPECT_EQ(err.category(), matiec::ErrorCategory::Semantic);
    EXPECT_TRUE(err.isError());
    EXPECT_FALSE(err.isFatal());
}

TEST(ParseErrorTest, IncludesSourceLocationInFormat) {
    matiec::ParseError err("parse failed", {"file.st", 10, 2});
    const std::string formatted = err.format();
    EXPECT_THAT(formatted, ::testing::HasSubstr("file.st:10:2"));
    EXPECT_THAT(formatted, ::testing::HasSubstr("error"));
    EXPECT_THAT(formatted, ::testing::HasSubstr("parse failed"));
}

namespace {

// Test that the test utilities work correctly
class TestUtilsTest : public ::testing::Test {
protected:
    void SetUp() override {
        temp_dir_ = matiec::test::createTempDir();
    }

    void TearDown() override {
        matiec::test::removeTempDir(temp_dir_);
    }

    std::filesystem::path temp_dir_;
};

TEST_F(TestUtilsTest, CreateAndRemoveTempDir) {
    EXPECT_TRUE(std::filesystem::exists(temp_dir_));
    EXPECT_TRUE(std::filesystem::is_directory(temp_dir_));
}

TEST_F(TestUtilsTest, WriteAndReadFile) {
    auto file_path = temp_dir_ / "test.txt";
    const std::string content = "Hello, World!";

    EXPECT_TRUE(matiec::test::writeFile(file_path, content));
    EXPECT_TRUE(std::filesystem::exists(file_path));

    auto read_content = matiec::test::readFile(file_path);
    ASSERT_TRUE(read_content.has_value());
    EXPECT_EQ(*read_content, content);
}

TEST_F(TestUtilsTest, ReadNonexistentFile) {
    auto result = matiec::test::readFile(temp_dir_ / "nonexistent.txt");
    EXPECT_FALSE(result.has_value());
}

// =============================================================================
// Standalone tests (no fixture needed)
// =============================================================================

TEST(TestUtilsStandaloneTest, TempDirRAII) {
    std::filesystem::path captured_path;
    {
        matiec::test::TempDir temp;
        captured_path = temp.path();
        EXPECT_TRUE(std::filesystem::exists(captured_path));
    }
    // After TempDir goes out of scope, directory should be removed
    EXPECT_FALSE(std::filesystem::exists(captured_path));
}

TEST(TestUtilsStandaloneTest, MakeSimpleProgram) {
    auto program = matiec::test::makeSimpleProgram("test_prog", "temp := 42;");
    EXPECT_THAT(program, ::testing::HasSubstr("PROGRAM test_prog"));
    EXPECT_THAT(program, ::testing::HasSubstr("temp := 42;"));
    EXPECT_THAT(program, ::testing::HasSubstr("END_PROGRAM"));
}

TEST(TestUtilsStandaloneTest, MakeFunctionBlock) {
    auto fb = matiec::test::makeFunctionBlock("test_fb", "out1 := in1 * 2;");
    EXPECT_THAT(fb, ::testing::HasSubstr("FUNCTION_BLOCK test_fb"));
    EXPECT_THAT(fb, ::testing::HasSubstr("VAR_INPUT"));
    EXPECT_THAT(fb, ::testing::HasSubstr("VAR_OUTPUT"));
    EXPECT_THAT(fb, ::testing::HasSubstr("out1 := in1 * 2;"));
    EXPECT_THAT(fb, ::testing::HasSubstr("END_FUNCTION_BLOCK"));
}

TEST(TestUtilsStandaloneTest, GetProjectRoot) {
    auto root = matiec::test::getProjectRoot();
    // Project root should contain CMakeLists.txt
    EXPECT_TRUE(std::filesystem::exists(root / "CMakeLists.txt"));
}

TEST(TestUtilsStandaloneTest, GetLibDir) {
    auto lib_dir = matiec::test::getLibDir();
    // lib directory should exist and contain IEC standard library files
    if (std::filesystem::exists(lib_dir)) {
        // Check for presence of standard library files
        bool has_iec_files = false;
        for (const auto& entry : std::filesystem::directory_iterator(lib_dir)) {
            if (entry.path().extension() == ".txt" || entry.path().extension() == ".h") {
                has_iec_files = true;
                break;
            }
        }
        EXPECT_TRUE(has_iec_files) << "lib/ directory should contain .txt or .h files";
    }
}

} // namespace
