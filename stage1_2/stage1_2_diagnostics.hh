/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Shared diagnostics helpers for stage1_2 (lexer/parser).
 */

#ifndef MATIEC_STAGE1_2_DIAGNOSTICS_HH
#define MATIEC_STAGE1_2_DIAGNOSTICS_HH

#include <optional>
#include <string>
#include <string_view>

#include "matiec/error.hpp"

namespace matiec::stage1_2 {

inline std::optional<matiec::SourceLocation> make_location(const char* filename,
                                                           int line,
                                                           int column,
                                                           const char* unknown_file = nullptr) {
    matiec::SourceLocation loc;
    if (filename && (!unknown_file || std::string_view(filename) != unknown_file)) {
        loc.filename = filename;
    }
    loc.line = line;
    loc.column = column;
    if (!loc.isValid()) {
        return std::nullopt;
    }
    return loc;
}

inline void report_parse_error(const char* message,
                               const char* filename,
                               int line,
                               int column,
                               const char* unknown_file = nullptr) {
    if (!message) {
        return;
    }

    const auto location = make_location(filename, line, column, unknown_file);
    if (location) {
        matiec::globalErrorReporter().reportParseError(message, *location);
    } else {
        matiec::globalErrorReporter().reportParseError(message);
    }
}

inline void report_error(matiec::ErrorSeverity severity,
                         matiec::ErrorCategory category,
                         const char* message,
                         const char* filename = nullptr,
                         int line = 0,
                         int column = 0,
                         const char* unknown_file = nullptr) {
    if (!message) {
        return;
    }

    const auto location = make_location(filename, line, column, unknown_file);
    matiec::globalErrorReporter().report(severity, category, std::string(message), location);
}

inline void report_error(matiec::ErrorSeverity severity,
                         matiec::ErrorCategory category,
                         const std::string& message,
                         const char* filename = nullptr,
                         int line = 0,
                         int column = 0,
                         const char* unknown_file = nullptr) {
    const auto location = make_location(filename, line, column, unknown_file);
    matiec::globalErrorReporter().report(severity, category, message, location);
}

} // namespace matiec::stage1_2

#endif // MATIEC_STAGE1_2_DIAGNOSTICS_HH
