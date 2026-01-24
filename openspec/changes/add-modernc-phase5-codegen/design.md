## Context
Phase 5 introduces a structured code emitter and refactors code generation to
improve readability and reduce string-concatenation noise.

## Goals / Non-Goals
- Goals:
  - Provide CodeEmitter with indentation and block helpers.
  - Keep generated output stable for existing inputs.
- Non-Goals:
  - No semantic changes to generated code.
  - No CLI or C API changes.

## Decisions
- Use a lightweight emitter that writes to std::ostream and enforces 4-space
  indentation to match existing style.
- Add golden-output tests for representative fixtures.

## Risks / Trade-offs
- Minor formatting drift could cause downstream diffs; tests will lock output.

## Migration Plan
1) Introduce CodeEmitter and unit tests.
2) Move C generator to the emitter.
3) Move IEC generator to the emitter.
