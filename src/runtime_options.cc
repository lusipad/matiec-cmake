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
 * @file runtime_options.cc
 * @brief Definition of runtime_options global variable and error_exit function
 *
 * This file is separate from main.cc to allow the library to be linked
 * without including the main() function, which would conflict with
 * test frameworks like GoogleTest.
 */

#include "main.hh"
#include "matiec/error.hpp"
#include <cstdio>
#include <cstdarg>
#include <vector>

/* Define the global runtime_options variable */
runtime_options_t runtime_options;

/* error_exit function - called on internal compiler errors */
void error_exit(const char *file_name, int line_no, const char *errmsg, ...) {  
    va_list argptr;
    va_start(argptr, errmsg);

    std::string message;
    if (errmsg != nullptr) {
        va_list argptr_copy;
        va_copy(argptr_copy, argptr);
        const int required = std::vsnprintf(nullptr, 0, errmsg, argptr_copy);
        va_end(argptr_copy);

        if (required >= 0) {
            std::vector<char> buffer(static_cast<size_t>(required) + 1);
            std::vsnprintf(buffer.data(), buffer.size(), errmsg, argptr);
            message.assign(buffer.data(), static_cast<size_t>(required));
        } else {
            message = errmsg;
        }
    }

    va_end(argptr);

    matiec::globalErrorReporter().reportInternalError(
        std::move(message), file_name, line_no);
}
