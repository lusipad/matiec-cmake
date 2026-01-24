# P4: Modern C++ Phase 4 Semantic Analysis

Goal: migrate stage3 semantic passes to the new type system and keep diagnostics
behavior-compatible.

Non-goals:
- No codegen changes.
- No CLI or C API changes.

## Steps (E2E loop)
1) plan -> issues: generate Issue CSV (A1-A2).
2) implement: candidate collection/narrowing, constant folding updates.
3) test: build + semantic regression tests.
4) review: validate error codes and messages.
5) commit: per-issue commits if needed.
6) regression: run full ctest after A1-A2 complete.

## Verification
- Build (WSL): cmake --build build-wsl
- Tests: ctest --test-dir build-wsl -R SemanticCandidatesTest --output-on-failure
- Tests: ctest --test-dir build-wsl -R ConstantFoldingTest --output-on-failure
- Regression: ctest --test-dir build-wsl --output-on-failure

## Risks
- Subtle semantic behavior drift.

## Rollback / Safety
- Revert the change commit(s); keep legacy helpers until Phase 6.
