## 1. Implementation
- [x] 1.1 Migrate candidate datatype collection to use the type registry.
- [x] 1.2 Migrate datatype narrowing and compatibility checks to the new helpers.
- [x] 1.3 Update constant folding to use type-aware ConstValue results.
- [x] 1.4 Add/extend unit tests for stage3 semantic analysis.
- [x] 1.5 Register new unit tests in tests/CMakeLists.txt.

## 2. Verification
- [x] 2.1 Build (WSL): cmake --build build-wsl
- [x] 2.2 Unit tests: ctest --test-dir build-wsl -R SemanticCandidatesTest --output-on-failure
- [x] 2.3 Unit tests: ctest --test-dir build-wsl -R ConstantFoldingTest --output-on-failure
- [x] 2.4 Regression: ctest --test-dir build-wsl --output-on-failure
