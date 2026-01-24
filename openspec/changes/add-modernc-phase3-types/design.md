## Context
Phase 3 introduces a type system decoupled from the AST so semantic checks can
use explicit type objects and compatibility rules.

## Goals / Non-Goals
- Goals:
  - Provide Type hierarchy and registry for built-in and user-defined types.
  - Provide a type inferrer for literals and expressions.
  - Preserve existing stage3 behavior and error diagnostics.
- Non-Goals:
  - No changes to code generation output.
  - No CLI or C API changes.

## Decisions
- Keep the type model header-only initially to minimize build impact.
- Use shared ownership for registry-managed types.
- Provide a compatibility layer for existing get_datatype_info_c utilities.

## Risks / Trade-offs
- Divergence between legacy and new type logic until migration is complete.

## Migration Plan
1) Add new type headers and unit tests.
2) Bridge stage3 type utilities to the new registry/inferrer.
3) Remove legacy type helpers in Phase 6.

## Open Questions
- Should type registry be per-compilation-unit or global singleton?
