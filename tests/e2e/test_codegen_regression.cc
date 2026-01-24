/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Code generation regression tests.
 */

#include <gtest/gtest.h>

#include "test_utils.hh"
#include "matiec/matiec.h"

#include <filesystem>
#include <string>

namespace fs = std::filesystem;
using namespace matiec::test;

class CodegenRegressionTest : public ::testing::Test {
protected:
    void SetUp() override {
        matiec_options_init(&opts_);
        lib_dir_ = getLibDir().string();
        opts_.include_dir = lib_dir_.c_str();
        output_dir_ = temp_.path().string();
        opts_.output_dir = output_dir_.c_str();
        fixture_path_ = getFixturesDir() / "simple_program.st";
    }

    void TearDown() override {
        matiec_result_free(&result_);
    }

    void CompileFixture(matiec_output_format_t format) {
        ASSERT_TRUE(fs::exists(fixture_path_)) << "Missing fixture: " << fixture_path_.string();
        opts_.output_format = format;
        auto status = matiec_compile_file(fixture_path_.string().c_str(), &opts_, &result_);
        ASSERT_EQ(status, MATIEC_OK)
            << "Compilation failed: "
            << (result_.error_message ? result_.error_message : "none");
    }

    std::string ReadRequiredFile(const fs::path& path) {
        auto content = readFile(path);
        EXPECT_TRUE(content.has_value()) << "Failed to read: " << path.string();
        return content.value_or(std::string());
    }

    TempDir temp_;
    matiec_options_t opts_{};
    matiec_result_t result_{};
    std::string lib_dir_;
    std::string output_dir_;
    fs::path fixture_path_;
};

TEST_F(CodegenRegressionTest, GeneratesStableCOutput) {
    CompileFixture(MATIEC_OUTPUT_C);

    const fs::path expected_dir = getFixturesDir() / "codegen";
    const std::string expected_pous_c = ReadRequiredFile(expected_dir / "POUS.c");
    const std::string expected_pous_h = ReadRequiredFile(expected_dir / "POUS.h");

    const std::string actual_pous_c = ReadRequiredFile(temp_.path() / "POUS.c");
    const std::string actual_pous_h = ReadRequiredFile(temp_.path() / "POUS.h");

    EXPECT_EQ(actual_pous_c, expected_pous_c);
    EXPECT_EQ(actual_pous_h, expected_pous_h);
}

TEST_F(CodegenRegressionTest, GeneratesStableIecOutput) {
    CompileFixture(MATIEC_OUTPUT_IEC);

    const fs::path expected_dir = getFixturesDir() / "codegen";
    const std::string expected_iec = ReadRequiredFile(expected_dir / "simple_program.iec");

    const std::string actual_iec = ReadRequiredFile(temp_.path() / "simple_program.iec");

    EXPECT_EQ(actual_iec, expected_iec);
}
