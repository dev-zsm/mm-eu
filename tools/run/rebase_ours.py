#!/usr/bin/env python3
"""Rebase the local commits onto a ref (default origin/main), the other side winning every conflict, structural ones included.
`git rebase -X ours` settles the conflicts inside a file, but not a file that one side modified and the other deleted (a wip draft that an
agent promoted while a round of the VPS changed it): the rebase stopped, push.sh dropped the whole round ("rebase failed, local commits
dropped") and the next push of the same kind did it again. Here such a path takes the state of the ref (its version when it has the file,
else it is deleted) and the rebase goes on. Exit code 0 when HEAD sits on the ref, else the rebase is aborted and the exit code is 1.
usage: rebase_ours.py [ref]"""
import subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def git(*a, cwd=ROOT, env=None):
    return subprocess.run(["git", "-c", "core.editor=true", *a], cwd=cwd, capture_output=True, text=True, env=env)


def rebase_ours(ref="origin/main", cwd=ROOT):
    r = git("rebase", "-q", "-X", "ours", ref, cwd=cwd)
    for _ in range(200):   # one round per local commit, a few conflicts each
        if r.returncode == 0:
            return True
        unmerged = git("diff", "--name-only", "--diff-filter=U", cwd=cwd).stdout.split("\n")
        unmerged = [p for p in unmerged if p]
        if not unmerged:
            break   # stopped for another reason (an empty commit is the usual one: skip it)
        for p in unmerged:
            if git("checkout", "--ours", "--", p, cwd=cwd).returncode == 0:
                git("add", "--", p, cwd=cwd)
            else:
                git("rm", "-q", "-f", "--", p, cwd=cwd)
        r = git("rebase", "--continue", cwd=cwd)
        if r.returncode != 0 and "No changes" in (r.stdout + r.stderr):
            r = git("rebase", "--skip", cwd=cwd)
    git("rebase", "--abort", cwd=cwd)
    return False


if __name__ == "__main__":
    sys.exit(0 if rebase_ours(*sys.argv[1:2]) else 1)
