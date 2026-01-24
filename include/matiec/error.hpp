/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Copyright (C) 2003-2011  Mario de Sousa (msousa@fe.up.pt)
 *  Copyright (C) 2007-2011  Laurent Bessard and Edouard Tisserant
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 */

/**
 * @file error.hpp
 * @brief Modern C++17 error handling infrastructure for matiec
 *
 * This header provides structured error types and an error collection system
 * to replace the legacy fprintf(stderr)/exit() pattern.
 */

#ifndef MATIEC_ERROR_HPP
#define MATIEC_ERROR_HPP

#include <string>
#include <string_view>
#include <vector>
#include <optional>
#include <functional>
#include <memory>
#include <stdexcept>
#include <cstdint>

namespace matiec {

/**
 * @brief Source location information
 */
struct SourceLocation {
    std::string filename;
    int line = 0;
    int column = 0;

    [[nodiscard]] bool isValid() const noexcept {
        return !filename.empty() && line > 0;
    }

    [[nodiscard]] std::string toString() const;
};

/**
 * @brief Error severity levels
 */
enum class ErrorSeverity : uint8_t {
    Note,       // Informational message
    Warning,    // Non-fatal issue
    Error,      // Recoverable error
    Fatal       // Unrecoverable error (compilation must stop)
};

/**
 * @brief Error category for classification
 */
enum class ErrorCategory : uint8_t {
    Internal,   // Internal compiler error (bug)
    Lexical,    // Lexical analysis error
    Syntax,     // Syntax/parsing error
    Semantic,   // Semantic analysis error
    Type,       // Type checking error
    CodeGen,    // Code generation error
    IO          // File I/O error
};

/**
 * @brief Convert severity to string
 */
[[nodiscard]] constexpr std::string_view severityToString(ErrorSeverity severity) noexcept {
    switch (severity) {
        case ErrorSeverity::Note:    return "note";
        case ErrorSeverity::Warning: return "warning";
        case ErrorSeverity::Error:   return "error";
        case ErrorSeverity::Fatal:   return "fatal error";
    }
    return "unknown";
}

/**
 * @brief Convert category to string
 */
[[nodiscard]] constexpr std::string_view categoryToString(ErrorCategory category) noexcept {
    switch (category) {
        case ErrorCategory::Internal: return "internal";
        case ErrorCategory::Lexical:  return "lexical";
        case ErrorCategory::Syntax:   return "syntax";
        case ErrorCategory::Semantic: return "semantic";
        case ErrorCategory::Type:     return "type";
        case ErrorCategory::CodeGen:  return "codegen";
        case ErrorCategory::IO:       return "io";
    }
    return "unknown";
}

/**
 * @brief Base class for all compiler errors
 */
class CompilerError {
public:
    CompilerError(ErrorSeverity severity, ErrorCategory category, std::string message)
        : severity_(severity), category_(category), message_(std::move(message)) {}

    CompilerError(ErrorSeverity severity, ErrorCategory category, std::string message,
                  SourceLocation location)
        : severity_(severity), category_(category), message_(std::move(message)),
          location_(std::move(location)) {}

    virtual ~CompilerError() = default;

    // Non-copyable, movable
    CompilerError(const CompilerError&) = default;
    CompilerError& operator=(const CompilerError&) = default;
    CompilerError(CompilerError&&) = default;
    CompilerError& operator=(CompilerError&&) = default;

    [[nodiscard]] ErrorSeverity severity() const noexcept { return severity_; }
    [[nodiscard]] ErrorCategory category() const noexcept { return category_; }
    [[nodiscard]] const std::string& message() const noexcept { return message_; }
    [[nodiscard]] const std::optional<SourceLocation>& location() const noexcept { return location_; }

    [[nodiscard]] bool isError() const noexcept {
        return severity_ == ErrorSeverity::Error || severity_ == ErrorSeverity::Fatal;
    }

    [[nodiscard]] bool isFatal() const noexcept {
        return severity_ == ErrorSeverity::Fatal;
    }

    /**
     * @brief Format error for display (GCC-style format)
     * @return Formatted error string: "file:line:col: severity: message"
     */
    [[nodiscard]] virtual std::string format() const;

    /**
     * @brief Clone the error preserving dynamic type
     */
    [[nodiscard]] virtual std::unique_ptr<CompilerError> clone() const {
        return std::make_unique<CompilerError>(*this);
    }

protected:
    ErrorSeverity severity_;
    ErrorCategory category_;
    std::string message_;
    std::optional<SourceLocation> location_;
};

/**
 * @brief Parse/syntax error
 */
class ParseError : public CompilerError {
public:
    ParseError(std::string message, SourceLocation location)
        : CompilerError(ErrorSeverity::Error, ErrorCategory::Syntax,
                        std::move(message), std::move(location)) {}

    ParseError(std::string message)
        : CompilerError(ErrorSeverity::Error, ErrorCategory::Syntax, std::move(message)) {}

    [[nodiscard]] std::unique_ptr<CompilerError> clone() const override {
        return std::make_unique<ParseError>(*this);
    }
};

/**
 * @brief Semantic analysis error
 */
class SemanticError : public CompilerError {
public:
    SemanticError(std::string message, SourceLocation location)
        : CompilerError(ErrorSeverity::Error, ErrorCategory::Semantic,
                        std::move(message), std::move(location)) {}

    SemanticError(std::string message)
        : CompilerError(ErrorSeverity::Error, ErrorCategory::Semantic, std::move(message)) {}

    [[nodiscard]] std::unique_ptr<CompilerError> clone() const override {
        return std::make_unique<SemanticError>(*this);
    }
};

/**
 * @brief Type checking error
 */
class TypeError : public CompilerError {
public:
    TypeError(std::string message, SourceLocation location,
              std::string expected_type = "", std::string actual_type = "")
        : CompilerError(ErrorSeverity::Error, ErrorCategory::Type,
                        std::move(message), std::move(location)),
          expected_type_(std::move(expected_type)),
          actual_type_(std::move(actual_type)) {}

    [[nodiscard]] const std::string& expectedType() const noexcept { return expected_type_; }
    [[nodiscard]] const std::string& actualType() const noexcept { return actual_type_; }

    [[nodiscard]] std::string format() const override;
    [[nodiscard]] std::unique_ptr<CompilerError> clone() const override {
        return std::make_unique<TypeError>(*this);
    }

private:
    std::string expected_type_;
    std::string actual_type_;
};

/**
 * @brief Internal compiler error (indicates a bug)
 */
class InternalError : public CompilerError {
public:
    InternalError(std::string message, const char* file, int line)
        : CompilerError(ErrorSeverity::Fatal, ErrorCategory::Internal, std::move(message)),
          source_file_(file), source_line_(line) {}

    [[nodiscard]] const char* sourceFile() const noexcept { return source_file_; }
    [[nodiscard]] int sourceLine() const noexcept { return source_line_; }

    [[nodiscard]] std::string format() const override;
    [[nodiscard]] std::unique_ptr<CompilerError> clone() const override {
        return std::make_unique<InternalError>(*this);
    }

private:
    const char* source_file_;
    int source_line_;
};

/**
 * @brief Error callback function type
 */
using ErrorCallback = std::function<void(const CompilerError&)>;

/**
 * @brief Error reporter - collects and manages compiler errors
 *
 * Thread-safety: NOT thread-safe. Use one instance per compilation unit.
 */
class ErrorReporter {
public:
    ErrorReporter() = default;
    ~ErrorReporter() = default;

    // Non-copyable, movable
    ErrorReporter(const ErrorReporter&) = delete;
    ErrorReporter& operator=(const ErrorReporter&) = delete;
    ErrorReporter(ErrorReporter&&) = default;
    ErrorReporter& operator=(ErrorReporter&&) = default;

    /**
     * @brief Report an error
     */
    void report(const CompilerError& error);

    /**
     * @brief Report an error (convenience overload)
     */
    void report(ErrorSeverity severity, ErrorCategory category,
                std::string message, std::optional<SourceLocation> location = std::nullopt);

    /**
     * @brief Report a parse error
     */
    void reportParseError(std::string message, SourceLocation location);
    void reportParseError(std::string message);

    /**
     * @brief Report a semantic error
     */
    void reportSemanticError(std::string message, SourceLocation location);
    void reportSemanticError(std::string message);

    /**
     * @brief Report a type error
     */
    void reportTypeError(std::string message, SourceLocation location,
                         std::string expected = "", std::string actual = "");

    /**
     * @brief Report an internal error
     */
    [[noreturn]] void reportInternalError(std::string message, const char* file, int line);

    /**
     * @brief Report a warning
     */
    void reportWarning(std::string message, std::optional<SourceLocation> location = std::nullopt);

    /**
     * @brief Get all collected errors
     */
    [[nodiscard]] const std::vector<CompilerError>& errors() const noexcept {
        return errors_snapshot_;
    }

    /**
     * @brief Get all collected errors with dynamic type preserved
     */
    [[nodiscard]] const std::vector<std::unique_ptr<CompilerError>>& detailedErrors() const noexcept {
        return errors_;
    }

    /**
     * @brief Get error count (errors + fatal errors, not warnings)
     */
    [[nodiscard]] int errorCount() const noexcept { return error_count_; }

    /**
     * @brief Get warning count
     */
    [[nodiscard]] int warningCount() const noexcept { return warning_count_; }

    /**
     * @brief Check if any errors were reported
     */
    [[nodiscard]] bool hasErrors() const noexcept { return error_count_ > 0; }

    /**
     * @brief Check if a fatal error was reported
     */
    [[nodiscard]] bool hasFatalError() const noexcept { return has_fatal_; }

    /**
     * @brief Clear all errors
     */
    void clear() noexcept;

    /**
     * @brief Set error callback (called for each error)
     */
    void setCallback(ErrorCallback callback) { callback_ = std::move(callback); }

    /**
     * @brief Print all errors to stderr
     */
    void printAll() const;

    /**
     * @brief Print summary (e.g., "5 errors, 2 warnings")
     */
    void printSummary() const;

    /**
     * @brief Get/set maximum errors before stopping
     */
    void setMaxErrors(int max) noexcept { max_errors_ = max; }
    [[nodiscard]] int maxErrors() const noexcept { return max_errors_; }
    [[nodiscard]] bool reachedMaxErrors() const noexcept {
        return max_errors_ > 0 && error_count_ >= max_errors_;
    }

private:
    std::vector<std::unique_ptr<CompilerError>> errors_;
    std::vector<CompilerError> errors_snapshot_;
    ErrorCallback callback_;
    int error_count_ = 0;
    int warning_count_ = 0;
    int max_errors_ = 0;  // 0 = unlimited
    bool has_fatal_ = false;
};

/**
 * @brief Exception type thrown on internal compiler errors
 *
 * Internal compiler errors indicate a bug/unrecoverable state. The compiler
 * reports the error via ErrorReporter and then throws this exception to abort
 * the current compilation without terminating the host process (important for
 * library usage and tests).
 */
class InternalCompilerErrorException final : public std::runtime_error {
public:
    InternalCompilerErrorException(std::string message, const char* file, int line)
        : std::runtime_error(std::move(message)),
          source_file_(file ? file : "<unknown>"),
          source_line_(line) {}

    [[nodiscard]] const char* sourceFile() const noexcept { return source_file_; }
    [[nodiscard]] int sourceLine() const noexcept { return source_line_; }

private:
    const char* source_file_;
    int source_line_;
};

/**
 * @brief Global error reporter instance
 *
 * For backward compatibility with existing code that uses global error reporting.
 * New code should prefer passing ErrorReporter instances explicitly.
 */
ErrorReporter& globalErrorReporter();

/**
 * @brief Reset the global error reporter
 */
void resetGlobalErrorReporter();

} // namespace matiec

// =============================================================================
// Convenience macros for error reporting
// =============================================================================

/**
 * @brief Report an internal error with source location
 *
 * Usage: MATIEC_INTERNAL_ERROR("unexpected null pointer")
 */
#define MATIEC_INTERNAL_ERROR(msg) \
    ::matiec::globalErrorReporter().reportInternalError(msg, __FILE__, __LINE__)

/**
 * @brief Assert condition and report internal error if false
 *
 * Usage: MATIEC_ASSERT(ptr != nullptr, "pointer should not be null")
 */
#define MATIEC_ASSERT(cond, msg) \
    do { \
        if (!(cond)) { \
            MATIEC_INTERNAL_ERROR(std::string("Assertion failed: ") + (msg)); \
        } \
    } while (0)

#endif // MATIEC_ERROR_HPP
