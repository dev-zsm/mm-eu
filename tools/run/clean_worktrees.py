#!/usr/bin/env python3
"""List the agent worktrees of .claude/worktrees, so that the safe ones can be removed by hand. Run on Windows (the git that owns the worktrees).
usage: clean_worktrees.py [--no-size] [--idle-days N=1] [--remove-safe]
Per worktree: branch, uncommitted changes (tracked / untracked files), commits that are not on origin/main, last activity (the newest of the
last commit, of the files git sees as changed and of the reflog of the worktree), size (the links to the folders of the main
checkout, asm/ extracted/ build/ ..., are not followed or counted) and a verdict: SAFE (nothing uncommitted, nothing unpushed, idle for more
than N days), else the reason it is not.
--remove-safe removes the SAFE ones only: the links are taken out first (a link is removed, never its target), then `git worktree remove`
(which itself refuses a worktree with changes); the branches are kept. Without it nothing is ever deleted."""
import argparse, os, subprocess, sys, time
from pathlib import Path


def git(*a, cwd=None):
    r = subprocess.run(["git", "--no-optional-locks", *a], cwd=cwd, capture_output=True, text=True)   # `status` must not rewrite the index: that is the activity it measures
    return r.stdout.strip() if r.returncode == 0 else ""


def is_link(e):
    return e.is_symlink() or (hasattr(e, "is_junction") and e.is_junction())


def size(path: Path) -> int:
    total, stack = 0, [path]
    while stack:
        try:
            with os.scandir(stack.pop()) as it:
                for e in it:
                    if is_link(e):
                        continue
                    if e.is_dir(follow_symlinks=False):
                        stack.append(e.path)
                    else:
                        total += e.stat(follow_symlinks=False).st_size
        except OSError:
            pass
    return total


def links(path: Path):
    """The links of the worktree (asm, extracted, build, tools/vendor ...): the top folders and tools/vendor."""
    out = []
    for p in [*path.iterdir(), path / "tools" / "vendor"]:
        try:
            if p.is_symlink() or p.is_junction():
                out.append(p)
        except OSError:
            pass
    return out


def worktrees(root: Path):
    found, cur = [], {}
    for line in git("worktree", "list", "--porcelain", cwd=root).splitlines() + [""]:
        if not line:
            if cur.get("worktree"):
                found.append(cur)
            cur = {}
        else:
            k, _, v = line.partition(" ")
            cur[k] = v
    return [w for w in found if "/.claude/worktrees/" in w["worktree"].replace("\\", "/")]


def inspect(w, idle_days, with_size):
    p = Path(w["worktree"])
    gitdir = Path(git("rev-parse", "--git-dir", cwd=p) or ".")
    gitdir = gitdir if gitdir.is_absolute() else p / gitdir
    status = git("status", "--porcelain", cwd=p).splitlines()
    tracked = [l for l in status if not l.startswith("??")]
    untracked = [l for l in status if l.startswith("??")]
    ahead = int(git("rev-list", "--count", "origin/main..HEAD", cwd=p) or 0)
    times = [int(git("log", "-1", "--format=%ct", cwd=p) or 0)]
    for l in status:
        try:
            times.append(int((p / l[3:].strip('"')).stat().st_mtime))
        except OSError:
            pass
    try:   # the reflog of HEAD moves with commits, checkouts and rebases of the worktree, not with a `git status` (the index does)
        times.append(int((gitdir / "logs" / "HEAD").stat().st_mtime))
    except OSError:
        pass
    last = max(times)
    idle = (time.time() - last) / 86400
    why = []
    if tracked or untracked:
        why.append(f"{len(tracked)} changed + {len(untracked)} untracked files")
    if ahead:
        why.append(f"{ahead} commits not on origin/main")
    if idle <= idle_days:
        why.append(f"active {idle * 24:.0f} h ago")
    return {"path": p, "branch": w.get("branch", "(detached)").replace("refs/heads/", ""), "tracked": len(tracked), "untracked": len(untracked),
            "ahead": ahead, "last": last, "idle": idle, "size": size(p) if with_size else None, "safe": not why, "why": why}


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--no-size", action="store_true")
    ap.add_argument("--idle-days", type=float, default=1)
    ap.add_argument("--remove-safe", action="store_true")
    a = ap.parse_args()
    root = Path(git("rev-parse", "--path-format=absolute", "--git-common-dir", cwd=Path(__file__).resolve().parent)).parent
    git("fetch", "-q", "origin", cwd=root)
    rows = [inspect(w, a.idle_days, not a.no_size) for w in worktrees(root)]
    for r in sorted(rows, key=lambda r: r["last"]):
        when = time.strftime("%Y-%m-%d %H:%M", time.localtime(r["last"]))
        mb = "" if r["size"] is None else f"{r['size'] / 2**20:8.0f} MB"
        print(f"{'SAFE' if r['safe'] else 'keep'}  {r['path'].name:34} {r['branch'][:38]:38} last {when} ({r['idle']:.1f} d) {mb}  "
              f"changed {r['tracked']} untracked {r['untracked']} unpushed {r['ahead']}" + ("" if r["safe"] else "  <- " + "; ".join(r["why"])))
    safe = [r for r in rows if r["safe"]]
    print(f"{len(rows)} worktrees, {len(safe)} safe to remove" + ("" if a.remove_safe else " (nothing is removed: --remove-safe does it)"))
    if a.remove_safe:
        for r in safe:
            for link in links(r["path"]):
                os.rmdir(link) if link.is_junction() else link.unlink()   # the link only, never its target
            res = subprocess.run(["git", "worktree", "remove", str(r["path"])], cwd=root, capture_output=True, text=True)
            print(("removed " if res.returncode == 0 else "NOT removed ") + r["path"].name + ("" if res.returncode == 0 else ": " + res.stderr.strip()))


if __name__ == "__main__":
    sys.exit(main())
