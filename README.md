# CMS Toolkit

[![C++](https://img.shields.io/badge/C++-11/17-blue.svg)](https://isocpp.org/)
[![CMake](https://img.shields.io/badge/CMake-3.20+-green.svg)](https://cmake.org/)
[![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey.svg)]()

A lightweight cross-platform C++ utility library providing terminal operations, safe input handling, and more.

# Usage
~~~cpp
#include "cms_utils.hpp" //or cms_toolkit_dll.hpp

// Clear screen
cms::terminal::ClearScreen();

// Safe input
int age = cms::io::SafeInput<int>("Enter age: ");

// Clear buffer on error
cms::io::ClearInput();
~~~

## Start

### Prerequisites

- CMake 3.20 or higher
- C++17 compatible compiler (MSVC, GCC)


### Build and Install

#### Using CMake

```bash
# Configure the project
cmake -B build

# Build the project
cmake --build build --config Release

# Install to dist/ directory
cmake --install build --config Release