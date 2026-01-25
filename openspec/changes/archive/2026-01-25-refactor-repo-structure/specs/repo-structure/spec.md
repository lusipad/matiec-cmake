## ADDED Requirements
### Requirement: Consolidated root layout
The repository SHALL keep the root directory limited to src/, docs/, cmake/,
config/, tests/, tools/, and openspec/ plus root entry files (e.g.
CMakeLists.txt, README.md, COPYING).

#### Scenario: Root directory audit
- **WHEN** listing the repository root
- **THEN** only the whitelisted top-level directories are present (excluding hidden directories)

### Requirement: Source tree under src
The repository SHALL locate all compiler sources and runtime assets under src/,
including:
- src/absyntax, src/absyntax_utils, src/stage1_2, src/stage3, src/stage4, src/util
- src/include for public headers
- src/lib for IEC 61131-3 standard library assets

#### Scenario: Standard library lookup
- **WHEN** locating the IEC standard library
- **THEN** it is found under src/lib and headers under src/include

### Requirement: Documentation and issue organization
The repository SHALL place architecture documents under docs/architecture,
AnnexF materials under docs/reference/AnnexF, and issue tracking files under
tools/issues with completed items archived under tools/issues/archive.

#### Scenario: Documentation navigation
- **WHEN** searching for architecture docs or AnnexF reference material
- **THEN** they are located under docs/architecture and docs/reference/AnnexF

#### Scenario: Issue archive review
- **WHEN** reviewing completed issue CSV or Markdown files
- **THEN** they are located under tools/issues/archive
