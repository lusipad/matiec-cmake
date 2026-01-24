## Context
Phase 6 finalizes the modernization by removing compatibility shims and
updating project documentation and performance checks.

## Goals / Non-Goals
- Goals:
  - Remove legacy visitor and type helpers.
  - Update docs to reflect modern APIs.
  - Add a lightweight performance regression check.
- Non-Goals:
  - No changes to external CLI behavior or output format.

## Decisions
- Remove compatibility layers only after Phases 2-5 are complete.
- Keep the performance check lightweight and repeatable.

## Risks / Trade-offs
- Downstream projects may need migration guidance; docs must be explicit.

## Migration Plan
1) Remove legacy headers and update includes.
2) Update docs and migration notes.
3) Add and document performance check.
