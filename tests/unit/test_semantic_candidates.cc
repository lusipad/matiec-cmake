/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Unit tests for modern semantic candidate annotations.
 */

#include <algorithm>

#include <gtest/gtest.h>

#include "absyntax_utils/absyntax_utils.hh"
#include "stage3/modern_semantic_annotations.hh"

namespace {

bool has_type(const std::vector<std::shared_ptr<const matiec::types::Type>>& types,
              std::string_view name) {
    return std::any_of(types.begin(), types.end(), [&](const auto& type) {
        return type && type->name() == name;
    });
}

} // namespace

TEST(SemanticCandidatesTest, FiltersIncompatibleCandidates) {
    symbol_c symbol;
    symbol.candidate_datatypes.push_back(&get_datatype_info_c::int_type_name);
    symbol.candidate_datatypes.push_back(&get_datatype_info_c::dint_type_name);
    symbol.candidate_datatypes.push_back(&get_datatype_info_c::bool_type_name);
    symbol.datatype = &get_datatype_info_c::dint_type_name;

    matiec::stage3::populate_modern_annotations(&symbol);

    ASSERT_NE(symbol.datatype_modern, nullptr);
    EXPECT_EQ(symbol.datatype_modern->name(), "DINT");

    EXPECT_TRUE(has_type(symbol.candidate_types, "INT"));
    EXPECT_TRUE(has_type(symbol.candidate_types, "DINT"));
    EXPECT_FALSE(has_type(symbol.candidate_types, "BOOL"));
}

TEST(SemanticCandidatesTest, LinkerAnchorsRuntimeOptionsForStaticArchives) {
    // Ensure libmatiec object defining error_exit/runtime_options is linked.
    volatile bool anchor = runtime_options.relaxed_datatype_model;
    (void)anchor;
    SUCCEED();
}
