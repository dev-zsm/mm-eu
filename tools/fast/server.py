#!/usr/bin/env python3
"""Persistent match server, run in WSL (started by client.py when needed). usage: server.py <run directory>
Keeps the ROM, the size index, the names and the object cache of tools/lib/match.py warm in one process and answers JSON lines on a
unix socket <run directory>/sock. At most MM_JOBS (default 3) compilers run at once for every server of the machine (flock on
<MM_FAST_HOME>/slots/N); the other requests wait in a queue. It exits after MM_FAST_IDLE seconds (default 7200) without a request.
Requests, one JSON object per line (answers are one line each, in completion order, carrying the "id" of the request/candidate):
  {"op": "match", "seg", "fn", "source" | "file", "flags": "-O1 -g0", "disasm": true, "max_diffs": 8}
  {"op": "batch", "seg", "fn", "candidates": [{"id", "source" | "file", "flags", "seg", "fn"}]}  then {"done": N}
  {"op": "ping" | "stats" | "reload" | "scrub" | "stop"}
An answer: {"id", "status": MATCH | DIFF | SIZE | ERROR, "match", "ms", "compiled", "rom_len", "our_len", "diff", "score", "reg", "moved",
"hard", "edit", "size", "first", "lines", "error"} (see tools/lib/score.py)."""
import collections, contextlib, fcntl, hashlib, json, os, shlex, socketserver, subprocess, sys, tempfile, threading, time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(d) for d in Path(__file__).resolve().parents[1].glob("*/") if d.name != "vendor"]
import match  # noqa: E402
import objcache  # noqa: E402
import score  # noqa: E402

JOBS = max(1, int(os.environ.get("MM_JOBS") or 3))
HOME = Path(os.environ.get("MM_FAST_HOME") or Path.home() / "mmfast")
IDLE = int(os.environ.get("MM_FAST_IDLE") or 7200)
SEM = threading.BoundedSemaphore(JOBS)
LOCK = threading.Lock()
STATE = collections.Counter()      # waiting, running, requests, compiled, cached, matches, errors, ms
LOCAL = threading.local()
BORN, LAST = time.time(), [time.time()]
RUN = Path(sys.argv[1]) if len(sys.argv) > 1 else HOME / "run"
TMP = RUN / "tmp"


def take_slot():
    """A free machine-wide compile slot: an exclusively locked file, released by the system if this process dies."""
    (HOME / "slots").mkdir(parents=True, exist_ok=True)
    while True:
        for i in range(JOBS):
            f = open(HOME / "slots" / str(i), "a+")
            try:
                fcntl.flock(f, fcntl.LOCK_EX | fcntl.LOCK_NB)
                return f
            except OSError:
                f.close()
        time.sleep(0.05)


@contextlib.contextmanager
def gate():
    """Held while a compiler runs: JOBS at a time in this server, JOBS in all the servers of the machine."""
    with LOCK:
        STATE["waiting"] += 1
    SEM.acquire()
    f = None
    try:
        f = take_slot()
        with LOCK:
            STATE["waiting"] -= 1
            STATE["running"] += 1
            STATE["peak"] = max(STATE["peak"], STATE["running"])
        LOCAL.compiled = True
        yield
    finally:
        with LOCK:
            STATE["running" if f else "waiting"] -= 1
        if f:
            f.close()
        SEM.release()


objcache.GATE, objcache.QUIET = gate, True


def disassemble(code: bytes) -> list:
    TMP.mkdir(parents=True, exist_ok=True)
    with tempfile.NamedTemporaryFile(dir=TMP, suffix=".bin") as f:
        f.write(code)
        f.flush()
        out = subprocess.run(["mips-linux-gnu-objdump", "-b", "binary", "-m", "mips:4300", "-EB", "-D", "-M", "no-aliases", f.name],
                             capture_output=True).stdout.decode(errors="replace")
    return [l.split("\t", 2)[-1].strip() for l in out.splitlines() if l[:1] == " " and ":" in l]


def candidate_file(seg: str, fn: str, text: str) -> Path:
    """A private copy of the source under src/[overlays/NNNN/] so that match.real_name finds the names of its segment."""
    d = TMP / "src" / (f"overlays/{seg[3:]}" if seg.startswith("ovl") else seg)
    d.mkdir(parents=True, exist_ok=True)
    return d / f"{hashlib.sha1(text.encode()).hexdigest()[:12]}_{threading.get_ident()}.c"


def do_match(r: dict) -> dict:
    t0 = time.time()
    LOCAL.compiled = False
    out = {"id": r.get("id")}
    cfile = None
    try:
        seg, fn = r["seg"], r["fn"]
        text = r["source"] if r.get("source") is not None else Path(r["file"]).read_text()
        text = text.replace("\r\n", "\n")
        cfile = candidate_file(seg, fn, text)
        cfile.write_text(text)
        if r.get("flags"):
            lead = shlex.split(r["flags"]) if isinstance(r["flags"], str) else list(r["flags"])
            flags = lead + match.DEFAULT_FLAGS[3:]
        else:
            flags = match.file_flags(cfile)
        want, _ = match.original(seg, fn)
        got, masks = match.compiled(cfile, fn, flags, len(want))
        if len(got) > len(want) and not any(got[len(want):]):  # IDO pads .text to 16 bytes
            got = got[:len(want)]
        a, b = match.mask(want, masks), match.mask(got, masks)
        out.update(score.score(a, b, int(r.get("max_diffs", 8))), rom_len=len(want), our_len=len(got))
        out["match"] = out["diff"] == 0 and len(want) == len(got)
        out["status"] = "MATCH" if out["match"] else "SIZE" if len(want) != len(got) else "DIFF"
        if not out["match"] and r.get("disasm", True):
            w, g = disassemble(want), disassemble(got)
            out["lines"] = [{"off": o, "rom": w[o // 4] if o // 4 < len(w) else "", "ours": g[o // 4] if o // 4 < len(g) else ""}
                            for o in out["first"]]
    except subprocess.CalledProcessError as e:
        out.update(status="ERROR", match=False, error=(e.stderr or str(e))[-1500:])
    except Exception as e:  # noqa: BLE001  a bad request must not kill the connection
        out.update(status="ERROR", match=False, error=f"{type(e).__name__}: {e}")
    finally:
        if cfile is not None:
            cfile.unlink(missing_ok=True)
    ms = round((time.time() - t0) * 1000, 1)
    out.update(ms=ms, compiled=LOCAL.compiled)
    with LOCK:
        STATE["requests"] += 1
        STATE["compiled" if LOCAL.compiled else "cached"] += 1
        STATE["matches"] += out["match"]
        STATE["errors"] += out["status"] == "ERROR"
        STATE["ms"] += ms
    return out


def stats() -> dict:
    with LOCK:
        s = dict(STATE)
    n = max(1, s.get("requests", 0))
    return {"ok": True, "jobs": JOBS, "uptime": round(time.time() - BORN), "root": str(ROOT), "pid": os.getpid(),
            "avg_ms": round(s.get("ms", 0) / n, 1), **{k: v for k, v in s.items() if k != "ms"}}


class Handler(socketserver.StreamRequestHandler):
    def send(self, obj):
        with self.wlock:
            try:
                self.wfile.write((json.dumps(obj) + "\n").encode())
                self.wfile.flush()
            except OSError:
                pass

    def handle(self):
        self.wlock = threading.Lock()
        for line in self.rfile:
            LAST[0] = time.time()
            try:
                r = json.loads(line)
                op = r.get("op", "match")
            except ValueError as e:
                self.send({"ok": False, "status": "ERROR", "error": f"bad json: {e}"})
                continue
            if op == "match":
                self.send(do_match(r))
            elif op == "batch":
                cands = [{**{k: r[k] for k in ("seg", "fn", "flags", "disasm", "max_diffs") if k in r}, **c} for c in r["candidates"]]
                for i, c in enumerate(cands):
                    c.setdefault("id", i)
                with ThreadPoolExecutor(min(len(cands), 64) or 1) as ex:
                    for f in [ex.submit(lambda c=c: self.send(do_match(c))) for c in cands]:
                        f.result()
                self.send({"done": len(cands)})
            elif op == "ping":
                self.send({"ok": True, "pong": True})
            elif op == "stats":
                self.send(stats())
            elif op == "scrub":
                self.send({"ok": True, "deleted": objcache.scrub()})
            elif op in ("reload", "stop"):
                self.send({"ok": True, op: True})
                threading.Thread(target=finish, args=(op,), daemon=True).start()
            else:
                self.send({"ok": False, "error": f"unknown op {op}"})


def finish(op):
    time.sleep(0.2)   # the answer is on its way
    if op == "reload":   # new tools, headers or names: a fresh process reads them all again
        os.execv(sys.executable, [sys.executable, str(Path(__file__).resolve()), *sys.argv[1:]])
    (RUN / "sock").unlink(missing_ok=True)
    os._exit(0)


class Server(socketserver.ThreadingMixIn, socketserver.UnixStreamServer):
    daemon_threads = True
    request_queue_size = 128


def main():
    RUN.mkdir(parents=True, exist_ok=True)
    os.chdir(ROOT)   # flags such as -Iinclude/mm are relative to the root, as when match.py runs there
    sock = RUN / "sock"
    sock.unlink(missing_ok=True)   # the client holds the start lock: a socket still there is a dead server's
    srv = Server(str(sock), Handler)
    objcache.scrub()
    print(f"mm fast server: pid {os.getpid()} root {ROOT} jobs {JOBS} cache {objcache.CACHE}", flush=True)

    def idle():
        while time.time() - LAST[0] < IDLE:
            time.sleep(30)
        finish("stop")
    threading.Thread(target=idle, daemon=True).start()
    srv.serve_forever()


if __name__ == "__main__":
    main()
