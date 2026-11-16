# Contributing

Thank you for your interest in contributing to this project.

## Setting up the development environment

1. Install [Docker](https://www.docker.com/) and [VS Code](https://code.visualstudio.com/) with the [Dev Containers extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers).
2. Open the project in VS Code.
3. Click **Reopen in Container** when prompted (or run `Dev Containers: Reopen in Container` from the command palette).
4. The container builds itself and runs the first build automatically.

## Commands

```bash
make build   # Configure and compile
make run     # Build and run the raytracer
make test    # Build and run the tests
make clean   # Delete the build directory
```

## Test-Driven Development (TDD)

We follow TDD. Every feature or bug fix must come with tests.

1. Write a failing test in `tests/`.
2. Run `make test` to confirm it fails.
3. Write the minimum code in `src/` to make it pass.
4. Run `make test` again to confirm it passes.
5. Refactor if needed, then commit.

## Architecture Decision Records (ADR)

Architecture decisions are documented in `docs/adr/` using Michael Nygard's format.

- Read the existing ADRs before changing the build system, tools, or test setup.
- Never go against an accepted ADR.
- To propose a change, write a new ADR with status **Proposed** and open a pull request. The maintainers will review and accept or reject it.

## Submitting a change

1. Fork the repository and create a branch from `main`.
2. Make your changes in small, focused commits with clear messages.
3. Make sure `make test` passes.
4. Open a pull request and fill in the template.

## Code of conduct

This project follows the [Contributor Covenant Code of Conduct](CODE_OF_CONDUCT.md). By participating, you agree to uphold it.
