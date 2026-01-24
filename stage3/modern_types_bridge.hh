/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 */

#ifndef MATIEC_STAGE3_MODERN_TYPES_BRIDGE_HH
#define MATIEC_STAGE3_MODERN_TYPES_BRIDGE_HH

#include "absyntax/absyntax.hh"
#include "matiec/types/type_registry.hpp"

namespace matiec::stage3 {

inline std::shared_ptr<const types::Type> infer_legacy_literal_type(
    const symbol_c& symbol,
    types::TypeRegistry& registry) {
    if (dynamic_cast<const integer_c*>(&symbol) ||
        dynamic_cast<const integer_literal_c*>(&symbol)) {
        return registry.getInt();
    }
    if (dynamic_cast<const real_c*>(&symbol) ||
        dynamic_cast<const real_literal_c*>(&symbol)) {
        return registry.getReal();
    }
    if (dynamic_cast<const boolean_true_c*>(&symbol) ||
        dynamic_cast<const boolean_false_c*>(&symbol) ||
        dynamic_cast<const boolean_literal_c*>(&symbol)) {
        return registry.getBool();
    }
    return {};
}

} // namespace matiec::stage3

#endif // MATIEC_STAGE3_MODERN_TYPES_BRIDGE_HH
