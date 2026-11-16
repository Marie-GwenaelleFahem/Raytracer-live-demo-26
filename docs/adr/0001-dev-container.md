# ADR 0001 — Use a Dev Container for the development environment

## Context

Team members use different operating systems and may have different versions of compilers, CMake, or libraries installed locally. This leads to "works on my machine" problems that waste time.

Alternatives considered:

- **Manual setup instructions in the README.** Each developer installs tools by hand. Differences in OS, shell, or package versions can cause hard-to-debug build failures.
- **Docker Compose without IDE integration.** Provides a reproducible environment but requires developers to manage containers manually and loses IDE features like IntelliSense.

The course requires that every student works in the same environment.

## Decision

Use a VS Code Dev Container based on the `mcr.microsoft.com/devcontainers/cpp:1-debian-12` image. The container includes the C++ toolchain, CMake, and the VS Code extensions needed for C++ development. The project builds automatically when the container is created.

## Status

Accepted

## Consequences

- **Good:** Every team member gets an identical environment with one click. No time lost on setup or debugging OS-specific issues.
- **Good:** New contributors (partner studios) can start working immediately.
- **Good:** The `postCreateCommand` builds the project on first open, so the developer knows right away if something is broken.
- **Bad:** Requires VS Code and Docker. Developers who prefer another editor must adapt or maintain their own setup.
- **Bad:** Building inside a container can be slower than building natively, depending on the host machine.
