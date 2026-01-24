## 1. Implementation
- [x] 1.1 Add include/matiec/types/type.hpp defining the Type hierarchy and
      compatibility helpers.
- [x] 1.2 Add include/matiec/types/type_registry.hpp with built-in types and
      registration APIs.
- [x] 1.3 Add include/matiec/types/type_inferrer.hpp and integrate with stage3.
- [x] 1.4 Add unit tests for registry lookup, compatibility, and inference.
- [x] 1.5 Register new unit tests in tests/CMakeLists.txt.

## 2. Verification
- [x] 2.1 Build (WSL): cmake --build build-wsl
- [x] 2.2 Unit tests: ctest --test-dir build-wsl -R TypeRegistryTest --output-on-failure
- [x] 2.3 Unit tests: ctest --test-dir build-wsl -R TypeInferrerTest --output-on-failure
