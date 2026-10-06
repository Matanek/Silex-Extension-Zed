# Release notes

These notes cover Zed extension changes since version 0.52.0. Earlier versions
remain available in Git history.

## [0.53.0] - 2026-10-06

### Added

- Parsing of `+`, `-`, `*`, and `/` operator overload declarations, with
  highlighting of the `operator` keyword and symbol.
- Parsing of integer, boolean, and string patterns in `match`, including
  negative integers.
- Parsing of subjectless condition matches and `yield` statements, with
  highlighting of `yield`.

### Fixed

- Parsing of `move` as a method name in regular, optional, and cascade calls,
  while preserving the `move` transfer expression.
- Alignment of the packaged grammar with the extension's highlighting queries.

### Installation

- The README now presents the Zed gallery as the primary installation method
  and retains development installation.
- No configuration migration is required. The compiler and language server
  remain supplied separately by the `silex` command.
