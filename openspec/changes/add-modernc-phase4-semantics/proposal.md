# Change: Phase 4 Modern C++ Semantic Analysis

## Why
Phase 4 migrates stage3 semantic analysis to use the new type system and
modernized AST annotations, reducing reliance on legacy helpers while keeping
behavior and diagnostics consistent.

## What Changes
- Migrate candidate datatype collection and narrowing to use the new type model.
- Update constant folding to produce consistent ConstValue results.
- Keep existing error reporting behavior and error codes.
- Add unit tests for semantic analysis regression coverage.

## Impact
- Affected specs: semantic-analysis
- Affected code: stage3 semantic passes, AST annotations, unit tests,
  	ests/CMakeLists.txt
- Risk level: medium-high (semantic behavior and diagnostics)
