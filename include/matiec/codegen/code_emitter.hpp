/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 */

#ifndef MATIEC_CODEGEN_CODE_EMITTER_HPP
#define MATIEC_CODEGEN_CODE_EMITTER_HPP

#include <functional>
#include <ostream>
#include <string>
#include <string_view>

namespace matiec::codegen {

class CodeEmitter {
public:
    using WriteFn = std::function<void(std::string_view)>;
    using IndentFn = std::function<void()>;
    using DedentFn = std::function<void()>;
    using IndentPrefixFn = std::function<std::string_view()>;

    explicit CodeEmitter(std::ostream& output, std::string indent_unit = "  ")
        : output_(&output), indent_unit_(std::move(indent_unit)), use_callbacks_(false) {}

    CodeEmitter(WriteFn write, IndentFn indent, DedentFn dedent, IndentPrefixFn indent_prefix)
        : write_fn_(std::move(write)),
          indent_fn_(std::move(indent)),
          dedent_fn_(std::move(dedent)),
          indent_prefix_fn_(std::move(indent_prefix)),
          use_callbacks_(true) {}

    void write(std::string_view text) {
        if (use_callbacks_) {
            if (write_fn_) {
                write_fn_(text);
            }
            return;
        }
        if (!output_ || text.empty()) {
            return;
        }
        output_->write(text.data(), static_cast<std::streamsize>(text.size()));
    }

    void newline() {
        write("\n");
    }

    void writeIndent() {
        write(indentPrefix());
    }

    void writeLine(std::string_view text = "") {
        writeIndent();
        write(text);
        write("\n");
    }

    void indent() {
        if (use_callbacks_) {
            if (indent_fn_) {
                indent_fn_();
            }
            return;
        }
        ++indent_level_;
        indent_dirty_ = true;
    }

    void dedent() {
        if (use_callbacks_) {
            if (dedent_fn_) {
                dedent_fn_();
            }
            return;
        }
        if (indent_level_ == 0) {
            return;
        }
        --indent_level_;
        indent_dirty_ = true;
    }

    class IndentGuard {
    public:
        explicit IndentGuard(CodeEmitter& emitter) : emitter_(emitter) { emitter_.indent(); }
        ~IndentGuard() { emitter_.dedent(); }
        IndentGuard(const IndentGuard&) = delete;
        IndentGuard& operator=(const IndentGuard&) = delete;

    private:
        CodeEmitter& emitter_;
    };

    [[nodiscard]] IndentGuard indented() { return IndentGuard(*this); }

    template <typename Func>
    void block(std::string_view header, Func&& body) {
        std::string line(header);
        line.append(" {");
        writeLine(line);
        {
            auto guard = indented();
            std::forward<Func>(body)();
        }
        writeLine("}");
    }

    template <typename Func>
    void function(std::string_view return_type,
                  std::string_view name,
                  std::string_view params,
                  Func&& body) {
        std::string line;
        line.reserve(return_type.size() + name.size() + params.size() + 4);
        line.append(return_type);
        line.append(" ");
        line.append(name);
        line.append("(");
        line.append(params);
        line.append(") {");
        writeLine(line);
        {
            auto guard = indented();
            std::forward<Func>(body)();
        }
        writeLine("}");
        newline();
    }

    void lineComment(std::string_view text) {
        std::string line("// ");
        line.append(text);
        writeLine(line);
    }

private:
    std::string_view indentPrefix() {
        if (use_callbacks_) {
            if (indent_prefix_fn_) {
                return indent_prefix_fn_();
            }
            return {};
        }
        if (indent_dirty_) {
            indent_cache_.clear();
            for (size_t i = 0; i < indent_level_; ++i) {
                indent_cache_.append(indent_unit_);
            }
            indent_dirty_ = false;
        }
        return indent_cache_;
    }

    std::ostream* output_ = nullptr;
    std::string indent_unit_;
    size_t indent_level_ = 0;
    bool indent_dirty_ = true;
    std::string indent_cache_;

    WriteFn write_fn_;
    IndentFn indent_fn_;
    DedentFn dedent_fn_;
    IndentPrefixFn indent_prefix_fn_;
    bool use_callbacks_ = false;
};

} // namespace matiec::codegen

#endif // MATIEC_CODEGEN_CODE_EMITTER_HPP
