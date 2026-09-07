use zed_extension_api as zed;

struct SilexExtension;

impl zed::Extension for SilexExtension {
    fn new() -> Self {
        Self
    }

    fn language_server_command(
        &mut self,
        _language_server_id: &zed::LanguageServerId,
        worktree: &zed::Worktree,
    ) -> zed::Result<zed::Command> {
        let command = worktree
            .which("silex")
            .ok_or_else(|| "silex was not found in the user PATH".to_string())?;

        Ok(zed::Command {
            command,
            args: vec!["lsp".to_string()],
            env: Vec::new(),
        })
    }
}

zed::register_extension!(SilexExtension);
