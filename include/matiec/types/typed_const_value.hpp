/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 */

#ifndef MATIEC_TYPES_TYPED_CONST_VALUE_HPP
#define MATIEC_TYPES_TYPED_CONST_VALUE_HPP

#include <cstdint>
#include <memory>
#include <variant>

#include "matiec/types/type.hpp"

namespace matiec::types {

enum class ConstValueStatus : uint8_t {
    Undefined,
    NonConst,
    Overflow,
    Value
};

struct TypedConstValue {
    ConstValueStatus status = ConstValueStatus::Undefined;
    std::shared_ptr<const Type> type;
    std::variant<std::monostate, int64_t, uint64_t, double, bool> value;

    [[nodiscard]] bool isValid() const noexcept {
        return status == ConstValueStatus::Value;
    }
};

} // namespace matiec::types

#endif // MATIEC_TYPES_TYPED_CONST_VALUE_HPP
