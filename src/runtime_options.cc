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
#include <cstdio>
#include <cstdlib>
#include <cstdarg>

/* Define the global runtime_options variable */
runtime_options_t runtime_options;

/* error_exit function - called on internal compiler errors */
void error_exit(const char *file_name, int line_no, const char *errmsg, ...) {
    va_list argptr;
    va_start(argptr, errmsg);

    fprintf(stderr, "\nInternal compiler error in file %s at line %d", file_name, line_no);
    if (errmsg != NULL) {
        fprintf(stderr, ": ");
        vfprintf(stderr, errmsg, argptr);
    } else {
        fprintf(stderr, ".");
    }
    fprintf(stderr, "\n");
    va_end(argptr);

    exit(EXIT_FAILURE);
}
