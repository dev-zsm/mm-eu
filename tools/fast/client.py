#!/usr/bin/env python3
"""Client of the match server (tools/fast/server.py); starts it when it is not running. Run in WSL; stdlib only.
  client.py match <seg> <fn> <file.c> [--flags "-O1 -g0"] [--json] [--no-disasm]   like tools/lib/match.py, plus the diff and a score
  client.py batch <seg> <fn> <file.c ...>|<cands.jsonl>|-  [--flags ...] [--disasm]   one JSON line per candidate as it finishes
        jsonl lines: {"id": "a", "source": "..."} or {"id": "a", "file": "x.c", "flags": "-O1", "seg": "code", "fn": "func_..."}
  client.py sync [--all] | stats | ping | scrub | stop | start | path
`sync` copies the headers, names and tools of the repository to the native mirror ~/mmfast/<name>/tree and restarts the server on it
(`--all`: the ROM files and assembly too, about 20 s); do it after changing include/ or config/ or tools/lib/ (sources are sent with
each request, they need no sync).
Used as a module: match(seg, fn, source=..., flags=...) -> dict, batch(seg, fn, [{"source": ...}]) -> iterator of dicts."""
import fcntl, hashlib, json, os, re, socket, subprocess, sys, time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
HOME = Path(os.environ.get("MM_FAST_HOME") or Path.home() / "mmfast")
RUN = HOME / f"{ROOT.name[:24]}-{hashlib.sha1(str(ROOT).encode()).hexdigest()[:8]}"   # one server per checkout, one machine-wide compile cap
MIRRORED = str(ROOT).startswith("/mnt/")   # the repository is on the Windows disk: serve from a native copy
TREE = RUN / "tree" if MIRRORED else ROOT
SOCK = RUN / "sock"
QUICK = ["--include=/tools/", "--include=/tools/lib/***", "--include=/tools/fast/***", "--include=/include/***", "--include=/config/***"]
BULK = ["--include=/extracted/", "--include=/extracted/*.bin", "--include=/build/", "--include=/build/boot.bin", "--include=/asm/",
        "--include=/asm/*/", "--include=/asm/overlays/*/", "--include=/asm/*/text.s", "--include=/asm/overlays/*/text.s"]   # ROM and size index


def sync(everything: bool = False) -> float:
    """Copy what the server reads to the native mirror (incremental); seconds taken. The tools, headers and names every time
    (a second or two); the ROM files and the assembly (about 20 s through /mnt/c) the first time or with everything=True.
    Nothing to do for a native checkout."""
    t = time.time()
    if MIRRORED:
        TREE.mkdir(parents=True, exist_ok=True)
        bulk = everything or not (TREE / "asm").exists()
        subprocess.run(["rsync", "-aL", "--delete", "--prune-empty-dirs", *QUICK, *(BULK if bulk else ()), "--exclude=*",
                        f"{ROOT}/", f"{TREE}/"], check=True)
    return time.time() - t


def _connect():
    s = socket.socket(socket.AF_UNIX)
    s.connect(str(SOCK))
    return s


def start():
    """Start the server unless one answers; returns when it does."""
    RUN.mkdir(parents=True, exist_ok=True)
    with open(RUN / "start.lock", "a+") as lock:
        fcntl.flock(lock, fcntl.LOCK_EX)   # several agents starting at once: one server
        try:
            _connect().close()
            return
        except OSError:
            pass
        if not (TREE / "tools/fast/server.py").exists():
            sync()
        subprocess.Popen([sys.executable, str(TREE / "tools/fast/server.py"), str(RUN)], stdin=subprocess.DEVNULL,
                         stdout=open(RUN / "log", "a"), stderr=subprocess.STDOUT, start_new_session=True)
        for _ in range(100):
            time.sleep(0.1)
            try:
                _connect().close()
                return
            except OSError:
                pass
    raise SystemExit(f"the server did not start, see {RUN}/log")


def connect():
    for i in range(4):
        try:
            return _connect()
        except OSError:
            if i == 0:
                start()
            else:
                time.sleep(0.3)   # a reload is in progress
    raise SystemExit(f"cannot reach the server, see {RUN}/log")


def request(req: dict):
    """Send one request, yield the answers (one per line) until the end of the exchange."""
    s = connect()
    s.sendall((json.dumps(req) + "\n").encode())
    n = len(req.get("candidates", ())) if req.get("op") == "batch" else 1
    with s, s.makefile("r") as f:
        for line in f:
            r = json.loads(line)
            yield r
            if "done" in r or req.get("op") != "batch" and n == 1:
                return


def local(p: str) -> Path:
    """A path as typed on Windows (C:\\x\\y.c) or in WSL."""
    m = re.match(r"([A-Za-z]):[\\/](.*)", p)
    return Path(f"/mnt/{m.group(1).lower()}/{m.group(2).replace(chr(92), '/')}") if m else Path(p)


def match(seg: str, fn: str, source: str = None, file: str = None, flags: str = None, **kw) -> dict:
    text = source if source is not None else local(file).read_text()
    return next(request({"op": "match", "seg": seg, "fn": fn, "source": text, "flags": flags, **kw}))


def batch(seg: str, fn: str, candidates: list, **kw):
    cands = [{**c, "source": c["source"] if c.get("source") is not None else local(c["file"]).read_text()} for c in candidates]
    for r in request({"op": "batch", "seg": seg, "fn": fn, "candidates": cands, **kw}):
        if "done" not in r:
            yield r


def human(r: dict, fn: str) -> str:
    if r["status"] == "ERROR":
        return f"{fn}: ERROR {r.get('error', '')}"
    if r["match"]:
        return f"{fn}: MATCH ({r['rom_len']:#x} bytes) [{r['ms']:g} ms{'' if r['compiled'] else ', cached'}]"
    head = (f"{fn}: SIZE DIFFERS (rom {r['rom_len']:#x}, ours {r['our_len']:#x})" if r["status"] == "SIZE"
            else f"{fn}: {r['diff']}/{r['rom_len'] // 4} instructions differ, first at +{r['first'][0]:#x}")
    head += f" score {r['score']:g} (hard {r['hard']}, moved {r['moved']}, reg {r['reg']}, edit {r['edit']}) [{r['ms']:g} ms]"
    return "\n".join([head] + [f"  +{l['off']:#06x}  rom: {l['rom']:<34} ours: {l['ours']}" for l in r.get("lines", [])])


def cli(argv: list) -> int:
    flags = disasm = js = None
    args = []
    it = iter(argv)
    for a in it:
        if a == "--flags":
            flags = next(it)
        elif a == "--json":
            js = True
        elif a == "--disasm":
            disasm = True
        elif a == "--no-disasm":
            disasm = False
        else:
            args.append(a)
    cmd, args = (args or ["help"])[0], args[1:]
    if cmd == "path":
        print(RUN)
    elif cmd == "start":
        start()
        print(next(request({"op": "stats"})))
    elif cmd == "sync":
        print(f"synced in {sync('--all' in args):.1f} s")
        print(next(request({"op": "reload"})))
    elif cmd in ("stats", "ping", "scrub", "stop"):
        print(json.dumps(next(request({"op": cmd}))))
    elif cmd == "match" and len(args) == 3:
        r = match(args[0], args[1], file=args[2], flags=flags, **({} if disasm is None else {"disasm": disasm}))
        print(json.dumps(r) if js else human(r, args[1]))
        return 0 if r["match"] else 1
    elif cmd == "batch" and len(args) >= 3:
        seg, fn, rest = args[0], args[1], args[2:]
        if len(rest) == 1 and (rest[0] == "-" or rest[0].endswith(".jsonl")):
            lines = sys.stdin if rest[0] == "-" else open(local(rest[0]))
            cands = [json.loads(l) for l in lines if l.strip()]
        else:
            cands = [{"id": p, "file": p} for p in rest]
        best = None
        for r in batch(seg, fn, cands, flags=flags, disasm=bool(disasm)):
            print(json.dumps(r), flush=True)
            if r["status"] != "ERROR" and (best is None or r["score"] < best["score"]):
                best = r
        if best:
            print(f"best: {best['id']} score {best['score']:g} {best['status']}", file=sys.stderr)
        return 0 if best and best["match"] else 1
    else:
        print(__doc__)
        return 2
    return 0


if __name__ == "__main__":
    try:
        sys.exit(cli(sys.argv[1:]))
    except FileNotFoundError as e:
        sys.exit(f"{e.strerror}: {e.filename}")
