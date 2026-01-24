/*
 *  Copyright (C) 2003-2011  Mario de Sousa (msousa@fe.up.pt)
 *  Copyright (C) 2007-2011  Laurent Bessard and Edouard Tisserant
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * This code is made available on the understanding that it will not be
 * used in safety-critical situations without a full and competent review.
 */

/*
 * An IEC 61131-3 compiler.
 *
 * Based on the
 * FINAL DRAFT - IEC 61131-3, 2nd Ed. (2001-12-10)
 *
 */


/*
 * This file contains the code that stores the output generated
 * by each specific version of the 4th stage.
 */






// #include <stdio.h>  /* required for NULL */
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdarg>
#include <cstdlib>
#include <cctype>
#include <exception>
#include <memory>

#include "stage4.hh"
#include "../main.hh" // required for ERROR() and ERROR_MSG() macros.
#include "matiec/error.hpp"
#include "matiec/format.hpp"




#define FIRST_(symbol1, symbol2) (((symbol1)->first_order < (symbol2)->first_order)   ? (symbol1) : (symbol2))
#define  LAST_(symbol1, symbol2) (((symbol1)->last_order  > (symbol2)->last_order)    ? (symbol1) : (symbol2))
#include <stdarg.h>

void stage4err(const char *stage4_generator_id, symbol_c *symbol1, symbol_c *symbol2, const char *errmsg, ...) {
    va_list argptr;
    va_start(argptr, errmsg); /* second argument is last fixed pamater of stage4err() */

    const std::string msg = matiec::vformat(errmsg, argptr);
    va_end(argptr);

    /* Bridge to ErrorReporter (for library/C API consumers). */
    std::optional<matiec::SourceLocation> loc = std::nullopt;
    if ((symbol1 != NULL) && (symbol2 != NULL) && (FIRST_(symbol1,symbol2)->first_file != NULL)) {
      matiec::SourceLocation sl;
      sl.filename = FIRST_(symbol1,symbol2)->first_file;
      sl.line = FIRST_(symbol1,symbol2)->first_line;
      sl.column = FIRST_(symbol1,symbol2)->first_column;
      if (sl.isValid()) {
        loc = sl;
      }
    }

    std::string full_msg;
    if (stage4_generator_id != NULL) {
      full_msg = std::string(stage4_generator_id) + ": " + msg;
    } else {
      full_msg = msg;
    }

    matiec::globalErrorReporter().report(
        matiec::ErrorSeverity::Error,
        matiec::ErrorCategory::CodeGen,
        std::move(full_msg),
        loc);

    if ((symbol1 != NULL) && (symbol2 != NULL))
      fprintf(stderr, "%s:%d-%d..%d-%d: ",
              FIRST_(symbol1,symbol2)->first_file, FIRST_(symbol1,symbol2)->first_line, FIRST_(symbol1,symbol2)->first_column,
                                                   LAST_(symbol1,symbol2) ->last_line,  LAST_(symbol1,symbol2) ->last_column);

    fprintf(stderr, "error %s: %s\n", stage4_generator_id, msg.c_str());
    // error_count++;
}



stage4out_c::stage4out_c(std::string indent_level):
  m_file(nullptr) {
  out = &std::cout;
  this->indent_level = indent_level;
  this->indent_spaces = "";
  allow_output = true;
}

stage4out_c::stage4out_c(const char *dir, const char *radix, const char *extension, std::string indent_level) {
  std::string filename(radix);
  filename += ".";
  filename += extension;
  std::string filepath("");
  if (dir != NULL) {
    filepath += dir;
    filepath += "/";
  }
  filepath += filename;
  auto file = std::make_unique<std::fstream>(filepath.c_str(), std::fstream::out);
  if(file->fail()){
    std::string msg = "Cannot open " + filepath + " for write access";    
    matiec::globalErrorReporter().report(
        matiec::ErrorSeverity::Error,
        matiec::ErrorCategory::IO,
        msg);
    throw stage4_codegen_error(msg);
  }else{
    std::cout << filename << "\n";
  }
  out = file.get();
  m_file = std::move(file);
  this->indent_level = indent_level;
  this->indent_spaces = "";
  allow_output = true;
}

stage4out_c::~stage4out_c(void) {
  if (m_file) {
    m_file->close();
  }
}

void stage4out_c::flush(void) {
  out->flush();
}

void stage4out_c::enable_output(void) {
  allow_output = true;
}
    
void stage4out_c::disable_output(void) {
  allow_output = false;
}

void stage4out_c::indent_right(void) {
  indent_spaces+=indent_level;
}

void stage4out_c::indent_left(void) {
  if (indent_spaces.length() >= indent_level.length())
    indent_spaces.erase(indent_spaces.length() - indent_level.length(), indent_level.length());
  else
    indent_spaces.erase();
}

void *stage4out_c::print(     std::string_view value) {
  if (!allow_output) return NULL;
  if (!value.empty())
    out->write(value.data(), static_cast<std::streamsize>(value.size()));
  return NULL;
}
void *stage4out_c::print(           const char *value) {if (!allow_output) return NULL; *out << value; return NULL;}
//void *stage4out_c::print(               int64_t value) {if (!allow_output) return NULL; *out << value; return NULL;}
//void *stage4out_c::print(              uint64_t value) {if (!allow_output) return NULL; *out << value; return NULL;}
void *stage4out_c::print(              real64_t value) {if (!allow_output) return NULL; *out << value; return NULL;}
void *stage4out_c::print(                   int value) {if (!allow_output) return NULL; *out << value; return NULL;}
void *stage4out_c::print(              long int value) {if (!allow_output) return NULL; *out << value; return NULL;}
void *stage4out_c::print(         long long int value) {if (!allow_output) return NULL; *out << value; return NULL;}
void *stage4out_c::print(unsigned           int value) {if (!allow_output) return NULL; *out << value; return NULL;}
void *stage4out_c::print(unsigned      long int value) {if (!allow_output) return NULL; *out << value; return NULL;}
void *stage4out_c::print(unsigned long long int value) {if (!allow_output) return NULL; *out << value; return NULL;}


void *stage4out_c::print_long_integer(unsigned long l_integer, bool suffix) {
  if (!allow_output) return NULL;
  *out << l_integer;
  if (suffix) *out << "UL";
  return NULL;
}

void *stage4out_c::print_long_long_integer(unsigned long long ll_integer, bool suffix) {
  if (!allow_output) return NULL;
  *out << ll_integer;
  if (suffix) *out << "ULL";
  return NULL;
}


void *stage4out_c::printupper(const char *str) {
  if (!allow_output) return NULL;
  for (int i = 0; str[i] != '\0'; i++)
    *out << static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
  return NULL;
}

void *stage4out_c::printlocation(const char *str) {
  if (!allow_output) return NULL;
  *out << "__";
  for (int i = 0; str[i] != '\0'; i++)
    if(str[i] == '.')
      *out << '_';
    else
      *out << static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
  return NULL;
}

void *stage4out_c::printlocation_comasep(const char *str) {
  if (!allow_output) return NULL;
  *out << static_cast<char>(std::toupper(static_cast<unsigned char>(str[0])));
  *out << ',';
  *out << static_cast<char>(std::toupper(static_cast<unsigned char>(str[1])));
  *out << ',';
  for (int i = 2; str[i] != '\0'; i++)
    if(str[i] == '.')
      *out << ',';
    else
      *out << static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
  return NULL;
}



void *stage4out_c::printupper(std::string_view str) {
  if (!allow_output) return NULL;
  for (char c : str)
    *out << static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
  return NULL;
}


void *stage4out_c::printlocation(std::string_view str) {
  if (!allow_output) return NULL;
  *out << "__";
  for (char c : str)
    *out << ((c == '.') ? '_' : static_cast<char>(std::toupper(static_cast<unsigned char>(c))));
  return NULL;
}


/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/



/* forward declarations... */
/* These functions will be implemented in generate_XXX.cc */
visitor_c *new_code_generator(stage4out_c *s4o, const char *builddir);
void delete_code_generator(visitor_c *code_generator);


int stage4(symbol_c *tree_root, const char *builddir) {
  stage4out_c s4o;
  struct generator_deleter {
    void operator()(visitor_c *p) const noexcept {
      if (p) delete_code_generator(p);
    }
  };

  std::unique_ptr<visitor_c, generator_deleter> generate_code(new_code_generator(&s4o, builddir));
  if (generate_code == NULL) {
    matiec::globalErrorReporter().report(
        matiec::ErrorSeverity::Fatal,
        matiec::ErrorCategory::Internal,
        "Failed to create stage4 code generator");
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
        std::string("Unhandled exception in stage4: ") + e.what());
    return -1;
  } catch (...) {
    matiec::globalErrorReporter().report(
        matiec::ErrorSeverity::Fatal,
        matiec::ErrorCategory::Internal,
        "Unhandled non-standard exception in stage4");
    return -1;
  }

  return 0;
}
