#!/bin/bash

# Setup script for CinderPeak development environment
# This script sets up pre-commit hooks and development tools

echo "Setting up CinderPeak development environment..."

# Make pre-commit hook executable
chmod +x .git/hooks/pre-commit

echo "✓ Pre-commit hook installed and made executable"

# Check for required tools
echo "Checking for required development tools..."

# Check for clang-format
if command -v clang-format &> /dev/null; then
    echo "✓ clang-format found: $(clang-format --version | head -n1)"
else
    echo "⚠ clang-format not found. Please install it:"
    echo "  Ubuntu/Debian: sudo apt-get install clang-format"
    echo "  macOS: brew install clang-format"
    echo "  Windows: Install LLVM from https://llvm.org/builds/"
fi

# Check for clang-tidy
if command -v clang-tidy &> /dev/null; then
    echo "✓ clang-tidy found: $(clang-tidy --version | head -n1)"
else
    echo "⚠ clang-tidy not found. Please install it:"
    echo "  Ubuntu/Debian: sudo apt-get install clang-tidy"
    echo "  macOS: brew install llvm"
    echo "  Windows: Install LLVM from https://llvm.org/builds/"
fi

# Check for CMake
if command -v cmake &> /dev/null; then
    echo "✓ CMake found: $(cmake --version | head -n1)"
else
    echo "⚠ CMake not found. Please install CMake 3.14 or later"
fi

echo ""
echo "Development environment setup complete!"
echo ""
echo "Usage:"
echo "  - The pre-commit hook will automatically run clang-format and clang-tidy"
echo "  - To manually format code: clang-format -i <file>"
echo "  - To run static analysis: clang-tidy <file> -p build"
echo "  - To build the project: cmake -S . -B build && cmake --build build"
echo ""
echo "Happy coding! 🚀"
