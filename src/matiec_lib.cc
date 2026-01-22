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

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
// Avoid the Windows GDI ERROR macro clashing with matiec's legacy ERROR macro
// from main.hh (pulled in transitively by absyntax headers).
#ifdef ERROR
#undef ERROR
#endif
#else
#include <unistd.h>
#endif

#include "matiec/matiec.h"
#include "matiec/error.hpp"
#include "matiec/c_file.hpp"
#include "matiec/scope_exit.hpp"
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
#include <filesystem>
#include <memory>
#include <string>
#include <vector>
#include <fstream>

// IEC generator entry points (built from stage4_iec_alt with renamed symbols).
// These have C++ linkage (same as the rest of stage4).
visitor_c* new_iec_code_generator(stage4out_c* s4o, const char* builddir);
void delete_iec_code_generator(visitor_c* code_generator);

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

static std::string path_stem(const char* path) {
    if (!path || !*path) {
        return "output";
    }

    std::string p(path);
    const size_t sep = p.find_last_of("/\\");
    std::string name = (sep == std::string::npos) ? p : p.substr(sep + 1);

    const size_t dot = name.find_last_of('.');
    if (dot != std::string::npos) {
        name = name.substr(0, dot);
    }

    if (name.empty()) {
        return "output";
    }
    return name;
}

static std::string join_dir_file(const char* dir, const std::string& filename) {
    if (!dir || !*dir) {
        return filename;
    }
    std::string out(dir);
    out += "/";
    out += filename;
    return out;
}

static int stage4_generate_iec_to_file(symbol_c* tree_root,
                                       const char* builddir,
                                       const char* input_file) {
    if (tree_root == nullptr) {
        matiec::globalErrorReporter().report(
            matiec::ErrorSeverity::Fatal,
            matiec::ErrorCategory::Internal,
            "stage4 IEC called with null AST root");
        return -1;
    }

    const std::string radix = path_stem(input_file);

    stage4out_c s4o(builddir, radix.c_str(), "iec");

    struct generator_deleter {
        void operator()(visitor_c* p) const noexcept {
            if (p) {
                delete_iec_code_generator(p);
            }
        }
    };

    std::unique_ptr<visitor_c, generator_deleter> generate_code(
        new_iec_code_generator(&s4o, builddir));
    if (generate_code == nullptr) {
        matiec::globalErrorReporter().report(
            matiec::ErrorSeverity::Fatal,
            matiec::ErrorCategory::Internal,
            "Failed to create stage4 IEC code generator");
        return -1;
    }

    try {
        tree_root->accept(*generate_code);
    } catch (const stage4_codegen_error&) {
        return -1;
    } catch (const std::exception& e) {
        matiec::globalErrorReporter().report(
            matiec::ErrorSeverity::Fatal,
            matiec::ErrorCategory::Internal,
            std::string("Unhandled exception in stage4 IEC: ") + e.what());
        return -1;
    } catch (...) {
        matiec::globalErrorReporter().report(
            matiec::ErrorSeverity::Fatal,
            matiec::ErrorCategory::Internal,
            "Unhandled non-standard exception in stage4 IEC");
        return -1;
    }

    s4o.flush();
    return 0;
}
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

static bool result_add_output_file(matiec_result_t* result, const std::string& path) {
    if (!result) {
        return false;
    }

    char* copy = matiec_strdup(path.c_str());
    if (!copy) {
        return false;
    }

    const int next_index = result->output_file_count;
    char** new_list = static_cast<char**>(
        realloc(result->output_files, sizeof(char*) * static_cast<size_t>(next_index + 1)));
    if (!new_list) {
        free(copy);
        return false;
    }

    result->output_files = new_list;
    result->output_files[next_index] = copy;
    result->output_file_count = next_index + 1;
    return true;
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
        if (opts && opts->output_format == MATIEC_OUTPUT_IEC) {
            if (stage4_generate_iec_to_file(ordered_tree_root, builddir, input_file) < 0) {
                result_set_error_from_reporter(
                    result,
                    MATIEC_ERROR_CODEGEN,
                    "IEC code generation failed");
                ret = result->error_code;
                return ret;
            }

            (void)result_add_output_file(result, join_dir_file(builddir, path_stem(input_file) + ".iec"));
        } else {
            if (stage4(ordered_tree_root, const_cast<char*>(builddir)) < 0) {
                result_set_error_from_reporter(
                    result,
                    MATIEC_ERROR_CODEGEN,
                    "Code generation failed");
                ret = result->error_code;
                return ret;
            }
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
    (void)source_name; // reserved for future "virtual filename" support
    std::string temp_file_path;

#ifdef _WIN32
    std::vector<char> temp_path_buf(MAX_PATH);
    DWORD temp_path_len = GetTempPathA(static_cast<DWORD>(temp_path_buf.size()),
                                       temp_path_buf.data());
    if (temp_path_len == 0) {
        result_set_error(result, MATIEC_ERROR_IO, "Failed to get temporary directory");
        return MATIEC_ERROR_IO;
    }
    if (temp_path_len >= temp_path_buf.size()) {
        temp_path_buf.resize(static_cast<size_t>(temp_path_len) + 1);
        temp_path_len = GetTempPathA(static_cast<DWORD>(temp_path_buf.size()),
                                     temp_path_buf.data());
        if (temp_path_len == 0 || temp_path_len >= temp_path_buf.size()) {
            result_set_error(result, MATIEC_ERROR_IO, "Failed to get temporary directory");
            return MATIEC_ERROR_IO;
        }
    }

    // GetTempFileNameA() requires a buffer of at least MAX_PATH characters.
    std::vector<char> temp_file_buf(MAX_PATH);
    if (GetTempFileNameA(temp_path_buf.data(), "iec", 0, temp_file_buf.data()) == 0) {
        result_set_error(result, MATIEC_ERROR_IO, "Failed to create temporary file name");
        return MATIEC_ERROR_IO;
    }
    temp_file_path = temp_file_buf.data();
#else
    constexpr int kSuffixLen = 3; // ".st"
    std::error_code ec;
    std::filesystem::path temp_dir = std::filesystem::temp_directory_path(ec);
    if (ec) {
        temp_dir = "/tmp";
    }
    std::string temp_template_str = (temp_dir / "matiec_XXXXXX.st").string();
    std::vector<char> temp_template(temp_template_str.begin(), temp_template_str.end());
    temp_template.push_back('\0');

    int fd = mkstemps(temp_template.data(), kSuffixLen);
    if (fd < 0) {
        result_set_error(result, MATIEC_ERROR_IO, "Failed to create temporary file");
        return MATIEC_ERROR_IO;
    }
    close(fd);
    temp_file_path = temp_template.data();
#endif

    /* Write source to temp file */
    auto temp_guard = matiec::make_scope_exit([&]() noexcept {
        if (!temp_file_path.empty()) {
            std::remove(temp_file_path.c_str());
        }
    });

    matiec::unique_c_file f(std::fopen(temp_file_path.c_str(), "wb"));
    if (!f) {
        result_set_error(result, MATIEC_ERROR_IO, "Failed to write temporary file");
        return MATIEC_ERROR_IO;
    }
    if (std::fwrite(source, 1, source_len, f.get()) != source_len) {
        result_set_error(result, MATIEC_ERROR_IO, "Failed to write temporary file");
        return MATIEC_ERROR_IO;
    }
    f.reset(); // close before compiling

    /* Compile the temp file */
    matiec_error_t ret = matiec_compile_file(temp_file_path.c_str(), opts, result);
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
