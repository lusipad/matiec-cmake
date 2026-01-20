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

/*
 * Small printf-style formatting helpers.
 *
 * These are used to bridge legacy diagnostics (printf/fprintf + ...) to
 * modern `std::string`-based APIs without fixed-size buffers.
 */

#ifndef MATIEC_FORMAT_HPP
#define MATIEC_FORMAT_HPP

#include <cstdarg>
#include <cstdio>
#include <string>
#include <vector>

namespace matiec {

[[nodiscard]] inline std::string vformat(const char* fmt, va_list args) {       
  if (fmt == nullptr) return {};

  va_list args_copy;
  va_copy(args_copy, args);
  const int required = std::vsnprintf(nullptr, 0, fmt, args_copy);
  va_end(args_copy);

  if (required < 0) {
    // Fall back to the raw format string on encoding/format errors.
    return std::string(fmt);
  }

  std::vector<char> buffer(static_cast<size_t>(required) + 1);
  // Use a copy for the actual formatting too. On some platforms `va_list` is an
  // array type and passing it "by value" to another function effectively passes
  // it by reference, so we avoid consuming/modifying the caller's `va_list`.
  va_list args_copy2;
  va_copy(args_copy2, args);
  std::vsnprintf(buffer.data(), buffer.size(), fmt, args_copy2);
  va_end(args_copy2);
  return std::string(buffer.data(), static_cast<size_t>(required));
}

[[nodiscard]] inline std::string format(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  std::string result = vformat(fmt, args);
  va_end(args);
  return result;
}

} // namespace matiec

#endif // MATIEC_FORMAT_HPP
