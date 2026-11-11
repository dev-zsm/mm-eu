#!/bin/bash
# THE way to push to main. In WSL: `make push` or tools/check/push.sh
# Refuses unless the commit sits on top of origin/main and the tree is committed; then runs the selftest and a full fastcheck
# (incremental by default, MM_FULL=1 make push trusts no earlier verdict), and only when both are green: git push origin HEAD:main.
# A push refused because someone pushed meanwhile ends here: rebase on origin/main and run it again.
cd "$(dirname "$0")/../.."
bash tools/check/preflight.sh || exit 1
# git does not work inside WSL for a worktree of a Windows checkout: git.exe does
g() { if command -v git.exe > /dev/null; then git.exe "$@"; else command git "$@"; fi; }
g fetch -q origin || exit 1
g merge-base --is-ancestor origin/main HEAD || { echo "origin/main has commits that HEAD does not: git rebase origin/main first" >&2; exit 1; }
[ -z "$(g status --porcelain --untracked-files=no)" ] || { echo "uncommitted changes: commit them first" >&2; exit 1; }
[ "$(g rev-list --count origin/main..HEAD | tr -d '\r')" -gt 0 ] || { echo "nothing to push"; exit 0; }
make selftest && bash tools/check/fastcheck.sh || { echo "checks failed: not pushed" >&2; exit 1; }
g fetch -q origin && g merge-base --is-ancestor origin/main HEAD || { echo "origin/main moved during the checks: rebase and run again" >&2; exit 1; }
g push origin HEAD:main
