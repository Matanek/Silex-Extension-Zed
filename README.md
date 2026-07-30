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
module and package symbols, and inline previews for direct `GFX.Color`
expressions in the executable language subset. Zed renders those previews
according to its `lsp_document_colors` setting. The server does not yet
advertise the historical navigation and refactoring features.
