# Silex for Zed

This repository contains the Zed extension for the Silex language. It owns the
Tree-sitter grammar, Zed queries, and the small Rust adapter that
starts the language server supplied by the `silex` command.

The compiler, semantic analysis and language-server implementation remain in
the main [Silex repository](https://github.com/Matanek/Silex).

## Install the extension

First, [install Silex](https://github.com/Matanek/Silex-Documentation/blob/main/EN/Tools/Installation.md)
and check that Zed can find its command:

```sh
silex --version
```

Open Zed's Extensions view, search for `Silex`, and click **Install**.
Open an `.sx` file to start `silex lsp` automatically. If Silex was added to
`PATH` while Zed was open, restart Zed first. Git and Rust are not needed for
this installation.

See the [installation guide](https://github.com/Matanek/Silex-Documentation/blob/main/EN/Tools/Install-Zed-extension.md)
for both installation methods and troubleshooting.

### Install a development version

Use this method to test repository changes that are not yet in the gallery.

Install Git and Rust with `rustup`, then add the WebAssembly target used by Zed
extensions:

```sh
rustup target add wasm32-wasip2
git clone https://github.com/Matanek/Silex-Extension-Zed.git
```

In Zed, open the command palette, run `zed: install dev extension`, and select
the cloned `Silex-Extension-Zed` directory that contains `extension.toml`.
Open an `.sx` file to start `silex lsp` automatically. If Silex was added to
`PATH` while Zed was open, restart Zed first.

To update this development installation, pull the repository and run
`zed: rebuild dev extension` from the command palette:

```sh
git -C Silex-Extension-Zed pull --ff-only
```

A development extension overrides the gallery version. To switch back,
uninstall the development extension, then install `Silex` from the Extensions
view.

## Release notes

See [CHANGELOG.md](CHANGELOG.md) or the [French release notes](CHANGELOG.fr.md).

## Development requirements

- `silex` available in `PATH`;
- Node.js and npm for the Tree-sitter grammar;
- Rust installed through rustup with the `wasm32-wasip2` target for the Zed
  extension.

## Verify the grammar

```sh
npm install
npx tree-sitter generate
npm test
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
