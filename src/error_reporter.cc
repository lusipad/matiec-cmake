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
 * @file error_reporter.cc
 * @brief Implementation of the error reporting infrastructure
 */

#include "matiec/error.hpp"

#include <cstdio>
#include <sstream>
#include <iostream>

namespace matiec {

// =============================================================================
// SourceLocation implementation
// =============================================================================

std::string SourceLocation::toString() const {
    if (!isValid()) {
        return "<unknown location>";
    }

    std::ostringstream oss;
    oss << filename << ":" << line;
    if (column > 0) {
        oss << ":" << column;
    }
    return oss.str();
}

// =============================================================================
// CompilerError implementation
// =============================================================================

std::string CompilerError::format() const {
    std::ostringstream oss;

    // GCC-style format: file:line:col: severity: message
    if (location_ && location_->isValid()) {
        oss << location_->toString() << ": ";
    }

    oss << severityToString(severity_) << ": " << message_;

    return oss.str();
}

// =============================================================================
// TypeError implementation
// =============================================================================

std::string TypeError::format() const {
    std::ostringstream oss;

    if (location_ && location_->isValid()) {
        oss << location_->toString() << ": ";
    }

    oss << severityToString(severity_) << ": " << message_;

    if (!expected_type_.empty() || !actual_type_.empty()) {
        oss << " (";
        if (!expected_type_.empty()) {
            oss << "expected: " << expected_type_;
            if (!actual_type_.empty()) {
                oss << ", ";
            }
        }
        if (!actual_type_.empty()) {
            oss << "got: " << actual_type_;
        }
        oss << ")";
    }

    return oss.str();
}

// =============================================================================
// InternalError implementation
// =============================================================================

std::string InternalError::format() const {
    std::ostringstream oss;

    oss << "INTERNAL COMPILER ERROR at " << source_file_ << ":" << source_line_;
    oss << "\n  " << message_;
    oss << "\n  Please report this bug.";

    return oss.str();
}

// =============================================================================
// ErrorReporter implementation
// =============================================================================

void ErrorReporter::report(CompilerError error) {
    // Update counters
    if (error.isError()) {
        ++error_count_;
    } else if (error.severity() == ErrorSeverity::Warning) {
        ++warning_count_;
    }

    if (error.isFatal()) {
        has_fatal_ = true;
    }

    // Call callback if set
    if (callback_) {
        callback_(error);
    }

    // Store error
    errors_.push_back(std::move(error));
}

void ErrorReporter::report(ErrorSeverity severity, ErrorCategory category,
                           std::string message, std::optional<SourceLocation> location) {
    CompilerError error(severity, category, std::move(message));
    if (location) {
        error = CompilerError(severity, category, error.message(), std::move(*location));
    }
    report(std::move(error));
}

void ErrorReporter::reportParseError(std::string message, SourceLocation location) {
    report(ParseError(std::move(message), std::move(location)));
}

void ErrorReporter::reportParseError(std::string message) {
    report(ParseError(std::move(message)));
}

void ErrorReporter::reportSemanticError(std::string message, SourceLocation location) {
    report(SemanticError(std::move(message), std::move(location)));
}

void ErrorReporter::reportSemanticError(std::string message) {
    report(SemanticError(std::move(message)));
}

void ErrorReporter::reportTypeError(std::string message, SourceLocation location,
                                    std::string expected, std::string actual) {
    report(TypeError(std::move(message), std::move(location),
                     std::move(expected), std::move(actual)));
}

[[noreturn]] void ErrorReporter::reportInternalError(std::string message,
                                                      const char* file, int line) {
    const char* safe_file = (file != nullptr) ? file : "<unknown>";

    std::ostringstream oss;
    oss << "Internal compiler error in file " << safe_file << " at line " << line;
    if (!message.empty()) {
        oss << ": " << message;
    }

    const std::string full_message = oss.str();
    report(ErrorSeverity::Fatal, ErrorCategory::Internal, full_message);
    throw InternalCompilerErrorException(full_message, safe_file, line);
}

void ErrorReporter::reportWarning(std::string message, std::optional<SourceLocation> location) {
    CompilerError error(ErrorSeverity::Warning, ErrorCategory::Semantic, std::move(message));
    if (location) {
        error = CompilerError(ErrorSeverity::Warning, ErrorCategory::Semantic,
                              error.message(), std::move(*location));
    }
    report(std::move(error));
}

void ErrorReporter::clear() noexcept {
    errors_.clear();
    error_count_ = 0;
    warning_count_ = 0;
    has_fatal_ = false;
}

void ErrorReporter::printAll() const {
    for (const auto& error : errors_) {
        std::cerr << error.format() << std::endl;
    }
}

void ErrorReporter::printSummary() const {
    if (error_count_ == 0 && warning_count_ == 0) {
        return;
    }

    std::cerr << error_count_ << " error";
    if (error_count_ != 1) {
        std::cerr << "s";
    }

    if (warning_count_ > 0) {
        std::cerr << ", " << warning_count_ << " warning";
        if (warning_count_ != 1) {
            std::cerr << "s";
        }
    }

    std::cerr << " generated." << std::endl;
}

// =============================================================================
// Global error reporter
// =============================================================================

namespace {
    // Use a function-local static to ensure proper initialization order
    ErrorReporter& getGlobalReporter() {
        static ErrorReporter reporter;
        return reporter;
    }
}

ErrorReporter& globalErrorReporter() {
    return getGlobalReporter();
}

void resetGlobalErrorReporter() {
    getGlobalReporter().clear();
}

} // namespace matiec
