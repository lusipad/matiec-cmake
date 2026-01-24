## 1. Implementation
- [x] 1.1 Add include/matiec/codegen/code_emitter.hpp with indentation and
      block helpers.
- [x] 1.2 Refactor C generator to use CodeEmitter.
- [x] 1.3 Refactor IEC generator to use CodeEmitter.
- [x] 1.4 Add codegen regression tests (golden output or fixture-based).
- [x] 1.5 Register new tests in tests/CMakeLists.txt.

## 2. Verification
- [x] 2.1 Build: cmake --build build-wsl
- [x] 2.2 Tests: ctest --test-dir build-wsl -R CodeEmitterTest --output-on-failure
- [x] 2.3 Tests: ctest --test-dir build-wsl -R CodegenRegressionTest --output-on-failure
- [x] 2.4 Regression: ctest --test-dir build-wsl --output-on-failure
