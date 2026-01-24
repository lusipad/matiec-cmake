/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Unit tests for matiec C API
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "test_utils.hh"
#include "matiec/matiec.h"

#include <algorithm>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;
using namespace matiec::test;

class MatiecApiTest : public ::testing::Test {
protected:
    void SetUp() override {
        matiec_options_init(&opts_);
        lib_dir_str_ = getLibDir().string();
        opts_.include_dir = lib_dir_str_.c_str();
    }

    void TearDown() override {
        matiec_result_free(&result_);
    }

    matiec_options_t opts_;
    matiec_result_t result_{};
    std::string lib_dir_str_;
};

// =============================================================================
// Version and utility tests
// =============================================================================

TEST(MatiecUtilsTest, VersionStringIsValid) {
    const char* version = matiec_version();
    ASSERT_NE(version, nullptr);
    // Check version string is not empty and contains version-like pattern
    std::string v(version);
    EXPECT_FALSE(v.empty());
    // Check it contains at least two dots (x.y.z format)
    size_t dot_count = std::count(v.begin(), v.end(), '.');
    EXPECT_GE(dot_count, 2u) << "Version string should be in x.y.z format, got: " << v;
}

TEST(MatiecUtilsTest, ErrorStringReturnsValidStrings) {
    EXPECT_STREQ(matiec_error_string(MATIEC_OK), "Success");
    EXPECT_STREQ(matiec_error_string(MATIEC_ERROR_INVALID_ARG), "Invalid argument");
    EXPECT_STREQ(matiec_error_string(MATIEC_ERROR_FILE_NOT_FOUND), "File not found");
    EXPECT_STREQ(matiec_error_string(MATIEC_ERROR_PARSE), "Parse error (lexical or syntax)");
    EXPECT_STREQ(matiec_error_string(MATIEC_ERROR_SEMANTIC), "Semantic error");
    EXPECT_STREQ(matiec_error_string(MATIEC_ERROR_CODEGEN), "Code generation error");
    EXPECT_STREQ(matiec_error_string(MATIEC_ERROR_IO), "I/O error");
    EXPECT_STREQ(matiec_error_string(MATIEC_ERROR_INTERNAL), "Internal compiler error");
}

TEST(MatiecUtilsTest, SupportedExtensions) {
    // Supported extensions
    EXPECT_TRUE(matiec_is_supported_extension("st"));
    EXPECT_TRUE(matiec_is_supported_extension(".st"));
    EXPECT_TRUE(matiec_is_supported_extension("ST"));
    EXPECT_TRUE(matiec_is_supported_extension(".ST"));
    EXPECT_TRUE(matiec_is_supported_extension("il"));
    EXPECT_TRUE(matiec_is_supported_extension("sfc"));
    EXPECT_TRUE(matiec_is_supported_extension("iec"));

    // Unsupported extensions
    EXPECT_FALSE(matiec_is_supported_extension("cpp"));
    EXPECT_FALSE(matiec_is_supported_extension("txt"));
    EXPECT_FALSE(matiec_is_supported_extension(""));
    EXPECT_FALSE(matiec_is_supported_extension(nullptr));
}

// =============================================================================
// Options initialization tests
// =============================================================================

TEST(MatiecOptionsTest, InitSetsDefaults) {
    matiec_options_t opts;
    matiec_options_init(&opts);

    EXPECT_EQ(opts.include_dir, nullptr);
    EXPECT_EQ(opts.output_dir, nullptr);
    EXPECT_EQ(opts.output_format, MATIEC_OUTPUT_C);
    EXPECT_FALSE(opts.allow_forward_refs);
    EXPECT_FALSE(opts.relaxed_datatype_model);
    EXPECT_FALSE(opts.safe_extensions);
    EXPECT_FALSE(opts.nested_comments);
    EXPECT_FALSE(opts.ref_extensions);
    EXPECT_FALSE(opts.ref_nonstandard);
    EXPECT_FALSE(opts.nonliteral_array_size);
    EXPECT_FALSE(opts.allow_void_functions);
    EXPECT_FALSE(opts.allow_missing_var_in);
    EXPECT_FALSE(opts.disable_implicit_en_eno);
    EXPECT_FALSE(opts.conversion_functions);
    EXPECT_FALSE(opts.full_token_location);
}

TEST(MatiecOptionsTest, InitHandlesNullPointer) {
    // Should not crash
    matiec_options_init(nullptr);
}

// =============================================================================
// Input validation tests
// =============================================================================

TEST_F(MatiecApiTest, CompileFileRejectsNullResult) {
    TempDir temp;
    auto file = temp.path() / "test.st";
    ASSERT_TRUE(writeFile(file, samples::MINIMAL_PROGRAM));

    auto result = matiec_compile_file(file.string().c_str(), &opts_, nullptr);
    EXPECT_EQ(result, MATIEC_ERROR_INVALID_ARG);
}

TEST_F(MatiecApiTest, CompileFileRejectsNullInputFile) {
    auto result = matiec_compile_file(nullptr, &opts_, &result_);
    EXPECT_EQ(result, MATIEC_ERROR_INVALID_ARG);
    EXPECT_EQ(result_.error_code, MATIEC_ERROR_INVALID_ARG);
    EXPECT_NE(result_.error_message, nullptr);
}

TEST_F(MatiecApiTest, CompileFileRejectsNonexistentFile) {
    auto result = matiec_compile_file("/nonexistent/path/file.st", &opts_, &result_);
    EXPECT_EQ(result, MATIEC_ERROR_FILE_NOT_FOUND);
    EXPECT_EQ(result_.error_code, MATIEC_ERROR_FILE_NOT_FOUND);
}

TEST_F(MatiecApiTest, CompileStringRejectsNullResult) {
    auto result = matiec_compile_string(samples::MINIMAL_PROGRAM, 0, "test.st", &opts_, nullptr);
    EXPECT_EQ(result, MATIEC_ERROR_INVALID_ARG);
}

TEST_F(MatiecApiTest, CompileStringRejectsNullSource) {
    auto result = matiec_compile_string(nullptr, 0, "test.st", &opts_, &result_);
    EXPECT_EQ(result, MATIEC_ERROR_INVALID_ARG);
    EXPECT_EQ(result_.error_code, MATIEC_ERROR_INVALID_ARG);
}

TEST_F(MatiecApiTest, CompileFileReportsSemanticErrorDetails) {
    TempDir temp;
    auto file = temp.path() / "type_error.st";
    ASSERT_TRUE(writeFile(file, samples::TYPE_ERROR));

    std::string file_str = file.string();
    auto result = matiec_compile_file(file_str.c_str(), &opts_, &result_);

    EXPECT_EQ(result, MATIEC_ERROR_SEMANTIC);
    EXPECT_EQ(result_.error_code, MATIEC_ERROR_SEMANTIC);
    ASSERT_NE(result_.error_message, nullptr);
    EXPECT_THAT(result_.error_message, ::testing::HasSubstr("error"));
    EXPECT_GT(result_.error_line, 0);
    ASSERT_NE(result_.error_file, nullptr);
    EXPECT_THAT(result_.error_file, ::testing::HasSubstr("type_error.st"));
}

// =============================================================================
// Compilation tests
// =============================================================================

TEST_F(MatiecApiTest, CompileMinimalProgram) {
    TempDir temp;
    auto file = temp.path() / "test.st";
    ASSERT_TRUE(writeFile(file, samples::MINIMAL_PROGRAM));
    std::string output_dir_str = temp.path().string();
    opts_.output_dir = output_dir_str.c_str();

    std::string file_str = file.string();
    auto result = matiec_compile_file(file_str.c_str(), &opts_, &result_);

    EXPECT_EQ(result, MATIEC_OK) << "Error: " << (result_.error_message ? result_.error_message : "none");
    EXPECT_EQ(result_.error_code, MATIEC_OK);
}

TEST_F(MatiecApiTest, CompileArithmeticProgram) {
    TempDir temp;
    auto file = temp.path() / "arithmetic.st";
    ASSERT_TRUE(writeFile(file, samples::ARITHMETIC_PROGRAM));
    std::string output_dir_str = temp.path().string();
    opts_.output_dir = output_dir_str.c_str();

    std::string file_str = file.string();
    auto result = matiec_compile_file(file_str.c_str(), &opts_, &result_);

    EXPECT_EQ(result, MATIEC_OK) << "Error: " << (result_.error_message ? result_.error_message : "none");
}

TEST_F(MatiecApiTest, CompileConditionalProgram) {
    TempDir temp;
    auto file = temp.path() / "conditional.st";
    ASSERT_TRUE(writeFile(file, samples::CONDITIONAL_PROGRAM));
    std::string output_dir_str = temp.path().string();
    opts_.output_dir = output_dir_str.c_str();

    std::string file_str = file.string();
    auto result = matiec_compile_file(file_str.c_str(), &opts_, &result_);

    EXPECT_EQ(result, MATIEC_OK) << "Error: " << (result_.error_message ? result_.error_message : "none");
}

TEST_F(MatiecApiTest, CompileLoopProgram) {
    TempDir temp;
    auto file = temp.path() / "loop.st";
    ASSERT_TRUE(writeFile(file, samples::LOOP_PROGRAM));
    std::string output_dir_str = temp.path().string();
    opts_.output_dir = output_dir_str.c_str();

    std::string file_str = file.string();
    auto result = matiec_compile_file(file_str.c_str(), &opts_, &result_);

    EXPECT_EQ(result, MATIEC_OK) << "Error: " << (result_.error_message ? result_.error_message : "none");
}

TEST_F(MatiecApiTest, CompileFunctionBlock) {
    TempDir temp;
    auto file = temp.path() / "fb.st";
    ASSERT_TRUE(writeFile(file, samples::SIMPLE_FUNCTION_BLOCK));
    std::string output_dir_str = temp.path().string();
    opts_.output_dir = output_dir_str.c_str();

    std::string file_str = file.string();
    auto result = matiec_compile_file(file_str.c_str(), &opts_, &result_);

    EXPECT_EQ(result, MATIEC_OK) << "Error: " << (result_.error_message ? result_.error_message : "none");
}

TEST_F(MatiecApiTest, CompileFromString) {
    TempDir temp;
    std::string output_dir_str = temp.path().string();
    opts_.output_dir = output_dir_str.c_str();

    auto result = matiec_compile_string(
        samples::MINIMAL_PROGRAM,
        0,  // auto-detect length
        "test.st",
        &opts_,
        &result_
    );

    EXPECT_EQ(result, MATIEC_OK) << "Error: " << (result_.error_message ? result_.error_message : "none");
}

// =============================================================================
// Error detection tests
// =============================================================================

TEST_F(MatiecApiTest, DetectsSyntaxError) {
    TempDir temp;
    auto file = temp.path() / "invalid.st";
    ASSERT_TRUE(writeFile(file, samples::INVALID_SYNTAX));
    std::string output_dir_str = temp.path().string();
    opts_.output_dir = output_dir_str.c_str();

    std::string file_str = file.string();
    auto result = matiec_compile_file(file_str.c_str(), &opts_, &result_);

    EXPECT_EQ(result, MATIEC_ERROR_PARSE);
    EXPECT_EQ(result_.error_code, MATIEC_ERROR_PARSE);
    EXPECT_NE(result_.error_message, nullptr);
    EXPECT_NE(result_.error_file, nullptr);
    EXPECT_GT(result_.error_line, 0);
}

TEST_F(MatiecApiTest, DetectsTypeError) {
    TempDir temp;
    auto file = temp.path() / "type_error.st";
    ASSERT_TRUE(writeFile(file, samples::TYPE_ERROR));
    std::string output_dir_str = temp.path().string();
    opts_.output_dir = output_dir_str.c_str();

    std::string file_str = file.string();
    auto result = matiec_compile_file(file_str.c_str(), &opts_, &result_);

    EXPECT_EQ(result, MATIEC_ERROR_SEMANTIC);
    EXPECT_EQ(result_.error_code, MATIEC_ERROR_SEMANTIC);
    EXPECT_NE(result_.error_message, nullptr);
    EXPECT_NE(result_.error_file, nullptr);
    EXPECT_GT(result_.error_line, 0);
}

TEST_F(MatiecApiTest, SupportsMultipleCompilesInOneProcess) {
    TempDir temp;

    const auto out1 = (temp.path() / "out1").string();
    const auto out2 = (temp.path() / "out2").string();
    const auto out3 = (temp.path() / "out3").string();
    fs::create_directories(out1);
    fs::create_directories(out2);
    fs::create_directories(out3);

    // 1) Parse error
    {
        auto file = temp.path() / "bad.st";
        ASSERT_TRUE(writeFile(file, samples::INVALID_SYNTAX));

        matiec_options_t opts = opts_;
        opts.output_dir = out1.c_str();

        matiec_result_t res{};
        auto err = matiec_compile_file(file.string().c_str(), &opts, &res);
        EXPECT_EQ(err, MATIEC_ERROR_PARSE);
        matiec_result_free(&res);
    }

    // 2) Successful compile
    {
        auto file = temp.path() / "good.st";
        ASSERT_TRUE(writeFile(file, samples::MINIMAL_PROGRAM));

        matiec_options_t opts = opts_;
        opts.output_dir = out2.c_str();

        matiec_result_t res{};
        auto err = matiec_compile_file(file.string().c_str(), &opts, &res);
        EXPECT_EQ(err, MATIEC_OK) << "Error: " << (res.error_message ? res.error_message : "none");
        matiec_result_free(&res);
    }

    // 3) Successful compile with pre-parsing enabled (forward refs)
    {
        auto file = temp.path() / "preparse.st";
        ASSERT_TRUE(writeFile(file, samples::MINIMAL_PROGRAM));

        matiec_options_t opts = opts_;
        opts.allow_forward_refs = true;
        opts.output_dir = out3.c_str();

        matiec_result_t res{};
        auto err = matiec_compile_file(file.string().c_str(), &opts, &res);
        EXPECT_EQ(err, MATIEC_OK) << "Error: " << (res.error_message ? res.error_message : "none");
        matiec_result_free(&res);
    }
}

// =============================================================================
// Result cleanup tests
// =============================================================================

TEST(MatiecResultTest, FreeHandlesNullPointer) {
    // Should not crash
    matiec_result_free(nullptr);
}

TEST(MatiecResultTest, FreeHandlesZeroedResult) {
    matiec_result_t result{};
    // Should not crash
    matiec_result_free(&result);
}

// =============================================================================
// Options behavior tests
// =============================================================================

TEST_F(MatiecApiTest, AcceptsNullOptions) {
    TempDir temp;
    auto file = temp.path() / "test.st";
    ASSERT_TRUE(writeFile(file, samples::MINIMAL_PROGRAM));

    // Compile with NULL options (should use defaults), but run from a temp cwd
    // so we don't accidentally emit generated C files into the repo root.
    const auto old_cwd = fs::current_path();
    fs::current_path(temp.path());

    std::string file_str = file.string();
    auto result = matiec_compile_file(file_str.c_str(), nullptr, &result_);

    fs::current_path(old_cwd);

    // Should not crash; most likely fails due to missing include dir from this cwd.
    EXPECT_EQ(result, MATIEC_ERROR_IO);
}
