# Change: Phase 5 Modern C++ Code Generation

## Why
Phase 5 modernizes code generation by introducing a structured code emitter
and updating C/IEC generators to use it, improving maintainability while
preserving output behavior.

## What Changes
- Add a CodeEmitter utility for indentation, formatting, and block helpers.
- Refactor stage4/generate_c and stage4/generate_iec to use the emitter.
- Add unit or golden-output tests to validate codegen output stability.

## Impact
- Affected specs: codegen-modernization
- Affected code: stage4/generate_c, stage4/generate_iec, new emitter headers,
  tests, 	ests/CMakeLists.txt
- Risk level: medium-high (output formatting and generated code stability)
