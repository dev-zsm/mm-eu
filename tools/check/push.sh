#!/bin/bash
# THE way to push to main, from the main checkout or from ANY worktree. From Windows (Git Bash): `bash tools/mm push` (or this script); in WSL: `make push`.
# The checks (selftest, fastcheck) always run in WSL and need no git. Every git command (fetch, rebase, push) runs on WINDOWS, never with the git of
# Linux (inside WSL the .git file of a worktree points to a Windows path that git cannot read): started from Git Bash, the script runs git natively
# and calls WSL for the checks only, so a broken link from WSL to Windows (accept4 failed 110, E_UNEXPECTED) does not touch it; started in WSL,
# it looks for the git of Windows once, in this order: GIT=<path>, `where git` asked to cmd.exe, git.exe on the path, the Git for Windows folders,
# `cmd.exe /c git`, `powershell.exe -c git`. The git in use is named in the output and in every failure, and a git command that fails on that
# link is tried again four times with a pause of 15 s.
# Refuses when the tree has uncommitted changes. When origin/main moved it rebases on it (a conflict stops it after `rebase --abort`), checks the
# rebased tree and pushes; when it moves again during the checks it does it once more, three attempts at most. The checks of a tree are not repeated:
# a tree that already passed (the push failed, or the script was killed after the checks) is pushed without them; a rebased tree gets the
# incremental fastcheck only (MM_FULL=1 applies to the first attempt). Prints `pushed <hash>`, or why not.
cd "$(dirname "$0")/../.."
if [ "${1:-}" = --checks ]; then   # what the Windows side asks WSL to do: no git here
    [ -f ~/mm-venv/bin/activate ] && . ~/mm-venv/bin/activate
    bash tools/check/preflight.sh || exit 1
    make selftest && bash tools/check/fastcheck.sh
    exit $?
fi
case "$(uname -s)" in MINGW* | MSYS* | CYGWIN*) WINDOWS=1 ;; *) WINDOWS= ; [ -f ~/mm-venv/bin/activate ] && . ~/mm-venv/bin/activate ;; esac
bash tools/check/preflight.sh "$(pwd)" || exit 1

GITCMD=(); GITDESC=""
try_git() {   # $1 description, rest: the command; keeps it when `--version` answers
    local desc=$1; shift
    "$@" --version > /dev/null 2>&1 || return 1
    GITCMD=("$@"); GITDESC=$desc
}
find_git() {
    local p
    if [ -n "${GIT:-}" ]; then
        try_git "GIT=$GIT" "$GIT"; return
    fi
    if [ -n "$WINDOWS" ]; then
        try_git "git of Windows (Git Bash)" git; return
    fi
    p=$(cmd.exe /c "where git" 2>/dev/null | tr -d '\r' | head -n 1)   # the lookup of Windows, not of WSL
    [ -n "$p" ] && p=$(wslpath -u "$p" 2>/dev/null) && [ -x "$p" ] && try_git "git of Windows at $p" "$p" && return
    p=$(command -v git.exe) && try_git "git.exe at $p" "$p" && return
    for p in "/mnt/c/Program Files/Git/cmd/git.exe" "/mnt/c/Program Files/Git/bin/git.exe" "/mnt/c/Program Files (x86)/Git/cmd/git.exe"; do
        [ -x "$p" ] && try_git "git.exe at $p" "$p" && return
    done
    try_git "cmd.exe /c git" cmd.exe /c git && return
    try_git "powershell.exe -c git" powershell.exe -NoProfile -Command git
}
for i in 1 2 3 4; do find_git && break; echo "no git answered (try $i of 4), waiting 15 s" >&2; sleep 15; done
[ ${#GITCMD[@]} -gt 0 ] || { echo "not pushed: no git of Windows answered (tried GIT, where git, git.exe, the install folders, cmd.exe, powershell.exe; from WSL the link to Windows may be down: run \`bash tools/mm push\` from Git Bash instead); install Git for Windows or set GIT=<path of git.exe>" >&2; exit 1; }
echo "git: $GITDESC"

LINK='accept4|E_UNEXPECTED|WSL_E_|Wsl/Service|UtilBindVsockAnyPort|vsock|Input/output error|Connection reset'
g() {   # the git command, output without carriage returns, tried again when the link to Windows fails
    local out rc i
    for i in 1 2 3 4; do
        out=$("${GITCMD[@]}" "$@" 2>&1); rc=$?
        [ $rc -ne 0 ] && echo "$out" | grep -qE "$LINK" && { echo "git ($GITDESC): the link to Windows failed (try $i of 4), waiting 15 s" >&2; sleep 15; continue; }
        break
    done
    [ -n "$out" ] && printf '%s\n' "$out" | tr -d '\r'
    return $rc
}
up_to_date() {   # 0: origin/main is in HEAD; 1: it is not; the script stops when git itself fails
    g merge-base --is-ancestor origin/main HEAD
    case $? in 0) return 0 ;; 1) return 1 ;; *) echo "not pushed: git merge-base failed ($GITDESC)" >&2; exit 1 ;; esac
}
run_checks() {
    if [ -n "$WINDOWS" ]; then   # the checks in WSL, started from here
        local root; root=$(pwd); case "$root" in /[a-z]/*) root="/mnt/${root:1:1}/${root:3}" ;; esac
        for i in $(seq 1 15); do wsl.exe -d Ubuntu --exec true > /dev/null 2>&1 && break; echo "waiting for WSL ($i of 15)..."; sleep 20; done
        MSYS_NO_PATHCONV=1 WSLENV="MM_JOBS:MM_WORK:MM_FULL:MM_CACHE_MAX:$WSLENV" wsl.exe -d Ubuntu --cd "$root" -- bash tools/check/push.sh --checks 2>&1 | tr -d '\0'
        return "${PIPESTATUS[0]}"
    fi
    make selftest && bash tools/check/fastcheck.sh
}
g rev-parse --git-dir > /dev/null 2>&1 || { echo "not pushed: $GITDESC cannot read the repository here ($(g rev-parse --git-dir 2>&1 | head -n 1)); set GIT=<path of git.exe> and retry" >&2; exit 1; }
[ -z "$(g status --porcelain --untracked-files=no)" ] || { echo "not pushed: uncommitted changes, commit them first" >&2; exit 1; }

STAMPS=~/.mm-push-ok; mkdir -p "$STAMPS"
stamp="$STAMPS/$(pwd | md5sum | cut -c1-16)"   # one per checkout: the tree (HEAD:) that passed the checks
for attempt in 1 2 3; do
    g fetch -q origin || { echo "not pushed: git fetch failed ($GITDESC)" >&2; exit 1; }
    if ! up_to_date; then
        echo "origin/main moved: rebasing on it"
        g rebase origin/main > /dev/null 2>&1 || { g rebase --abort > /dev/null 2>&1; echo "not pushed: the rebase on origin/main conflicts, resolve it by hand" >&2; exit 1; }
    fi
    [ "$(g rev-list --count origin/main..HEAD)" -gt 0 ] || { echo "nothing to push"; exit 0; }
    tree=$(g rev-parse HEAD:)
    if [ "$(cat "$stamp" 2> /dev/null)" = "$tree" ]; then
        echo "the checks already passed on this tree ($tree): not repeated"
    else
        run_checks || { echo "not pushed: the checks failed" >&2; exit 1; }
        echo "$tree" > "$stamp"
    fi
    unset MM_FULL   # a second attempt only has to check what the rebase brought: the incremental fastcheck
    g fetch -q origin || { echo "not pushed: git fetch failed ($GITDESC); the checks passed on this tree, run it again" >&2; exit 1; }
    if ! up_to_date; then
        echo "origin/main moved during the checks (attempt $attempt)"
        continue
    fi
    if g push origin HEAD:main; then
        echo "pushed $(g rev-parse --short HEAD)"
        exit 0
    fi
    echo "the push was refused (attempt $attempt)"
done
echo "not pushed: origin/main kept moving, run it again (the checks of an unchanged tree are not repeated)" >&2
exit 1
