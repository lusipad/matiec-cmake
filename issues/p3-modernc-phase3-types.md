# P3: Modern C++ Phase 3 Type System

Goal: introduce a standalone type model and registry, plus type inference,
then integrate them into stage3 checks while preserving behavior.

Non-goals:
- No codegen changes.
- No CLI or C API changes.

## Steps (E2E loop)
1) plan -> issues: generate Issue CSV (A1-A2).
2) implement: type model/registry, type inferrer integration.
3) test: build + type unit tests.
4) review: verify compatibility with existing semantic behavior.
5) commit: per-issue commits if needed.
6) regression: run full ctest after A1-A2 complete.

## Verification
- Build (WSL): cmake --build build-wsl
- Tests: ctest --test-dir build-wsl -R TypeRegistryTest --output-on-failure
- Tests: ctest --test-dir build-wsl -R TypeInferrerTest --output-on-failure

## Risks
- Divergence between legacy and new type logic.

## Rollback / Safety
- Revert the change commit(s); keep legacy helpers in place until Phase 6.
