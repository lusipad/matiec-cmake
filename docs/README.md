# matiec - IEC 61131-3 Compiler

matiec is an open-source compiler for the IEC 61131-3 programming languages used in Programmable Logic Controllers (PLCs).

## Included Tools

### iec2c
Compiles IEC 61131-3 source code to C code.

```bash
# Windows
tools/win-x64/iec2c.exe -I lib input.st -T output_dir

# Linux
tools/linux-x64/iec2c -I lib input.st -T output_dir

# macOS
tools/osx-x64/iec2c -I lib input.st -T output_dir
```

### iec2iec
Normalizes and pretty-prints IEC 61131-3 source code.

```bash
# Windows
tools/win-x64/iec2iec.exe input.st

# Linux
tools/linux-x64/iec2iec input.st

# macOS
tools/osx-x64/iec2iec input.st
```

## Supported Languages

- **ST** (Structured Text)
- **IL** (Instruction List)
- **SFC** (Sequential Function Chart)
- **FBD** (Function Block Diagram) - partial
- **LD** (Ladder Diagram) - partial

## Command Line Options

| Option | Description |
|--------|-------------|
| `-h` | Display help |
| `-v` | Display version |
| `-f` | Display full token location |
| `-p` | Allow use of forward references |
| `-l` | Use relaxed datatype equivalence model |
| `-s` | Support SAFE datatypes (PLCopen Safety) |
| `-n` | Allow nested comments |
| `-r` | Support REF_TO, REF, ^, and NULL |
| `-I <dir>` | Include directory for libraries |
| `-T <dir>` | Target directory for output |

## Standard Library

The `lib/` directory contains IEC 61131-3 standard library definitions:
- Standard functions (arithmetic, comparison, etc.)
- Standard function blocks (timers, counters, etc.)
- Type definitions

## License

GPL-3.0 - See LICENSE file for details.

## Links

- [GitHub Repository](https://github.com/your-org/matiec)
- [IEC 61131-3 Standard](https://www.plcopen.org/)
