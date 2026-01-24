# Change: Phase 3 Modern C++ Type System

## Why
Phase 3 introduces a standalone type system so semantic analysis can be
expressed in terms of explicit type objects instead of raw AST pointers.
This enables safer inference, clearer compatibility rules, and future refactors.

## What Changes
- Add type model headers under include/matiec/types/ (Type hierarchy,
  TypeRegistry, TypeInferrer).
- Integrate the registry and inferrer with stage3 type checks, preserving
  current behavior and error reporting.
- Add unit tests for type registry, compatibility rules, and inference.

## Impact
- Affected specs: type-system
- Affected code: include/matiec/types/*, stage3 type utilities, unit tests,
  	ests/CMakeLists.txt
- Risk level: medium (semantic analysis integration)
