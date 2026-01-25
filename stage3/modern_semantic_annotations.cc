/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 */

#include "modern_semantic_annotations.hh"

#include <algorithm>
#include <string_view>

#include "absyntax_utils/absyntax_utils.hh"
#include "matiec/types/type_registry.hpp"

namespace {

matiec::types::TypeRegistry& legacy_type_registry() {
    static matiec::types::TypeRegistry registry;
    return registry;
}

bool is_safe_type_name(std::string_view name) {
    return name.rfind("SAFE", 0) == 0;
}

std::string_view normalize_legacy_name(std::string_view name) {
    if (name == "TOD") {
        return "TIME_OF_DAY";
    }
    if (name == "DT") {
        return "DATE_AND_TIME";
    }
    return name;
}

void assign_status_from_legacy(const_value_c& legacy,
                               matiec::types::TypedConstValue& out,
                               matiec::types::TypeCategory category) {
    using matiec::types::ConstValueStatus;
    using matiec::types::TypeCategory;

    auto assign_from = [&](auto& legacy_value, auto value) {
        if (legacy_value.is_valid()) {
            out.status = ConstValueStatus::Value;
            out.value = value;
        } else if (legacy_value.is_overflow()) {
            out.status = ConstValueStatus::Overflow;
        } else if (legacy_value.is_nonconst()) {
            out.status = ConstValueStatus::NonConst;
        } else {
            out.status = ConstValueStatus::Undefined;
        }
    };

    switch (category) {
        case TypeCategory::Bool:
            assign_from(legacy.m_bool, legacy.m_bool.get());
            return;
        case TypeCategory::Byte:
        case TypeCategory::Word:
        case TypeCategory::DWord:
        case TypeCategory::LWord:
        case TypeCategory::USInt:
        case TypeCategory::UInt:
        case TypeCategory::UDInt:
        case TypeCategory::ULInt:
            assign_from(legacy.m_uint64, legacy.m_uint64.get());
            return;
        case TypeCategory::SInt:
        case TypeCategory::Int:
        case TypeCategory::DInt:
        case TypeCategory::LInt:
        case TypeCategory::Time:
        case TypeCategory::Date:
        case TypeCategory::TimeOfDay:
        case TypeCategory::DateAndTime:
            assign_from(legacy.m_int64, legacy.m_int64.get());
            return;
        case TypeCategory::Real:
        case TypeCategory::LReal:
            assign_from(legacy.m_real64, static_cast<double>(legacy.m_real64.get()));
            return;
        default:
            out.status = ConstValueStatus::Undefined;
            return;
    }
}

matiec::types::TypedConstValue typed_const_value_from_legacy(
    const_value_c& legacy,
    const std::shared_ptr<const matiec::types::Type>& type) {
    matiec::types::TypedConstValue out;
    out.type = type;
    out.value = std::monostate{};
    if (!type) {
        return out;
    }
    assign_status_from_legacy(legacy, out, type->category());
    return out;
}

bool contains_type(const std::vector<std::shared_ptr<const matiec::types::Type>>& types,
                   const std::shared_ptr<const matiec::types::Type>& type) {
    return std::any_of(types.begin(), types.end(),
                       [&](const auto& entry) { return entry == type; });
}

} // namespace

namespace matiec::stage3 {

std::shared_ptr<const types::Type> resolve_legacy_type(symbol_c *type_symbol) {
    if (!get_datatype_info_c::is_type_valid(type_symbol)) {
        return {};
    }
    symbol_c *type_id = get_datatype_info_c::get_id(type_symbol);
    if (!type_id) {
        return {};
    }
    const char* name = get_datatype_info_c::get_id_str(type_id);
    if (!name) {
        return {};
    }
    std::string_view view(name);
    if (is_safe_type_name(view)) {
        return {};
    }
    view = normalize_legacy_name(view);
    return legacy_type_registry().findType(view);
}

void populate_modern_annotations(symbol_c *symbol) {
    if (!symbol) {
        return;
    }

    symbol->candidate_types.clear();
    for (auto* legacy_type : symbol->candidate_datatypes) {
        auto modern_type = resolve_legacy_type(legacy_type);
        if (!modern_type || contains_type(symbol->candidate_types, modern_type)) {
            continue;
        }
        symbol->candidate_types.push_back(std::move(modern_type));
    }

    symbol->datatype_modern = resolve_legacy_type(symbol->datatype);
    if (symbol->datatype_modern) {
        symbol->candidate_types.erase(
            std::remove_if(symbol->candidate_types.begin(),
                           symbol->candidate_types.end(),
                           [&](const auto& candidate) {
                               return !candidate ||
                                      !candidate->isAssignableTo(*symbol->datatype_modern);
                           }),
            symbol->candidate_types.end());
        symbol->const_value_modern =
            typed_const_value_from_legacy(symbol->const_value, symbol->datatype_modern);
    } else {
        symbol->const_value_modern = types::TypedConstValue{};
    }
}

void modern_semantic_annotations_c::prefix_fcall(symbol_c *symbol) {
    populate_modern_annotations(symbol);
}

} // namespace matiec::stage3
