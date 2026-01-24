/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Unit tests for typed constant folding annotations.
 */

#include <variant>

#include <gtest/gtest.h>

#include "absyntax_utils/absyntax_utils.hh"
#include "matiec/types/typed_const_value.hpp"
#include "stage3/modern_semantic_annotations.hh"

TEST(ConstantFoldingTest, TypedConstValueUsesLegacyInt) {
    symbol_c symbol;
    symbol.datatype = &get_datatype_info_c::int_type_name;
    symbol.const_value.m_int64.set(42);

    matiec::stage3::populate_modern_annotations(&symbol);

    EXPECT_EQ(symbol.const_value_modern.status, matiec::types::ConstValueStatus::Value);
    EXPECT_EQ(std::get<int64_t>(symbol.const_value_modern.value), 42);
    ASSERT_NE(symbol.const_value_modern.type, nullptr);
    EXPECT_EQ(symbol.const_value_modern.type->name(), "INT");
}

TEST(ConstantFoldingTest, TypedConstValueTracksOverflow) {
    symbol_c symbol;
    symbol.datatype = &get_datatype_info_c::dint_type_name;
    symbol.const_value.m_int64.set_overflow();

    matiec::stage3::populate_modern_annotations(&symbol);

    EXPECT_EQ(symbol.const_value_modern.status, matiec::types::ConstValueStatus::Overflow);
}

TEST(ConstantFoldingTest, LinkerAnchorsRuntimeOptionsForStaticArchives) {
    // Ensure libmatiec object defining error_exit/runtime_options is linked.
    volatile bool anchor = runtime_options.relaxed_datatype_model;
    (void)anchor;
    SUCCEED();
}
