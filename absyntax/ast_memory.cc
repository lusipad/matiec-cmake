/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Memory management helpers for the AST and lexer-owned strings.
 *
 *  The upstream project historically relied on process termination to reclaim
 *  memory. In a library/test environment we need to free per-compilation state.
 */

#include "absyntax.hh"
#include "visitor.hh"

#include <cstdlib>
#include <cstring>
#include <unordered_set>
#include <vector>

namespace {

// Track heap-allocated AST nodes (symbol_c and all derived types).
// This lets us avoid deleting static/singleton symbol objects that are referenced
// from annotations (e.g. get_datatype_info_c::invalid_type_name).
std::unordered_set<void*>& heap_symbols() {
    static std::unordered_set<void*> symbols;
    return symbols;
}

bool is_heap_symbol(const symbol_c* symbol) {
    if (!symbol) return false;
    return heap_symbols().find(const_cast<symbol_c*>(symbol)) != heap_symbols().end();
}

// Pool of C strings that must remain valid during a compilation (token values and
// filenames produced by the lexer/parser). Cleared explicitly at compile end.
std::vector<char*>& cstr_pool() {
    static std::vector<char*> pool;
    return pool;
}

// Visitor that pushes syntax children (SYM_REF*, SYM_LIST) onto a work stack.
// Non-syntax edges (annotations) are handled generically in the traversal loop.
class child_pusher_visitor final : public visitor_c {
public:
    explicit child_pusher_visitor(std::vector<symbol_c*>& stack) : stack_(stack) {}

private:
    std::vector<symbol_c*>& stack_;

    void push(symbol_c* s) {
        if (s) stack_.push_back(s);
    }

    void* visit_list(list_c* list) {
        if (!list) return nullptr;
        for (int i = 0; i < list->n; ++i) {
            push(list->get_element(i));
        }
        return nullptr;
    }

public:
#define SYM_LIST(class_name_c, ...) \
    void* visit(class_name_c* symbol) override { return visit_list(symbol); }
#define SYM_TOKEN(class_name_c, ...) \
    void* visit(class_name_c* /*symbol*/) override { return nullptr; }
#define SYM_REF0(class_name_c, ...) \
    void* visit(class_name_c* /*symbol*/) override { return nullptr; }
#define SYM_REF1(class_name_c, ref1, ...) \
    void* visit(class_name_c* symbol) override { push(symbol->ref1); return nullptr; }
#define SYM_REF2(class_name_c, ref1, ref2, ...) \
    void* visit(class_name_c* symbol) override { push(symbol->ref1); push(symbol->ref2); return nullptr; }
#define SYM_REF3(class_name_c, ref1, ref2, ref3, ...) \
    void* visit(class_name_c* symbol) override { push(symbol->ref1); push(symbol->ref2); push(symbol->ref3); return nullptr; }
#define SYM_REF4(class_name_c, ref1, ref2, ref3, ref4, ...) \
    void* visit(class_name_c* symbol) override { push(symbol->ref1); push(symbol->ref2); push(symbol->ref3); push(symbol->ref4); return nullptr; }
#define SYM_REF5(class_name_c, ref1, ref2, ref3, ref4, ref5, ...) \
    void* visit(class_name_c* symbol) override { push(symbol->ref1); push(symbol->ref2); push(symbol->ref3); push(symbol->ref4); push(symbol->ref5); return nullptr; }
#define SYM_REF6(class_name_c, ref1, ref2, ref3, ref4, ref5, ref6, ...) \
    void* visit(class_name_c* symbol) override { push(symbol->ref1); push(symbol->ref2); push(symbol->ref3); push(symbol->ref4); push(symbol->ref5); push(symbol->ref6); return nullptr; }

#include "generated/ast_child_pusher_visitor_methods.gen.inc"

#undef SYM_LIST
#undef SYM_TOKEN
#undef SYM_REF0
#undef SYM_REF1
#undef SYM_REF2
#undef SYM_REF3
#undef SYM_REF4
#undef SYM_REF5
#undef SYM_REF6
};

void push_annotation_edges(symbol_c* symbol, std::vector<symbol_c*>& stack) {
    if (!symbol) return;

    // token points to a token_c identifying this symbol (often a child, but not always)
    if (symbol->token) stack.push_back(symbol->token);
    if (symbol->datatype) stack.push_back(symbol->datatype);
    if (symbol->scope) stack.push_back(symbol->scope);

    for (symbol_c* dt : symbol->candidate_datatypes) {
        if (dt) stack.push_back(dt);
    }

    for (const auto& kv : symbol->anotations_map) {
        if (kv.second) stack.push_back(kv.second);
    }
}

void ast_delete_impl(const std::vector<symbol_c*>& roots) noexcept {
    if (roots.empty()) return;

    std::vector<symbol_c*> stack;
    stack.reserve(1024);
    for (auto* r : roots) {
        if (r) stack.push_back(r);
    }
    if (stack.empty()) return;

    std::unordered_set<symbol_c*> visited;
    visited.reserve(4096);

    std::vector<symbol_c*> to_delete;
    to_delete.reserve(4096);

    child_pusher_visitor pusher(stack);

    while (!stack.empty()) {
        symbol_c* node = stack.back();
        stack.pop_back();
        if (!node) continue;

        if (!visited.insert(node).second) {
            continue; // already processed
        }

        // Collect first; delete in a second pass so we never dereference freed nodes.
        if (is_heap_symbol(node)) {
            to_delete.push_back(node);
        }

        push_annotation_edges(node, stack);
        node->accept(pusher); // pushes syntax children
    }

    // Delete in reverse order to reduce the chances of order-dependent destructors.
    for (auto it = to_delete.rbegin(); it != to_delete.rend(); ++it) {
        delete *it;
    }
}

} // namespace

/* -------------------------------------------------------------------------- */
/* symbol_c heap tracking                                                     */
/* -------------------------------------------------------------------------- */

void* symbol_c::operator new(std::size_t size) {
    void* ptr = ::operator new(size);
    heap_symbols().insert(ptr);
    return ptr;
}

void symbol_c::operator delete(void* ptr) noexcept {
    if (ptr) {
        heap_symbols().erase(ptr);
    }
    ::operator delete(ptr);
}

/* -------------------------------------------------------------------------- */
/* list_c owned storage                                                      */
/* -------------------------------------------------------------------------- */

list_c::~list_c(void) {
    // list_c does not own the pointed-to symbols, but it does own its internal array.
    if (elements) {
        std::free(elements);
        elements = nullptr;
    }
    c = 0;
    n = 0;
}

/* -------------------------------------------------------------------------- */
/* matiec helpers exposed via absyntax.hh                                      */
/* -------------------------------------------------------------------------- */

namespace matiec {

char* cstr_pool_strdup(const char* s) {
    if (!s) return nullptr;
#ifdef _WIN32
    char* dup = _strdup(s);
#else
    char* dup = ::strdup(s);
#endif
    if (!dup) return nullptr;
    cstr_pool().push_back(dup);
    return dup;
}

char* cstr_pool_take(char* s) {
    if (!s) return nullptr;
    cstr_pool().push_back(s);
    return s;
}

void cstr_pool_clear() noexcept {
    auto& pool = cstr_pool();
    for (char* s : pool) {
        std::free(s);
    }
    pool.clear();
}

void ast_delete(symbol_c* root) noexcept {
    ast_delete_impl({root});
}

void ast_delete(symbol_c* root1, symbol_c* root2) noexcept {
    ast_delete_impl({root1, root2});
}

} // namespace matiec
