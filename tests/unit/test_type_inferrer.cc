/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Unit tests for the type inferrer and legacy bridge.
 */

#include <gtest/gtest.h>

#include "main.hh"
#include "matiec/types/type_inferrer.hpp"
#include "stage3/modern_types_bridge.hh"

TEST(TypeInferrerTest, InfersIntegerLiteral) {
    matiec::types::TypeRegistry registry;
    matiec::types::TypeInferrer inferrer(registry);

    matiec::ast::integer_c literal("123");
    const auto inferred = inferrer.inferType(literal);

    ASSERT_NE(inferred, nullptr);
    EXPECT_EQ(inferred->name(), "INT");
}

TEST(TypeInferrerTest, InfersBooleanLiteral) {
    matiec::types::TypeRegistry registry;
    matiec::types::TypeInferrer inferrer(registry);

    matiec::ast::boolean_true_c literal;
    const auto inferred = inferrer.inferType(literal);

    ASSERT_NE(inferred, nullptr);
    EXPECT_EQ(inferred->name(), "BOOL");
}

TEST(TypeInferrerTest, LinkerAnchorsRuntimeOptionsForStaticArchives) {
    // Ensure libmatiec object defining error_exit/runtime_options is linked.
    volatile bool anchor = runtime_options.relaxed_datatype_model;
    (void)anchor;
    SUCCEED();
}

TEST(LegacyTypeBridgeTest, InfersLegacyIntegerLiteral) {
    matiec::types::TypeRegistry registry;
    ::integer_c legacy_literal("42");

    const auto inferred = matiec::stage3::infer_legacy_literal_type(legacy_literal, registry);

    ASSERT_NE(inferred, nullptr);
    EXPECT_EQ(inferred->name(), "INT");
}
