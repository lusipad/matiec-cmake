# Change: Phase 6 Modern C++ Integration and Cleanup

## Why
Phase 6 removes transitional compatibility layers, updates documentation, and
adds baseline performance checks to complete the modernization effort.

## What Changes
- Remove legacy visitor compatibility adapters and oid* visitor interfaces.
- Clean up legacy helpers superseded by the new type system.
- Update documentation to describe the modern AST/type/codegen APIs.
- Add a basic benchmark or performance checklist for regression tracking.

## Impact
- Affected specs: modernization-integration
- Affected code: legacy compatibility headers, stage3 helpers, docs, benchmarks
- Risk level: medium (removal of legacy APIs)
