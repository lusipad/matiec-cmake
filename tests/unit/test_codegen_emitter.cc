/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Unit tests for CodeEmitter.
 */

#include <gtest/gtest.h>

#include <sstream>
#include <string>

#include "matiec/codegen/code_emitter.hpp"

TEST(CodeEmitterTest, WritesIndentedLines) {
    std::ostringstream out;
    matiec::codegen::CodeEmitter emitter(out);

    emitter.writeLine("line1");
    emitter.indent();
    emitter.writeLine("line2");
    emitter.dedent();
    emitter.writeLine("line3");

    EXPECT_EQ(out.str(), "line1\n  line2\nline3\n");
}

TEST(CodeEmitterTest, BlockHelperUsesIndent) {
    std::ostringstream out;
    matiec::codegen::CodeEmitter emitter(out);

    emitter.block("if (ready)", [&] { emitter.writeLine("do_work();"); });

    EXPECT_EQ(out.str(), "if (ready) {\n  do_work();\n}\n");
}

TEST(CodeEmitterTest, CallbackConstructorUsesIndentProvider) {
    std::string buffer;
    std::string indent;
    matiec::codegen::CodeEmitter emitter(
        [&buffer](std::string_view text) { buffer.append(text); },
        [&indent]() { indent.append("  "); },
        [&indent]() {
            if (indent.size() >= 2) {
                indent.resize(indent.size() - 2);
            }
        },
        [&indent]() -> std::string_view { return indent; });

    emitter.writeLine("root");
    emitter.indent();
    emitter.writeLine("child");
    emitter.dedent();
    emitter.writeLine("tail");

    EXPECT_EQ(buffer, "root\n  child\ntail\n");
}
