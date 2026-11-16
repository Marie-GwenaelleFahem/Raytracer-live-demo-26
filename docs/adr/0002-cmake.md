# ADR 0002 — Use CMake as the build system (with CTest)

## Context

A C++ project needs a build system to compile source files, manage dependencies, and run tests. The course requires CMake.

Alternatives considered:

- **Plain Makefiles.** Simple for small projects, but hard to maintain as the project grows and not portable across platforms.
- **Meson.** Modern and fast, but less widely adopted in the C++ industry and less tooling support in VS Code.
- **Bazel.** Powerful for large monorepos, but complex to set up and overkill for a project of this size.

CTest is the test runner bundled with CMake. It discovers and runs test executables declared in the CMake configuration.

## Decision

Use CMake (minimum version 3.20) with C++20 and strict compiler warnings (`-Wall -Wextra -Wpedantic -Werror` on GCC/Clang, `/W4 /WX` on MSVC). Use CTest to run the tests.

## Status

Accepted

## Consequences

- **Good:** CMake is the industry standard for C++ projects. Partner studios are likely already familiar with it.
- **Good:** CTest is included with CMake, so no extra tool is needed to run tests.
- **Good:** Cross-platform: the same `CMakeLists.txt` works on Linux, macOS, and Windows.
- **Good:** Strict warnings (`-Werror`) catch potential bugs at compile time.
- **Bad:** CMake syntax is verbose and can be confusing for beginners.
- **Bad:** `FetchContent` (used for Catch2) downloads dependencies at configure time, which requires an internet connection on first build.
