/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Copyright (C) 2026
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 */
/*
 * Small string utilities (C++17).
 *
 * Prefer these over platform-specific `strcasecmp/_stricmp` so comparisons are
 * consistent across the codebase.
 */

#ifndef MATIEC_STRING_UTILS_HPP
#define MATIEC_STRING_UTILS_HPP

#include <cctype>
#include <string_view>

namespace matiec {

[[nodiscard]] inline std::string_view sv_or_empty(const char* s) noexcept {
  return s ? std::string_view(s) : std::string_view();
}

[[nodiscard]] inline int icompare(std::string_view a, std::string_view b) {
  const size_t n = (a.size() < b.size()) ? a.size() : b.size();
  for (size_t i = 0; i < n; ++i) {
    const unsigned char ca = static_cast<unsigned char>(a[i]);
    const unsigned char cb = static_cast<unsigned char>(b[i]);
    const int ua = std::toupper(ca);
    const int ub = std::toupper(cb);
    if (ua != ub) return (ua < ub) ? -1 : 1;
  }

  if (a.size() == b.size()) return 0;
  return (a.size() < b.size()) ? -1 : 1;
}

[[nodiscard]] inline bool iequals(std::string_view a, std::string_view b) {
  return icompare(a, b) == 0;
}

[[nodiscard]] inline bool iequals(const char* a, const char* b) {
  return iequals(sv_or_empty(a), sv_or_empty(b));
}

[[nodiscard]] inline bool istarts_with(std::string_view s,
                                      std::string_view prefix) {
  if (prefix.size() > s.size()) return false;
  return iequals(s.substr(0, prefix.size()), prefix);
}

[[nodiscard]] inline bool istarts_with(const char* s, const char* prefix) {
  return istarts_with(sv_or_empty(s), sv_or_empty(prefix));
}

} // namespace matiec

#endif // MATIEC_STRING_UTILS_HPP

