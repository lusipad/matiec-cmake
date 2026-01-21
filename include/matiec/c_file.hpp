/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Small FILE* RAII helpers.
 */

#ifndef MATIEC_C_FILE_HPP
#define MATIEC_C_FILE_HPP

#include <cstdio>
#include <memory>

namespace matiec {

struct c_file_closer {
    void operator()(FILE* f) const noexcept {
        if (f) {
            std::fclose(f);
        }
    }
};

using unique_c_file = std::unique_ptr<FILE, c_file_closer>;

} // namespace matiec

#endif

