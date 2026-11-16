# ADR 0004 — Use GitHub Actions for continuous integration

## Context

When contributors open a pull request, the project must verify that the code compiles and all tests pass before merging. This requires a CI service.

Alternatives considered:

- **GitLab CI.** Powerful, but the repository is hosted on GitHub, so using GitLab CI would add complexity with no benefit.
- **Jenkins.** Self-hosted, requires maintaining a server. Too heavy for a student project.
- **CircleCI / Travis CI.** Third-party services that require extra account setup and configuration.

GitHub Actions is free for public repositories and is built into GitHub, where the project is hosted.

## Decision

Use GitHub Actions to build and test the project on every pull request. The CI job runs inside the same Dev Container image (`mcr.microsoft.com/devcontainers/cpp:1-debian-12`) used for local development, so the CI environment matches the development environment.

## Status

Proposed

## Consequences

- **Good:** Every pull request is automatically verified before merge.
- **Good:** The CI uses the same container image as local development, reducing "works on my machine" issues.
- **Good:** No extra service to set up — GitHub Actions is built into GitHub.
- **Bad:** GitHub Actions is tied to GitHub. Moving to another host would require rewriting the workflow.
- **Bad:** Free tier has usage limits (2,000 minutes/month for private repos), though this is unlikely to matter for a student project.
