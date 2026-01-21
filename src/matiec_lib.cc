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
 * @file matiec_lib.cc
 * @brief Implementation of the matiec C library API
 */

#include "matiec/matiec.h"
#include "matiec/error.hpp"
#include "matiec/string_utils.hpp"
#include "config/config.h"
#include "absyntax/absyntax.hh"
#include "absyntax_utils/absyntax_utils.hh"
#include "stage1_2/stage1_2.hh"
#include "stage3/stage3.hh"
#include "stage4/stage4.hh"
#include "main.hh"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <string>
#include <vector>
#include <fstream>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

static char* matiec_strdup(const char* s) {
    if (!s) return nullptr;
#ifdef _WIN32
    return _strdup(s);
#else
    return ::strdup(s);
#endif
}

/* Global error callback */
static matiec_error_callback_t g_error_callback = nullptr;
static void *g_error_user_data = nullptr;

/* Temporary file for string compilation */
static std::string g_temp_file_path;

namespace {
// Owns the compilation AST roots and cleans up global per-compilation state.
// The compiler pipeline still uses raw pointers, but we use RAII at the API
// boundary to guarantee cleanup on all exit paths (including exceptions).
struct ast_roots_deleter {
    symbol_c* ordered_root = nullptr;

    void operator()(symbol_c* tree_root) const noexcept {
        matiec::ast_delete(tree_root, ordered_root);
    }
};

class compilation_cleanup_guard final {
public:
    compilation_cleanup_guard() = default;
    compilation_cleanup_guard(const compilation_cleanup_guard&) = delete;
    compilation_cleanup_guard& operator=(const compilation_cleanup_guard&) = delete;

    ~compilation_cleanup_guard() noexcept {
        // These global tables store raw pointers into the AST; clear them before
        // freeing the compilation's AST.
        absyntax_utils_reset();

        // Always run ast_delete(), even if we never got a root pointer back,
        // so any heap-tracked symbols are released.
        const auto deleter = tree_root_.get_deleter();
        symbol_c* root = tree_root_.release();
        deleter(root);

        // Release lexer-owned strings used by tokens/filenames.
        matiec::cstr_pool_clear();

        // Clear stage1_2 lexer/parser symbol tables and flags for the next run.
        stage1_2_reset();
    }

    std::unique_ptr<symbol_c, ast_roots_deleter>& tree_root_owner() noexcept {
        return tree_root_;
    }

private:
    std::unique_ptr<symbol_c, ast_roots_deleter> tree_root_{nullptr, ast_roots_deleter{nullptr}};
};
} // namespace

extern "C" {

MATIEC_API void matiec_options_init(matiec_options_t *opts) {
    if (!opts) return;

    memset(opts, 0, sizeof(matiec_options_t));

    opts->include_dir = nullptr;
    opts->output_dir = nullptr;
    opts->output_format = MATIEC_OUTPUT_C;

    opts->allow_forward_refs = false;
    opts->relaxed_datatype_model = false;
    opts->safe_extensions = false;
    opts->nested_comments = false;
    opts->ref_extensions = false;
    opts->ref_nonstandard = false;
    opts->nonliteral_array_size = false;
    opts->allow_void_functions = false;
    opts->allow_missing_var_in = false;
    opts->disable_implicit_en_eno = false;
    opts->conversion_functions = false;
    opts->full_token_location = false;
}

static void apply_options(const matiec_options_t *opts) {
    if (!opts) {
        /* Apply defaults */
        runtime_options.pre_parsing = false;
        runtime_options.relaxed_datatype_model = false;
        runtime_options.safe_extensions = false;
        runtime_options.nested_comments = false;
        runtime_options.ref_standard_extensions = false;
        runtime_options.ref_nonstand_extensions = false;
        runtime_options.nonliteral_in_array_size = false;
        runtime_options.allow_void_datatype = false;
        runtime_options.allow_missing_var_in = false;
        runtime_options.disable_implicit_en_eno = false;
        runtime_options.conversion_functions = false;
        runtime_options.full_token_loc = false;
        runtime_options.includedir = nullptr;
        return;
    }

    runtime_options.pre_parsing = opts->allow_forward_refs;
    runtime_options.relaxed_datatype_model = opts->relaxed_datatype_model;
    runtime_options.safe_extensions = opts->safe_extensions;
    runtime_options.nested_comments = opts->nested_comments;
    runtime_options.ref_standard_extensions = opts->ref_extensions || opts->ref_nonstandard;
    runtime_options.ref_nonstand_extensions = opts->ref_nonstandard;
    runtime_options.nonliteral_in_array_size = opts->nonliteral_array_size;
    runtime_options.allow_void_datatype = opts->allow_void_functions;
    runtime_options.allow_missing_var_in = opts->allow_missing_var_in;
    runtime_options.disable_implicit_en_eno = opts->disable_implicit_en_eno;
    runtime_options.conversion_functions = opts->conversion_functions;
    runtime_options.full_token_loc = opts->full_token_location;
    runtime_options.includedir = opts->include_dir;
}

static void result_init(matiec_result_t *result) {
    if (!result) return;

    memset(result, 0, sizeof(matiec_result_t));
    result->error_code = MATIEC_OK;
    result->error_message = nullptr;
    result->error_line = 0;
    result->error_column = 0;
    result->error_file = nullptr;
    result->output_files = nullptr;
    result->output_file_count = 0;
}

static matiec_error_t map_error_category(matiec::ErrorCategory category) {
    switch (category) {
        case matiec::ErrorCategory::Lexical:
        case matiec::ErrorCategory::Syntax:
            return MATIEC_ERROR_PARSE;
        case matiec::ErrorCategory::Semantic:
        case matiec::ErrorCategory::Type:
            return MATIEC_ERROR_SEMANTIC;
        case matiec::ErrorCategory::CodeGen:
            return MATIEC_ERROR_CODEGEN;
        case matiec::ErrorCategory::IO:
            return MATIEC_ERROR_IO;
        case matiec::ErrorCategory::Internal:
        default:
            return MATIEC_ERROR_INTERNAL;
    }
}

static const matiec::CompilerError* first_reported_error() {
    const auto& errors = matiec::globalErrorReporter().errors();
    for (const auto& err : errors) {
        if (err.isError()) {
            return &err;
        }
    }
    return nullptr;
}

static void result_clear_error_details(matiec_result_t* result) {
    if (!result) return;

    if (result->error_message) {
        free(result->error_message);
        result->error_message = nullptr;
    }

    // reserved[0] stores an owned copy of error_file (if any).
    if (result->reserved[0]) {
        free(result->reserved[0]);
        result->reserved[0] = nullptr;
    }

    result->error_line = 0;
    result->error_column = 0;
    result->error_file = nullptr;
}

static void result_set_error(matiec_result_t *result, matiec_error_t code, const char *message) {
    if (!result) return;

    result_clear_error_details(result);
    result->error_code = code;
    if (message) {
        result->error_message = matiec_strdup(message);
    }
}

static void result_set_error_from_reporter(matiec_result_t* result,
                                          matiec_error_t fallback_code,
                                          const char* fallback_message) {
    if (!result) return;

    const matiec::CompilerError* err = first_reported_error();
    if (!err) {
        result_set_error(result, fallback_code, fallback_message);
        return;
    }

    result_clear_error_details(result);

    result->error_code = map_error_category(err->category());

    const std::string formatted = err->format();
    result->error_message = matiec_strdup(formatted.c_str());

    if (err->location() && err->location()->isValid()) {
        result->error_line = err->location()->line;
        result->error_column = err->location()->column;

        if (!err->location()->filename.empty()) {
            char* file_copy = matiec_strdup(err->location()->filename.c_str());
            if (file_copy) {
                result->reserved[0] = file_copy;
                result->error_file = file_copy;
            }
        }
    }
}

MATIEC_API matiec_error_t matiec_compile_file(
    const char *input_file,
    const matiec_options_t *opts,
    matiec_result_t *result
) {
    if (!result) {
        return MATIEC_ERROR_INVALID_ARG;
    }

    result_init(result);

    // Reset global error reporter for this compilation
    matiec::resetGlobalErrorReporter();

    // Set up error callback bridge if user provided one
    if (g_error_callback) {
        matiec::globalErrorReporter().setCallback(
            [](const matiec::CompilerError& err) {
                if (!g_error_callback) {
                    return;
                }

                const char* file = nullptr;
                int line = 0;
                int column = 0;

                if (err.location() && err.location()->isValid()) {
                    file = err.location()->filename.c_str();
                    line = err.location()->line;
                    column = err.location()->column;
                }

                // Include severity in message since the C callback does not
                // expose it explicitly.
                std::string msg = std::string(matiec::severityToString(err.severity()))
                                  + ": " + err.message();

                g_error_callback(file, line, column, msg.c_str(), g_error_user_data);
            }
        );
    } else {
        // Ensure we don't keep a stale callback from a previous compilation.
        matiec::globalErrorReporter().setCallback(nullptr);
    }

    if (!input_file) {
        result_set_error(result, MATIEC_ERROR_INVALID_ARG, "Input file path is NULL");
        return MATIEC_ERROR_INVALID_ARG;
    }

    /* Check if file exists */
    FILE *f = fopen(input_file, "r");
    if (!f) {
        result_set_error(result, MATIEC_ERROR_FILE_NOT_FOUND, "Input file not found");
        return MATIEC_ERROR_FILE_NOT_FOUND;
    }
    fclose(f);

    /* Apply compiler options */
    apply_options(opts);

    /* Prepare output directory */
    const char *builddir = nullptr;
    if (opts && opts->output_dir) {
        builddir = opts->output_dir;
    }

    /* Set output format via stage4 options */
    if (opts && opts->output_format == MATIEC_OUTPUT_IEC) {
        stage4_parse_options(const_cast<char*>("IEC"));
    }

    symbol_c *tree_root = nullptr;
    symbol_c *ordered_tree_root = nullptr;
    matiec_error_t ret = MATIEC_OK;

    // Ensure cleanup happens even on early returns/exceptions.
    compilation_cleanup_guard cleanup;

    try {
        // Ensure stale global state from prior in-process compilations does not
        // affect this run.
        stage1_2_reset();
        absyntax_utils_reset();
        matiec::cstr_pool_clear();

        /* Stage 1 & 2: Lexical and Syntax analysis */
        if (stage1_2(const_cast<char*>(input_file), &tree_root) < 0) {    
            result_set_error_from_reporter(
                result,
                MATIEC_ERROR_PARSE,
                "Parsing failed (lexical or syntax error)");
            ret = result->error_code;
            cleanup.tree_root_owner().reset(tree_root);
            return ret;
        }
        cleanup.tree_root_owner().reset(tree_root);

        /* Stage pre-3: Initialize symbol tables */
        absyntax_utils_reset();
        absyntax_utils_init(tree_root);

        /* Stage 3: Semantic analysis */
        if (stage3(tree_root, &ordered_tree_root) < 0) {
            cleanup.tree_root_owner().get_deleter().ordered_root = ordered_tree_root;
            result_set_error_from_reporter(
                result,
                MATIEC_ERROR_SEMANTIC,
                "Semantic analysis failed");
            ret = result->error_code;
            return ret;
        }
        cleanup.tree_root_owner().get_deleter().ordered_root = ordered_tree_root;

        /* Stage 4: Code generation */
        if (stage4(ordered_tree_root, const_cast<char*>(builddir)) < 0) { 
            result_set_error_from_reporter(
                result,
                MATIEC_ERROR_CODEGEN,
                "Code generation failed");
            ret = result->error_code;
            return ret;
        }

        ret = MATIEC_OK;
    } catch (const matiec::InternalCompilerErrorException& ex) {
        result_set_error_from_reporter(result, MATIEC_ERROR_INTERNAL, ex.what());
        ret = result->error_code;
    } catch (const std::exception& ex) {
        result_set_error(result, MATIEC_ERROR_INTERNAL, ex.what());
        ret = MATIEC_ERROR_INTERNAL;
    } catch (...) {
        result_set_error(result, MATIEC_ERROR_INTERNAL, "Unknown internal compiler error");
        ret = MATIEC_ERROR_INTERNAL;
    }

    return ret;
}

MATIEC_API matiec_error_t matiec_compile_string(
    const char *source,
    size_t source_len,
    const char *source_name,
    const matiec_options_t *opts,
    matiec_result_t *result
) {
    if (!result) {
        return MATIEC_ERROR_INVALID_ARG;
    }

    result_init(result);

    if (!source) {
        result_set_error(result, MATIEC_ERROR_INVALID_ARG, "Source string is NULL");
        return MATIEC_ERROR_INVALID_ARG;
    }

    /* Calculate length if not provided */
    if (source_len == 0) {
        source_len = strlen(source);
    }

    /* Create temporary file */
    const char *name = source_name ? source_name : "input.st";

#ifdef _WIN32
    char temp_path[MAX_PATH];
    char temp_file[MAX_PATH];
    GetTempPathA(MAX_PATH, temp_path);
    GetTempFileNameA(temp_path, "iec", 0, temp_file);
    g_temp_file_path = temp_file;
#else
    char temp_template[] = "/tmp/matiec_XXXXXX.st";
    int fd = mkstemps(temp_template, 3);
    if (fd < 0) {
        result_set_error(result, MATIEC_ERROR_IO, "Failed to create temporary file");
        return MATIEC_ERROR_IO;
    }
    close(fd);
    g_temp_file_path = temp_template;
#endif

    /* Write source to temp file */
    FILE *f = fopen(g_temp_file_path.c_str(), "w");
    if (!f) {
        result_set_error(result, MATIEC_ERROR_IO, "Failed to write temporary file");
        return MATIEC_ERROR_IO;
    }
    fwrite(source, 1, source_len, f);
    fclose(f);

    /* Compile the temp file */
    matiec_error_t ret = matiec_compile_file(g_temp_file_path.c_str(), opts, result);

    /* Clean up temp file */
    remove(g_temp_file_path.c_str());

    return ret;
}

MATIEC_API void matiec_result_free(matiec_result_t *result) {
    if (!result) return;

    // reserved[0] stores an owned copy of error_file (if any).
    if (result->reserved[0]) {
        free(result->reserved[0]);
        result->reserved[0] = nullptr;
    }
    result->error_file = nullptr;

    if (result->error_message) {
        free(result->error_message);
        result->error_message = nullptr;
    }

    if (result->output_files) {
        for (int i = 0; i < result->output_file_count; i++) {
            free(result->output_files[i]);
        }
        free(result->output_files);
        result->output_files = nullptr;
    }

    result->output_file_count = 0;
}

MATIEC_API void matiec_set_error_callback(
    matiec_error_callback_t callback,
    void *user_data
) {
    g_error_callback = callback;
    g_error_user_data = user_data;
}

MATIEC_API const char* matiec_version(void) {
    return MATIEC_VERSION_STRING;
}

MATIEC_API const char* matiec_error_string(matiec_error_t error) {
    switch (error) {
        case MATIEC_OK:
            return "Success";
        case MATIEC_ERROR_INVALID_ARG:
            return "Invalid argument";
        case MATIEC_ERROR_FILE_NOT_FOUND:
            return "File not found";
        case MATIEC_ERROR_PARSE:
            return "Parse error (lexical or syntax)";
        case MATIEC_ERROR_SEMANTIC:
            return "Semantic error";
        case MATIEC_ERROR_CODEGEN:
            return "Code generation error";
        case MATIEC_ERROR_IO:
            return "I/O error";
        case MATIEC_ERROR_INTERNAL:
            return "Internal compiler error";
        default:
            return "Unknown error";
    }
}

MATIEC_API bool matiec_is_supported_extension(const char *extension) {
    if (!extension) return false;

    /* Skip leading dot if present */
    if (extension[0] == '.') {
        extension++;
    }

    /* Supported extensions (case-insensitive) */
    const char *supported[] = {"st", "il", "sfc", "iec", nullptr};        

    for (int i = 0; supported[i] != nullptr; i++) {
        if (matiec::iequals(extension, supported[i])) return true;
    }

    return false;
}

} /* extern "C" */
