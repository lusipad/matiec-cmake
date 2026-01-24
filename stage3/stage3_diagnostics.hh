/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Shared diagnostics helpers for stage3 checks.
 */

#ifndef MATIEC_STAGE3_DIAGNOSTICS_HH
#define MATIEC_STAGE3_DIAGNOSTICS_HH

#include <cstdio>
#include <optional>
#include <string>

#include "absyntax/absyntax.hh"
#include "matiec/error.hpp"
#include "matiec/format.hpp"

namespace matiec::stage3 {

inline const symbol_c* first_symbol(const symbol_c* lhs, const symbol_c* rhs) {
    return (lhs->first_order < rhs->first_order) ? lhs : rhs;
}

inline const symbol_c* last_symbol(const symbol_c* lhs, const symbol_c* rhs) {
    return (lhs->last_order > rhs->last_order) ? lhs : rhs;
}

inline std::optional<matiec::SourceLocation> make_location(const symbol_c* first) {
    matiec::SourceLocation loc;
    loc.filename = (first->first_file != nullptr) ? first->first_file : "";
    loc.line = first->first_line;
    loc.column = first->first_column;

    if (!loc.isValid()) {
        return std::nullopt;
    }
    return loc;
}

inline void emit_diagnostic(matiec::ErrorSeverity severity,
                            matiec::ErrorCategory category,
                            const symbol_c* symbol1,
                            const symbol_c* symbol2,
                            const std::string& message) {
    const symbol_c* first = first_symbol(symbol1, symbol2);
    const symbol_c* last = last_symbol(symbol1, symbol2);
    const auto location = make_location(first);

    matiec::globalErrorReporter().report(severity, category, message, location);

    const char* label = (severity == matiec::ErrorSeverity::Warning) ? "warning" : "error";
    std::fprintf(stderr, "%s:%d-%d..%d-%d: %s: %s\n",
                 first->first_file, first->first_line, first->first_column,
                 last->last_line, last->last_column,
                 label, message.c_str());
}

inline void report_error(matiec::ErrorCategory category,
                         const symbol_c* symbol1,
                         const symbol_c* symbol2,
                         const std::string& message) {
    emit_diagnostic(matiec::ErrorSeverity::Error, category, symbol1, symbol2, message);
}

inline void report_warning(matiec::ErrorCategory category,
                           const symbol_c* symbol1,
                           const symbol_c* symbol2,
                           const std::string& message) {
    emit_diagnostic(matiec::ErrorSeverity::Warning, category, symbol1, symbol2, message);
}

} // namespace matiec::stage3

#define MATIEC_STAGE3_ERROR(error_level, category, symbol1, symbol2, error_count_ref, display_level, ...) \
    do { \
        if ((display_level) >= (error_level)) { \
            std::string _matiec_msg = matiec::format(__VA_ARGS__); \
            ::matiec::stage3::report_error((category), (symbol1), (symbol2), _matiec_msg); \
            ++(error_count_ref); \
        } \
    } while (0)

#define MATIEC_STAGE3_WARNING(category, symbol1, symbol2, warning_flag_ref, ...) \
    do { \
        std::string _matiec_msg = matiec::format(__VA_ARGS__); \
        ::matiec::stage3::report_warning((category), (symbol1), (symbol2), _matiec_msg); \
        (warning_flag_ref) = true; \
    } while (0)

#endif // MATIEC_STAGE3_DIAGNOSTICS_HH
