# Third-party licenses

The Silex extension is built with third-party software. These components
remain under their own licenses.

## Tree-sitter

The generated C parser includes support code from Tree-sitter 0.25.10,
licensed under the MIT License. The complete notice is stored in
[Tree-sitter.txt](Tree-sitter.txt).

## Rust dependencies

The extension adapter depends directly on `zed_extension_api` 0.3.0, which is
licensed under Apache-2.0. Its transitive dependency graph is locked in
`Cargo.lock`.

That graph contains packages offered under one or more of these SPDX licenses:

- `Apache-2.0`;
- `Apache-2.0 WITH LLVM-exception`;
- `MIT OR Apache-2.0`;
- `Unlicense OR MIT`;
- `Unicode-3.0` for Unicode-derived portions of `unicode-ident`.

The copyright notices and license files distributed in each Cargo source
package continue to apply. Rebuilds and releases must use the committed
`Cargo.lock` so this inventory remains tied to exact dependency versions.
