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

// Placeholder test to verify test framework is working
TEST(ErrorHandlingTest, PlaceholderTest) {
    // This test will be replaced with actual error handling tests in P1
    EXPECT_TRUE(true);
}

// =============================================================================
// Future P1 tests will include:
// =============================================================================
//
// TEST(ErrorReporterTest, CollectsMultipleErrors)
// TEST(ErrorReporterTest, PreservesErrorLocation)
// TEST(ErrorReporterTest, CategorizesErrorSeverity)
// TEST(ErrorReporterTest, SupportsErrorCallback)
// TEST(CompilerErrorTest, HasCorrectErrorCategory)
// TEST(ParseErrorTest, IncludesSourceLocation)
// TEST(SemanticErrorTest, IncludesTypeInformation)
//
// =============================================================================

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

TEST(TestUtilsTest, TempDirRAII) {
    std::filesystem::path captured_path;
    {
        matiec::test::TempDir temp;
        captured_path = temp.path();
        EXPECT_TRUE(std::filesystem::exists(captured_path));
    }
    // After TempDir goes out of scope, directory should be removed
    EXPECT_FALSE(std::filesystem::exists(captured_path));
}

TEST(TestUtilsTest, MakeSimpleProgram) {
    auto program = matiec::test::makeSimpleProgram("test_prog", "temp := 42;");
    EXPECT_THAT(program, ::testing::HasSubstr("PROGRAM test_prog"));
    EXPECT_THAT(program, ::testing::HasSubstr("temp := 42;"));
    EXPECT_THAT(program, ::testing::HasSubstr("END_PROGRAM"));
}

TEST(TestUtilsTest, MakeFunctionBlock) {
    auto fb = matiec::test::makeFunctionBlock("test_fb", "out1 := in1 * 2;");
    EXPECT_THAT(fb, ::testing::HasSubstr("FUNCTION_BLOCK test_fb"));
    EXPECT_THAT(fb, ::testing::HasSubstr("VAR_INPUT"));
    EXPECT_THAT(fb, ::testing::HasSubstr("VAR_OUTPUT"));
    EXPECT_THAT(fb, ::testing::HasSubstr("out1 := in1 * 2;"));
    EXPECT_THAT(fb, ::testing::HasSubstr("END_FUNCTION_BLOCK"));
}

TEST(TestUtilsTest, GetProjectRoot) {
    auto root = matiec::test::getProjectRoot();
    // Project root should contain CMakeLists.txt
    EXPECT_TRUE(std::filesystem::exists(root / "CMakeLists.txt"));
}

TEST(TestUtilsTest, GetLibDir) {
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
