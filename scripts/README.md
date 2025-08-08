# Development Scripts

This directory contains scripts to help with development workflow.

## Pre-commit Hook

The pre-commit hook automatically formats C++ code using clang-format before each commit.

### Installation

Run the installation script:
```bash
./scripts/install-hooks.sh
```

Or manually copy the hook:
```bash
cp scripts/pre-commit .git/hooks/pre-commit
chmod +x .git/hooks/pre-commit
```

### Requirements

- `clang-format` must be installed and available in your PATH
- The hook uses the `.clang-format` configuration file in the project root

### What it does

- Runs on every `git commit`
- Automatically formats all staged C++ files (`.cpp`, `.hpp`, `.h`, `.cc`, `.cxx`)
- Re-stages the formatted files
- Prevents commit if clang-format is not available
