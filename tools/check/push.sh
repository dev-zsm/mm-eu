#!/bin/bash
# THE way to push to main, from the main checkout or from ANY worktree: `make push` or tools/check/push.sh in WSL, or tools/mm push from Windows.
# The checks (selftest, fastcheck) run in WSL and need no git. The git commands (fetch, rebase, push) go through the Windows git.exe when it
# can be found: inside WSL, the .git file of a worktree points to a Windows path that the git of Linux cannot follow.
# Refuses when the tree has uncommitted changes. When origin/main moved it rebases on it (stops on a conflict, nothing is lost: `git rebase
# --abort` was run), checks the rebased tree, and pushes; when it moves again during the checks (another agent pushed), once more.
# Prints `pushed <hash>`, or why not. MM_FULL=1 trusts no earlier verdict in the fastcheck. Environment: GIT=<path of git> to choose the git.
cd "$(dirname "$0")/../.."
[ -f ~/mm-venv/bin/activate ] && . ~/mm-venv/bin/activate
bash tools/check/preflight.sh || exit 1
find_git() {
    [ -n "${GIT:-}" ] && { echo "$GIT"; return; }
    for g in git.exe "/mnt/c/Program Files/Git/cmd/git.exe" "/mnt/c/Program Files/Git/bin/git.exe" "/mnt/c/Program Files (x86)/Git/cmd/git.exe"; do
        command -v "$g" > /dev/null 2>&1 && { command -v "$g"; return; }
    done
    command -v git
}
GITBIN=$(find_git) || { echo "no git found (git.exe of Windows, or git)" >&2; exit 1; }
g() { "$GITBIN" "$@" | tr -d '\r'; return "${PIPESTATUS[0]}"; }   # a path with a space is one word here
g rev-parse --git-dir > /dev/null 2>&1 || { echo "this git ($GITBIN) cannot read the repository: set GIT=<git.exe of Windows> and retry" >&2; exit 1; }
[ -z "$(g status --porcelain --untracked-files=no)" ] || { echo "not pushed: uncommitted changes, commit them first" >&2; exit 1; }
for attempt in 1 2 3; do
    g fetch -q origin || { echo "not pushed: git fetch failed" >&2; exit 1; }
    if ! g merge-base --is-ancestor origin/main HEAD; then
        echo "origin/main moved: rebasing on it"
        g rebase origin/main > /dev/null 2>&1 || { g rebase --abort > /dev/null 2>&1; echo "not pushed: the rebase on origin/main conflicts, resolve it by hand" >&2; exit 1; }
    fi
    [ "$(g rev-list --count origin/main..HEAD)" -gt 0 ] || { echo "nothing to push"; exit 0; }
    make selftest && bash tools/check/fastcheck.sh || { echo "not pushed: the checks failed" >&2; exit 1; }
    g fetch -q origin
    if ! g merge-base --is-ancestor origin/main HEAD; then
        echo "origin/main moved during the checks (attempt $attempt)"
        continue
    fi
    if g push origin HEAD:main; then
        echo "pushed $(g rev-parse --short HEAD)"
        exit 0
    fi
    echo "the push was refused (attempt $attempt)"
done
echo "not pushed: origin/main kept moving, run it again" >&2
exit 1
