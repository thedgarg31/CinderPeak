#!/bin/bash
# Install pre-commit hook for CinderPeak

echo "Installing pre-commit hook..."

# Check if we're in a git repository
if [ ! -d ".git" ]; then
    echo "Error: Not in a git repository"
    exit 1
fi

# Copy the pre-commit hook
cp scripts/pre-commit .git/hooks/pre-commit

# Make it executable
chmod +x .git/hooks/pre-commit

echo "Pre-commit hook installed successfully!"
echo "The hook will automatically format C++ files using clang-format before each commit."
