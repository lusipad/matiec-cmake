/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Unit tests for the modern type registry.
 */

#include <gtest/gtest.h>

#include "matiec/types/type_registry.hpp"

TEST(TypeRegistryTest, LookupRegisteredType) {
    matiec::types::TypeRegistry registry;

    auto custom = std::make_shared<matiec::types::StructType>(
        "MyType", std::vector<matiec::types::StructType::Field>{});
    registry.registerType("MyType", custom);

    const auto found = registry.findType("mytype");
    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->name(), "MyType");
}

TEST(TypeRegistryTest, IntegerAssignability) {
    matiec::types::TypeRegistry registry;

    auto int_type = registry.getInt();
    auto dint_type = registry.getDInt();
    ASSERT_NE(int_type, nullptr);
    ASSERT_NE(dint_type, nullptr);

    EXPECT_TRUE(int_type->isAssignableTo(*dint_type));
    EXPECT_FALSE(dint_type->isAssignableTo(*int_type));
}
