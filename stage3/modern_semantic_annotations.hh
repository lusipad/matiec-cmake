/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 */

#ifndef MATIEC_STAGE3_MODERN_SEMANTIC_ANNOTATIONS_HH
#define MATIEC_STAGE3_MODERN_SEMANTIC_ANNOTATIONS_HH

#include <memory>

#include "absyntax/visitor.hh"
#include "matiec/types/type.hpp"

namespace matiec::stage3 {

std::shared_ptr<const types::Type> resolve_legacy_type(symbol_c *type_symbol);
void populate_modern_annotations(symbol_c *symbol);

class modern_semantic_annotations_c : public fcall_iterator_visitor_c {
public:
    void prefix_fcall(symbol_c *symbol) override;
};

} // namespace matiec::stage3

#endif // MATIEC_STAGE3_MODERN_SEMANTIC_ANNOTATIONS_HH
