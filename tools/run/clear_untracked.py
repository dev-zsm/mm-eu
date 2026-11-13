#!/usr/bin/env python3
"""Delete the untracked files that a ref (default origin/main) tracks: they would stop a rebase onto it ("untracked working tree files would be
overwritten"). A round that fails keeps what it wrote (headers, drafts), and the same files then arrive committed from another machine, so
every later rebase of the rounds failed ("rebase failed, local commits dropped") until somebody cleaned by hand.
usage: clear_untracked.py [ref] [path ...]     (paths default to src include config)"""
import subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def git(*a):
    r = subprocess.run(["git", *a], cwd=ROOT, capture_output=True, text=True)
    return r.stdout.splitlines() if r.returncode == 0 else []


def clashing(untracked, tracked):
    """The untracked paths that the ref has as files."""
    tracked = set(tracked)
    return [p for p in untracked if p in tracked]


def main():
    args = sys.argv[1:]
    ref = args[0] if args else "origin/main"
    paths = args[1:] or ["src", "include", "config"]
    bad = clashing(git("ls-files", "-o", "--exclude-standard", "--", *paths), git("ls-tree", "-r", "--name-only", ref, "--", *paths))
    for p in bad:
        (ROOT / p).unlink(missing_ok=True)
    if bad:
        print(f"{len(bad)} untracked files that {ref} has were deleted before the rebase")


if __name__ == "__main__":
    main()
