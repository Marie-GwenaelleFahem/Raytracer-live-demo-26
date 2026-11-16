# Project commands

```bash
make build   # Configure and compile
make run     # Build and run the raytracer
make test    # Build and run the tests
make clean   # Delete the build directory
```

# Architecture decisions

Architecture Decision Records live in `docs/adr/`. Read them before changing the build system, the tools, or the test setup.

- Never go against an accepted ADR.
- To change a decision, write a new ADR with status **Proposed** and ask the developer. Never set an ADR status to **Accepted** yourself.

# Contributing and open source

- [CONTRIBUTING.md](CONTRIBUTING.md): setup, commands, TDD workflow, ADR process.
- [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md): Contributor Covenant.
- [LICENSE](LICENSE): MIT.
- `.github/workflows/ci.yml`: CI builds and tests every pull request.
- `.github/pull_request_template.md` and `.github/ISSUE_TEMPLATE/`: templates for PRs and issues.
