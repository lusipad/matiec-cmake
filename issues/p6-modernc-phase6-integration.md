# P6: Modern C++ Phase 6 Integration and Cleanup

Goal: remove legacy compatibility layers, update documentation, and add
lightweight performance regression checks.

Non-goals:
- No output format changes.
- No new compiler features.

## Steps (E2E loop)
1) plan -> issues: generate Issue CSV (A1-A2).
2) implement: remove legacy adapters/helpers, update docs.
3) test: build + full ctest.
4) review: ensure migration guidance is clear.
5) commit: per-issue commits if needed.
6) regression: run full ctest after A1-A2 complete.

## Verification
- Build: cmake --build build-wsl
- Tests: ctest --test-dir build-wsl --output-on-failure

## Risks
- Downstream breakage if migration notes are insufficient.

## Rollback / Safety
- Revert the change commit(s); reintroduce legacy headers if needed.
