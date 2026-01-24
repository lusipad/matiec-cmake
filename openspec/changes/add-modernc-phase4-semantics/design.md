## Context
Phase 4 transitions stage3 semantic passes to the new type system introduced in
Phase 3 while preserving existing error reporting and behavior.

## Goals / Non-Goals
- Goals:
  - Use the new type registry and compatibility helpers in stage3.
  - Preserve existing diagnostics and error codes.
  - Keep semantic results compatible with current codegen.
- Non-Goals:
  - No code generation refactor in this phase.
  - No CLI or C API changes.

## Decisions
- Keep AST annotations (candidateDatatypes, datatype, constValue) in place
  while switching their backing logic to the new type model.
- Add targeted regression tests for semantic analysis.

## Risks / Trade-offs
- Subtle semantic differences may surface; tests must pin expected behavior.

## Migration Plan
1) Migrate candidate collection and narrowing helpers.
2) Migrate constant folding.
3) Expand semantic regression tests.

## Open Questions
- Should semantic errors be routed through a unified diagnostic helper in this
  phase or deferred to a later cleanup?
