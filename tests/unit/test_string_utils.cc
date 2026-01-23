/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Unit tests for small string utilities and legacy string boundaries.
 */

#include "gtest/gtest.h"

#include "matiec/string_utils.hpp"

#include "absyntax/absyntax.hh"

TEST(StringUtilsTest, SvOrEmptyHandlesNull) {
    const std::string_view empty = matiec::sv_or_empty(nullptr);
    EXPECT_TRUE(empty.empty());

    const std::string_view non_empty = matiec::sv_or_empty("abc");
    EXPECT_EQ(non_empty, "abc");
}

TEST(StringUtilsTest, IEqualsIsCaseInsensitive) {
    EXPECT_TRUE(matiec::iequals("abc", "ABC"));
    EXPECT_TRUE(matiec::iequals("AbC", "aBc"));
    EXPECT_FALSE(matiec::iequals("abc", "abcd"));
    EXPECT_FALSE(matiec::iequals("abc", "abx"));
}

TEST(StringUtilsTest, NoCaseComparatorIsNullSafe) {
    nocasecmp_c cmp;
    EXPECT_FALSE(cmp(nullptr, nullptr));
    EXPECT_TRUE(cmp(nullptr, "A")); // empty < "A"
    EXPECT_FALSE(cmp("A", nullptr));
}

TEST(AbsyntaxListCTest, FindElementIsCaseInsensitive) {
    token_c foo("Foo");
    token_c bar("Bar");

    list_c list;
    list.add_element(&foo, foo.value.c_str());
    list.add_element(&bar, bar.value.c_str());

    EXPECT_EQ(list.find_element("foo"), &foo);
    EXPECT_EQ(list.find_element("BAR"), &bar);
    EXPECT_EQ(list.find_element("baz"), nullptr);
}

