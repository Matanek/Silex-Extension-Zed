# Silex for Zed

This repository contains the Zed extension for the Silex language. It owns the
Tree-sitter grammar, Zed queries, and the small Rust adapter that
starts the language server supplied by the `silex` command.

The compiler, semantic analysis and language-server implementation remain in
the main [Silex repository](https://github.com/Matanek/Silex).

## Requirements

- `silex` available in `PATH`;
- Node.js and npm for the Tree-sitter grammar;
- Rust installed through rustup with the `wasm32-wasip2` target for the Zed
  extension.

## Verify the grammar

```sh
npm install
npx tree-sitter generate
npx tree-sitter test
```

## Build the extension

```sh
cargo build --target wasm32-wasip2
```

The extension adapter only launches `silex lsp`. Editor-independent language
behavior is implemented and tested in the main Silex repository. The current
server provides diagnostics, context-prioritized completion for document,
module and package symbols, definition navigation to module and package
sources, and inline previews for direct `GFX.Color` expressions in the
executable language subset. Zed renders those previews according to its
`lsp_document_colors` setting. References and refactoring features are not yet
advertised.

## License

The Silex extension and grammar are licensed under the Apache License 2.0 with
LLVM Exceptions (`Apache-2.0 WITH LLVM-exception`). See [LICENSE](LICENSE) and
[NOTICE](NOTICE).

Generated Tree-sitter support code and Rust dependencies remain subject to
their respective terms listed in
[Licenses/README.md](Licenses/README.md).
