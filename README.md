# Raytracer-live-demo-26

A ray tracer written in C++ for a Los Angeles film studio (fictional scenario, 2035).

The studio wants a ray tracer that its developers and partner studios can
understand, fix and extend for years. It must be readable, tested, documented,
and fast enough to render a full feature film on CPU-only machines.

## Documentation

- [Discovery report](docs/discovery/discovery-report.md): problem statement,
  client interview, state of the art, and open questions.

---

## How to build and run

### Option 1 — Dev container (recommended, cross-platform)

Requirements: [Docker](https://www.docker.com/) and
[VS Code](https://code.visualstudio.com/) with the
[Dev Containers extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers).

1. Open the project in VS Code.
2. When prompted, click **Reopen in Container** (or run
   `Dev Containers: Reopen in Container` from the command palette).
3. The container builds itself and runs `cmake` automatically.
4. Open a terminal inside VS Code and run:

```bash
cmake --build build
./build/raytracer
```

### Option 2 — Local machine

Requirements: a C++20 compiler (GCC 11+, Clang 13+, or MSVC 2022+) and
[CMake 3.20+](https://cmake.org/).

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/raytracer          # Linux / macOS
build\Debug\raytracer.exe  # Windows
```

---

## How to run the tests

The project uses [Catch2 v3](https://github.com/catchorg/Catch2) for TDD.
Catch2 is downloaded automatically by CMake the first time you configure the
project (requires an internet connection).

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
```

### TDD workflow

1. Write a failing test in `tests/`.
2. Run `ctest` to confirm it fails.
3. Write the minimum code in `src/` to make it pass.
4. Run `ctest` again to confirm it passes.
5. Refactor if needed, then commit.

---

## Project layout

```
.devcontainer/      Dev container configuration
src/                Source code
tests/              Tests (Catch2)
docs/               Documentation
  discovery/        Discovery report
CMakeLists.txt      Build configuration
```
