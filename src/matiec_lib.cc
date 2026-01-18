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
#include <string>
#include <vector>
#include <fstream>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

/* Global error callback */
static matiec_error_callback_t g_error_callback = nullptr;
static void *g_error_user_data = nullptr;

/* Temporary file for string compilation */
static std::string g_temp_file_path;

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

static void result_set_error(matiec_result_t *result, matiec_error_t code, const char *message) {
    if (!result) return;

    result->error_code = code;
    if (message) {
        result->error_message = strdup(message);
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
                if (g_error_callback) {
                    const char* file = nullptr;
                    int line = 0;
                    int column = 0;

                    if (err.location() && err.location()->isValid()) {
                        file = err.location()->filename.c_str();
                        line = err.location()->line;
                        column = err.location()->column;
                    }

                    g_error_callback(file, line, column,
                                     err.message().c_str(), g_error_user_data);
                }
            }
        );
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

    /* Stage 1 & 2: Lexical and Syntax analysis */
    if (stage1_2(const_cast<char*>(input_file), &tree_root) < 0) {
        result_set_error(result, MATIEC_ERROR_PARSE, "Parsing failed (lexical or syntax error)");
        return MATIEC_ERROR_PARSE;
    }

    /* Stage pre-3: Initialize symbol tables */
    absyntax_utils_init(tree_root);

    /* Stage 3: Semantic analysis */
    if (stage3(tree_root, &ordered_tree_root) < 0) {
        result_set_error(result, MATIEC_ERROR_SEMANTIC, "Semantic analysis failed");
        return MATIEC_ERROR_SEMANTIC;
    }

    /* Stage 4: Code generation */
    if (stage4(ordered_tree_root, const_cast<char*>(builddir)) < 0) {
        result_set_error(result, MATIEC_ERROR_CODEGEN, "Code generation failed");
        return MATIEC_ERROR_CODEGEN;
    }

    return MATIEC_OK;
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
#ifdef _WIN32
        if (_stricmp(extension, supported[i]) == 0) return true;
#else
        if (strcasecmp(extension, supported[i]) == 0) return true;
#endif
    }

    return false;
}

} /* extern "C" */
