#!/usr/bin/env python3
from __future__ import annotations

import argparse
from dataclasses import dataclass
from pathlib import Path


@dataclass(frozen=True)
class SymEntry:
    kind: str  # LIST, TOKEN, REF0..REF6
    class_name: str
    refs: tuple[str, ...]
    varargs: tuple[str, ...]


def _scan_matching_paren(text: str, open_paren_index: int) -> int:
    """Return the index of the matching ')' for the '(' at open_paren_index."""
    if text[open_paren_index] != "(":
        raise ValueError("expected '(' at open_paren_index")

    depth = 0
    in_block_comment = False
    in_line_comment = False
    in_string = False
    in_char = False
    escape = False

    i = open_paren_index
    while i < len(text):
        ch = text[i]
        nxt = text[i + 1] if i + 1 < len(text) else ""

        if in_line_comment:
            if ch == "\n":
                in_line_comment = False
            i += 1
            continue

        if in_block_comment:
            if ch == "*" and nxt == "/":
                in_block_comment = False
                i += 2
                continue
            if ch == "\n":
                at_line_start = True
            else:
                at_line_start = False
            i += 1
            continue

        if in_string:
            if escape:
                escape = False
            elif ch == "\\":
                escape = True
            elif ch == '"':
                in_string = False
            i += 1
            continue

        if in_char:
            if escape:
                escape = False
            elif ch == "\\":
                escape = True
            elif ch == "'":
                in_char = False
            i += 1
            continue

        if ch == "/" and nxt == "/":
            in_line_comment = True
            i += 2
            continue

        if ch == "/" and nxt == "*":
            in_block_comment = True
            i += 2
            continue

        if ch == '"':
            in_string = True
            i += 1
            continue

        if ch == "'":
            in_char = True
            i += 1
            continue

        if ch == "(":
            depth += 1
        elif ch == ")":
            depth -= 1
            if depth == 0:
                return i

        i += 1

    raise ValueError("unbalanced parentheses while scanning absyntax.def")


def _split_top_level_commas(arg_text: str) -> list[str]:
    parts: list[str] = []
    buf: list[str] = []

    paren = 0
    brace = 0
    bracket = 0
    in_block_comment = False
    in_line_comment = False
    in_string = False
    in_char = False
    escape = False

    i = 0
    while i < len(arg_text):
        ch = arg_text[i]
        nxt = arg_text[i + 1] if i + 1 < len(arg_text) else ""

        if in_line_comment:
            buf.append(ch)
            if ch == "\n":
                in_line_comment = False
            i += 1
            continue

        if in_block_comment:
            buf.append(ch)
            if ch == "*" and nxt == "/":
                buf.append(nxt)
                in_block_comment = False
                i += 2
                continue
            i += 1
            continue

        if in_string:
            buf.append(ch)
            if escape:
                escape = False
            elif ch == "\\":
                escape = True
            elif ch == '"':
                in_string = False
            i += 1
            continue

        if in_char:
            buf.append(ch)
            if escape:
                escape = False
            elif ch == "\\":
                escape = True
            elif ch == "'":
                in_char = False
            i += 1
            continue

        if ch == "/" and nxt == "/":
            buf.append(ch)
            buf.append(nxt)
            in_line_comment = True
            i += 2
            continue

        if ch == "/" and nxt == "*":
            buf.append(ch)
            buf.append(nxt)
            in_block_comment = True
            i += 2
            continue

        if ch == '"':
            buf.append(ch)
            in_string = True
            i += 1
            continue

        if ch == "'":
            buf.append(ch)
            in_char = True
            i += 1
            continue

        if ch == "(":
            paren += 1
        elif ch == ")":
            paren -= 1
        elif ch == "{":
            brace += 1
        elif ch == "}":
            brace -= 1
        elif ch == "[":
            bracket += 1
        elif ch == "]":
            bracket -= 1

        if ch == "," and paren == 0 and brace == 0 and bracket == 0:
            part = "".join(buf).strip()
            parts.append(part)
            buf.clear()
            i += 1
            continue

        buf.append(ch)
        i += 1

    tail = "".join(buf).strip()
    if tail:
        parts.append(tail)
    else:
        # Allow trailing commas (shouldn't happen in this file, but be defensive)
        if parts and arg_text.rstrip().endswith(","):
            parts.append("")

    return parts


def parse_absyntax_def(text: str) -> list[SymEntry]:
    entries: list[SymEntry] = []

    i = 0
    in_block_comment = False
    in_line_comment = False
    in_string = False
    in_char = False
    escape = False
    at_line_start = True

    def skip_ws(idx: int) -> int:
        while idx < len(text) and text[idx] in (" ", "\t"):
            idx += 1
        return idx

    while i < len(text):
        ch = text[i]
        nxt = text[i + 1] if i + 1 < len(text) else ""

        if in_line_comment:
            if ch == "\n":
                in_line_comment = False
                at_line_start = True
            i += 1
            continue

        if in_block_comment:
            if ch == "*" and nxt == "/":
                in_block_comment = False
                i += 2
                continue
            i += 1
            continue

        if in_string:
            if escape:
                escape = False
            elif ch == "\\":
                escape = True
            elif ch == '"':
                in_string = False
            if ch == "\n":
                at_line_start = True
            else:
                at_line_start = False
            i += 1
            continue

        if in_char:
            if escape:
                escape = False
            elif ch == "\\":
                escape = True
            elif ch == "'":
                in_char = False
            if ch == "\n":
                at_line_start = True
            else:
                at_line_start = False
            i += 1
            continue

        if ch == "/" and nxt == "/":
            in_line_comment = True
            i += 2
            continue

        if ch == "/" and nxt == "*":
            in_block_comment = True
            i += 2
            continue

        if ch == '"':
            in_string = True
            i += 1
            continue

        if ch == "'":
            in_char = True
            i += 1
            continue

        if at_line_start:
            j = skip_ws(i)
            if text.startswith("SYM_", j):
                # Parse macro name (identifier up to '(').
                k = j
                while k < len(text) and (text[k].isalnum() or text[k] == "_"):
                    k += 1
                macro = text[j:k]

                k = skip_ws(k)
                if k >= len(text) or text[k] != "(":
                    raise ValueError(f"malformed {macro} invocation near index {j}")

                close_idx = _scan_matching_paren(text, k)
                args_text = text[k + 1 : close_idx]
                args = _split_top_level_commas(args_text)

                if not args:
                    raise ValueError(f"{macro} has no arguments")

                class_name = args[0].strip()
                if not class_name:
                    raise ValueError(f"{macro} missing class name")

                kind = macro.removeprefix("SYM_")
                if kind == "LIST":
                    refs: tuple[str, ...] = ()
                    varargs = tuple(a for a in args[1:] if a != "")
                elif kind == "TOKEN":
                    refs = ()
                    varargs = tuple(a for a in args[1:] if a != "")
                elif kind.startswith("REF"):
                    n = int(kind.removeprefix("REF"))
                    if len(args) < 1 + n:
                        raise ValueError(f"{macro} expected at least {1+n} args, got {len(args)}")
                    refs = tuple(a.strip() for a in args[1 : 1 + n])
                    if any(r == "" for r in refs):
                        raise ValueError(f"{macro} has empty ref name(s): {refs}")
                    varargs = tuple(a for a in args[1 + n :] if a != "")
                else:
                    raise ValueError(f"unknown macro kind: {macro}")

                entries.append(SymEntry(kind=kind, class_name=class_name, refs=refs, varargs=varargs))

                # Continue scanning after the matching ')'
                i = close_idx + 1
                at_line_start = False
                continue

        if ch == "\n":
            at_line_start = True
        else:
            at_line_start = False
        i += 1

    # Sanity: class names should be unique.
    seen: set[str] = set()
    dups: list[str] = []
    for e in entries:
        if e.class_name in seen:
            dups.append(e.class_name)
        seen.add(e.class_name)
    if dups:
        raise ValueError(f"duplicate class entries in absyntax.def: {dups}")

    return entries


LOCATION_DECL = (
    "int fl = 0, int fc = 0, const char *ffile = NULL /* filename */, long int forder=0,\n"
    "                 int ll = 0, int lc = 0, const char *lfile = NULL /* filename */, long int lorder=0"
)

LOCATION_DEF = (
    "int fl, int fc, const char *ffile, long int forder,\n"
    "                 int ll, int lc, const char *lfile, long int lorder"
)


def _join_varargs(varargs: tuple[str, ...], indent: str) -> str:
    if not varargs:
        return ""
    # Match preprocessor behavior: varargs are comma-separated tokens.
    raw = ", ".join(varargs).strip()
    if not raw:
        return ""
    # Keep as-is; most entries already end with ';' as needed.
    return "\n".join(f"{indent}{line}" for line in raw.splitlines()) + "\n"


def generate_nodes_header(entries: list[SymEntry]) -> str:
    out: list[str] = []
    out.append("// Generated file. Do not edit manually.\n")
    out.append("// Source: absyntax/absyntax.def (SYM_LIST/SYM_TOKEN/SYM_REF* entries)\n\n")
    out.append("#pragma once\n\n")

    for e in entries:
        if e.kind == "LIST":
            out.append(f"class {e.class_name}: public list_c {{\n")
            out.append("public:\n")
            out.append(_join_varargs(e.varargs, "  "))
            out.append("public:\n")
            out.append(f"  {e.class_name}(\n")
            out.append(f"                 {LOCATION_DECL});\n")
            out.append(f"  {e.class_name}(symbol_c *elem,\n")
            out.append(f"                 {LOCATION_DECL});\n")
            out.append("  virtual void *accept(visitor_c &visitor);\n")
            out.append(f"  virtual const char *absyntax_cname(void) {{return \"{e.class_name}\";}};\n")
            out.append("};\n\n")
            continue

        if e.kind == "TOKEN":
            out.append(f"class {e.class_name}: public token_c {{\n")
            out.append("public:\n")
            out.append(_join_varargs(e.varargs, "  "))
            out.append("public:\n")
            out.append(f"  {e.class_name}(const char *value,\n")
            out.append(f"                 {LOCATION_DECL});\n")
            out.append("  virtual void *accept(visitor_c &visitor);\n")
            out.append(f"  virtual const char *absyntax_cname(void) {{return \"{e.class_name}\";}};\n")
            out.append("};\n\n")
            continue

        if e.kind.startswith("REF"):
            n = int(e.kind.removeprefix("REF"))
            out.append(f"class {e.class_name}: public symbol_c {{\n")
            out.append("public:\n")
            for r in e.refs:
                out.append(f"  symbol_c *{r};\n")
            out.append(_join_varargs(e.varargs, "  "))
            out.append("public:\n")

            if n == 0:
                out.append(f"  {e.class_name}(\n")
                out.append(f"                 {LOCATION_DECL});\n")
            else:
                out.append(f"  {e.class_name}(")
                # Required/optional child parameters
                child_params: list[str] = []
                for idx, r in enumerate(e.refs, start=1):
                    default = ""
                    if (n == 2 and idx == 2) or (n == 4 and idx == 4) or (n == 6 and idx == 6):
                        default = " = NULL"
                    child_params.append(f"symbol_c *{r}{default}")
                out.append(",\n                 ".join(child_params))
                out.append(",\n                 ")
                out.append(f"{LOCATION_DECL});\n")

            out.append("  virtual void *accept(visitor_c &visitor);\n")
            out.append(f"  virtual const char *absyntax_cname(void) {{return \"{e.class_name}\";}};\n")
            out.append("};\n\n")
            continue

        raise AssertionError(f"unhandled entry kind: {e.kind}")

    return "".join(out)


def generate_nodes_source(entries: list[SymEntry]) -> str:
    out: list[str] = []
    out.append("// Generated file. Do not edit manually.\n")
    out.append("// Source: absyntax/absyntax.def (SYM_LIST/SYM_TOKEN/SYM_REF* entries)\n\n")
    out.append('#include "absyntax.hh"\n')
    out.append('#include "visitor.hh"\n\n')

    for e in entries:
        if e.kind == "LIST":
            out.append(f"{e.class_name}::{e.class_name}(\n")
            out.append(f"                           {LOCATION_DEF})\n")
            out.append(f"                        :list_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {{}}\n\n")
            out.append(f"{e.class_name}::{e.class_name}(symbol_c *elem,\n")
            out.append(f"                           {LOCATION_DEF})\n")
            out.append(
                f"                        :list_c(elem, fl, fc, ffile, forder, ll, lc, lfile, lorder) {{}}\n"
            )
            out.append(f"void *{e.class_name}::accept(visitor_c &visitor) {{return visitor.visit(this);}}\n\n")
            continue

        if e.kind == "TOKEN":
            out.append(f"{e.class_name}::{e.class_name}(const char *value,\n")
            out.append(f"                           {LOCATION_DEF})\n")
            out.append(
                f"                        :token_c(value, fl, fc, ffile, forder, ll, lc, lfile, lorder) {{}}\n"
            )
            out.append(f"void *{e.class_name}::accept(visitor_c &visitor) {{return visitor.visit(this);}}\n\n")
            continue

        if e.kind.startswith("REF"):
            n = int(e.kind.removeprefix("REF"))

            if n == 0:
                out.append(f"{e.class_name}::{e.class_name}(\n")
                out.append(f"                           {LOCATION_DEF})\n")
                out.append(f"                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {{}}\n")
                out.append(f"void *{e.class_name}::accept(visitor_c &visitor) {{return visitor.visit(this);}}\n\n")
                continue

            # Child parameters (no defaults in definitions)
            child_params = ",\n                           ".join(f"symbol_c *{r}" for r in e.refs)
            out.append(f"{e.class_name}::{e.class_name}({child_params},\n")
            out.append(f"                           {LOCATION_DEF})\n")
            out.append(f"                          :symbol_c(fl, fc, ffile, forder, ll, lc, lfile, lorder) {{\n")
            for r in e.refs:
                out.append(f"  this->{r} = {r};\n")
            for r in e.refs:
                out.append(f"  if  (NULL != {r})   {r}->parent = this;\n")
            out.append("}\n")
            out.append(f"void *{e.class_name}::accept(visitor_c &visitor) {{return visitor.visit(this);}}\n\n")
            continue

        raise AssertionError(f"unhandled entry kind: {e.kind}")

    return "".join(out)


def generate_visitor_decl(entries: list[SymEntry], pure: bool) -> str:
    out: list[str] = []
    out.append("// Generated fragment. Do not edit manually.\n")
    out.append("// Source: absyntax/absyntax.def (SYM_LIST/SYM_TOKEN/SYM_REF* entries)\n\n")

    suffix = " = 0" if pure else ""
    for e in entries:
        out.append(f"  virtual void *visit({e.class_name} *symbol){suffix};\n")
    return "".join(out)


def generate_visitor_impl(entries: list[SymEntry]) -> str:
    out: list[str] = []
    out.append("// Generated file. Do not edit manually.\n")
    out.append("// Source: absyntax/absyntax.def (SYM_LIST/SYM_TOKEN/SYM_REF* entries)\n\n")
    out.append('#include "visitor.hh"\n\n')

    # null_visitor_c
    for e in entries:
        out.append(f"void *null_visitor_c::visit({e.class_name} * /*symbol*/) {{return NULL;}}\n")
    out.append("\n")

    # fcall_visitor_c
    for e in entries:
        out.append(f"void *fcall_visitor_c::visit({e.class_name} *symbol) {{fcall(symbol); return NULL;}}\n")
    out.append("\n")

    # iterator_visitor_c
    for e in entries:
        if e.kind == "LIST":
            out.append(f"void *iterator_visitor_c::visit({e.class_name} *symbol) {{return visit_list(symbol);}}\n")
        elif e.kind == "TOKEN" or e.kind == "REF0":
            out.append(f"void *iterator_visitor_c::visit({e.class_name} * /*symbol*/) {{return NULL;}}\n")
        elif e.kind.startswith("REF"):
            out.append(f"void *iterator_visitor_c::visit({e.class_name} *symbol) {{\n")
            for r in e.refs:
                out.append(f"  if (symbol->{r}) symbol->{r}->accept(*this);\n")
            out.append("  return NULL;\n")
            out.append("}\n")
        else:
            raise AssertionError(f"unhandled entry kind: {e.kind}")
    out.append("\n")

    # fcall_iterator_visitor_c
    for e in entries:
        out.append(f"void *fcall_iterator_visitor_c::visit({e.class_name} *symbol) {{\n")
        out.append("  prefix_fcall(symbol);\n")
        out.append("  iterator_visitor_c::visit(symbol);\n")
        out.append("  suffix_fcall(symbol);\n")
        out.append("  return NULL;\n")
        out.append("}\n")
    out.append("\n")

    # search_visitor_c
    for e in entries:
        if e.kind == "LIST":
            out.append(f"void *search_visitor_c::visit({e.class_name} *symbol) {{return visit_list(symbol);}}\n")
        elif e.kind == "TOKEN" or e.kind == "REF0":
            out.append(f"void *search_visitor_c::visit({e.class_name} * /*symbol*/) {{return NULL;}}\n")
        elif e.kind.startswith("REF"):
            out.append(f"void *search_visitor_c::visit({e.class_name} *symbol) {{\n")
            out.append("  void *res = NULL;\n")
            for r in e.refs:
                out.append(f"  if (symbol->{r}) res = symbol->{r}->accept(*this);\n")
                out.append("  if (res != NULL)  return res;\n")
            out.append("  return NULL;\n")
            out.append("}\n")
        else:
            raise AssertionError(f"unhandled entry kind: {e.kind}")
    out.append("\n")

    return "".join(out)


def generate_child_pusher_methods(entries: list[SymEntry]) -> str:
    out: list[str] = []
    out.append("// Generated fragment. Do not edit manually.\n")
    out.append("// Source: absyntax/absyntax.def (SYM_LIST/SYM_TOKEN/SYM_REF* entries)\n\n")

    for e in entries:
        if e.kind == "LIST":
            out.append(f"    void* visit({e.class_name}* symbol) override {{ return visit_list(symbol); }}\n")
        elif e.kind == "TOKEN" or e.kind == "REF0":
            out.append(f"    void* visit({e.class_name}* /*symbol*/) override {{ return nullptr; }}\n")
        elif e.kind.startswith("REF"):
            out.append(f"    void* visit({e.class_name}* symbol) override {{ ")
            for r in e.refs:
                out.append(f"push(symbol->{r}); ")
            out.append("return nullptr; }\n")
        else:
            raise AssertionError(f"unhandled entry kind: {e.kind}")

    return "".join(out)


def main() -> int:
    ap = argparse.ArgumentParser(description="Generate AST/visitor code from absyntax.def")
    ap.add_argument("--input", type=Path, default=Path(__file__).with_name("absyntax.def"))
    ap.add_argument("--out-dir", type=Path, default=Path(__file__).with_name("generated"))
    args = ap.parse_args()

    text = args.input.read_text(encoding="utf-8", errors="strict")
    entries = parse_absyntax_def(text)

    out_dir: Path = args.out_dir
    out_dir.mkdir(parents=True, exist_ok=True)

    (out_dir / "absyntax_nodes.gen.hh").write_text(generate_nodes_header(entries), encoding="utf-8", newline="\n")
    (out_dir / "absyntax_nodes.gen.cc").write_text(generate_nodes_source(entries), encoding="utf-8", newline="\n")

    (out_dir / "visitor_methods_pure.gen.inc").write_text(
        generate_visitor_decl(entries, pure=True), encoding="utf-8", newline="\n"
    )
    # Included in multiple class scopes: no include guard / pragma once.
    (out_dir / "visitor_methods_virtual.gen.inc").write_text(
        generate_visitor_decl(entries, pure=False), encoding="utf-8", newline="\n"
    )
    (out_dir / "visitor_methods.gen.cc").write_text(generate_visitor_impl(entries), encoding="utf-8", newline="\n")
    (out_dir / "ast_child_pusher_visitor_methods.gen.inc").write_text(
        generate_child_pusher_methods(entries), encoding="utf-8", newline="\n"
    )

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
