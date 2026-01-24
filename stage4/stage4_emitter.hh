/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 */

#ifndef MATIEC_STAGE4_EMITTER_HH
#define MATIEC_STAGE4_EMITTER_HH

#include "stage4.hh"
#include "matiec/codegen/code_emitter.hpp"

namespace matiec::codegen {

inline CodeEmitter make_stage4_emitter(stage4out_c& out) {
    return CodeEmitter(
        [&out](std::string_view text) { out.print(text); },
        [&out]() { out.indent_right(); },
        [&out]() { out.indent_left(); },
        [&out]() -> std::string_view { return out.indent_spaces; });
}

} // namespace matiec::codegen

#endif // MATIEC_STAGE4_EMITTER_HH
