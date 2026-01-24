# P5: Modern C++ Phase 5 Code Generation

Goal: introduce CodeEmitter and refactor C/IEC code generators while preserving
output stability.

Non-goals:
- No semantic changes.
- No CLI or C API changes.

## Steps (E2E loop)
1) plan -> issues: generate Issue CSV (A1-A2).
2) implement: CodeEmitter + generator refactors.
3) test: build + codegen regression tests.
4) review: confirm output stability for fixtures.
5) commit: per-issue commits if needed.
6) regression: run full ctest after A1-A2 complete.

## Verification
- Build: cmake --build build-wsl
- Tests: ctest --test-dir build-wsl -R CodeEmitterTest --output-on-failure
- Tests: ctest --test-dir build-wsl -R CodegenRegressionTest --output-on-failure
- Regression: ctest --test-dir build-wsl --output-on-failure

## Risks
- Output formatting drift.

## Rollback / Safety
- Revert the change commit(s); keep legacy generator logic available until Phase 6.
