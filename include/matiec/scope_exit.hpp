/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  C++17 scope guard utility for small RAII cleanups.
 *
 *  This header is intentionally tiny and dependency-light so it can be reused
 *  in both the CLI tools and the library implementation.
 */

#ifndef MATIEC_SCOPE_EXIT_HPP
#define MATIEC_SCOPE_EXIT_HPP

#include <type_traits>
#include <utility>

namespace matiec {

template <class F>
class scope_exit final {
public:
    explicit scope_exit(F&& f) noexcept(std::is_nothrow_move_constructible_v<F>)
        : func_(std::forward<F>(f)) {}

    scope_exit(const scope_exit&) = delete;
    scope_exit& operator=(const scope_exit&) = delete;

    scope_exit(scope_exit&& other) noexcept(std::is_nothrow_move_constructible_v<F>)
        : func_(std::move(other.func_)), active_(other.active_) {
        other.active_ = false;
    }

    ~scope_exit() noexcept(noexcept(std::declval<F&>()())) {
        if (active_) {
            func_();
        }
    }

    void release() noexcept { active_ = false; }

private:
    F func_;
    bool active_ = true;
};

template <class F>
[[nodiscard]] inline scope_exit<std::decay_t<F>> make_scope_exit(F&& f) {
    return scope_exit<std::decay_t<F>>(std::forward<F>(f));
}

} // namespace matiec

#endif

