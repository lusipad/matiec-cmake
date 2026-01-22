/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Test utilities implementation
 */

#include "test_utils.hh"

#include <cstdlib>
#include <random>
#include <sstream>
#include <chrono>

namespace matiec::test {

namespace fs = std::filesystem;

std::filesystem::path getFixturesDir() {
    // Try relative path from build directory first
    fs::path fixtures = fs::current_path() / "tests" / "fixtures";
    if (fs::exists(fixtures)) {
        return fixtures;
    }

    // Try from project root
    fixtures = getProjectRoot() / "tests" / "fixtures";
    if (fs::exists(fixtures)) {
        return fixtures;
    }

    // Return expected path even if it doesn't exist (for error messages)
    return fs::current_path() / "tests" / "fixtures";
}

std::filesystem::path getProjectRoot() {
    // Look for CMakeLists.txt to find project root
    fs::path current = fs::current_path();

    // First, check if current directory is already project root
    if (fs::exists(current / "CMakeLists.txt") &&
        fs::exists(current / "lib") &&
        fs::exists(current / "lib" / "iec_std_lib.txt")) {
        return current;
    }

    // Walk up the directory tree
    fs::path search = current;
    while (!search.empty() && search != search.root_path()) {
        if (fs::exists(search / "CMakeLists.txt") &&
            fs::exists(search / "lib") &&
            fs::exists(search / "lib" / "iec_std_lib.txt")) {
            return search;
        }
        search = search.parent_path();
    }

    // Try checking if we're in a build subdirectory
    if (fs::exists(current.parent_path() / "CMakeLists.txt") &&
        fs::exists(current.parent_path() / "lib")) {
        return current.parent_path();
    }

    // Fallback to current directory
    return fs::current_path();
}

std::filesystem::path getLibDir() {
    return getProjectRoot() / "lib";
}

std::filesystem::path createTempDir() {
    std::error_code ec;
    fs::path base = fs::temp_directory_path(ec);
    if (ec) {
        base = fs::current_path();
    }

    // Generate unique directory name
    auto now = std::chrono::system_clock::now();
    auto epoch = now.time_since_epoch();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(epoch).count();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 999999);

    std::ostringstream oss;
    oss << "matiec_test_" << ms << "_" << dis(gen);

    fs::path temp_dir = base / oss.str();
    fs::create_directories(temp_dir);

    return temp_dir;
}

void removeTempDir(const std::filesystem::path& dir) {
    if (fs::exists(dir) && fs::is_directory(dir)) {
        std::error_code ec;
        fs::remove_all(dir, ec);
        // Ignore errors on cleanup
    }
}

std::optional<std::string> readFile(const std::filesystem::path& path) {
    std::ifstream file(path, std::ios::binary);
    if (!file) {
        return std::nullopt;
    }

    std::ostringstream oss;
    oss << file.rdbuf();
    return oss.str();
}

bool writeFile(const std::filesystem::path& path, std::string_view content) {
    // Ensure parent directory exists
    if (path.has_parent_path()) {
        std::error_code ec;
        fs::create_directories(path.parent_path(), ec);
        if (ec) {
            return false;
        }
    }

    std::ofstream file(path, std::ios::binary);
    if (!file) {
        return false;
    }

    file.write(content.data(), static_cast<std::streamsize>(content.size()));
    return file.good();
}

// TempDir implementation

TempDir::TempDir() : path_(createTempDir()) {}

TempDir::~TempDir() {
    if (!path_.empty()) {
        removeTempDir(path_);
    }
}

TempDir::TempDir(TempDir&& other) noexcept : path_(std::move(other.path_)) {
    other.path_.clear();
}

TempDir& TempDir::operator=(TempDir&& other) noexcept {
    if (this != &other) {
        if (!path_.empty()) {
            removeTempDir(path_);
        }
        path_ = std::move(other.path_);
        other.path_.clear();
    }
    return *this;
}

std::string makeSimpleProgram(std::string_view name, std::string_view body) {
    std::ostringstream oss;
    oss << "PROGRAM " << name << "\n"
        << "VAR\n"
        << "    temp : INT;\n"
        << "END_VAR\n"
        << body << "\n"
        << "END_PROGRAM\n";
    return oss.str();
}

std::string makeFunctionBlock(std::string_view name, std::string_view body) {
    std::ostringstream oss;
    oss << "FUNCTION_BLOCK " << name << "\n"
        << "VAR_INPUT\n"
        << "    in1 : INT;\n"
        << "END_VAR\n"
        << "VAR_OUTPUT\n"
        << "    out1 : INT;\n"
        << "END_VAR\n"
        << body << "\n"
        << "END_FUNCTION_BLOCK\n";
    return oss.str();
}

} // namespace matiec::test
