/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 */

#ifndef MATIEC_TYPES_TYPE_INFERRER_HPP
#define MATIEC_TYPES_TYPE_INFERRER_HPP

#include <memory>

#include "matiec/ast/generated/ast_nodes.gen.hpp"
#include "matiec/types/type_registry.hpp"

namespace matiec::types {

class TypeInferrer {
public:
    explicit TypeInferrer(TypeRegistry& registry) : registry_(registry) {}

    [[nodiscard]] std::shared_ptr<const Type> inferType(const ast::Symbol& expr) const {
        if (dynamic_cast<const ast::integer_c*>(&expr) ||
            dynamic_cast<const ast::integer_literal_c*>(&expr)) {
            return registry_.getInt();
        }
        if (dynamic_cast<const ast::real_c*>(&expr) ||
            dynamic_cast<const ast::real_literal_c*>(&expr)) {
            return registry_.getReal();
        }
        if (dynamic_cast<const ast::boolean_true_c*>(&expr) ||
            dynamic_cast<const ast::boolean_false_c*>(&expr) ||
            dynamic_cast<const ast::boolean_literal_c*>(&expr)) {
            return registry_.getBool();
        }
        return {};
    }

private:
    TypeRegistry& registry_;
};

} // namespace matiec::types

#endif // MATIEC_TYPES_TYPE_INFERRER_HPP
