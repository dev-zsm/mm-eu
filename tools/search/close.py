#!/usr/bin/env python3
"""Adaptive near-miss closer: take a C draft that is a few instructions away from the ROM and search source-level mutations
(tools/search/close_mut.py: operand order, statement order, declaration order, padding, types, aliases, ternaries, loops, IDO flags...)
until IDO 7.1 gives the bytes of the ROM, and learn which mutation solved which kind of difference.
Run in WSL (venv). MM_JOBS caps the compiler workers; the object cache is shared and capped (tools/lib/objcache.py).
usage: close.py try <seg> <fn> [file.c] [--time S=90] [--cands N=1500] [--beam W=5] [--per-node K=140] [--permute S] [--promote] [--seed N]
       close.py sweep <ovlAAAA-BBBB|ovlNNNN|code|boot> [--max-diff N=8] [--max-size HEX=0x300] [--time S=60] [--limit K] [--no-promote] [--skip-tried]
       close.py score <seg> <fn> <file.c>        distance of a draft to the ROM and the kind of difference
       close.py promote <seg> <fn>               move build/close_wins/<seg>/<fn>.c to src/ (match.py MATCH and the style rules first)
       close.py learn [--show]                   merge the wins found by other runs into config/search/close_stats.json and print the table
       close.py record <seg> <fn> <mutator,...>  note a fix found by hand (a mutator name of close_mut.py, or `permuter`)
Search: beam search over mutation sequences, scored by the number of differing instructions (finer: opcode changes weigh more); a
mutation whose object code is already known is dropped, so only changes that move the compiler's output are explored. The order in
which mutations are tried comes from config/search/close_stats.json (which mutator helped or won, and in which kind of difference:
register swap, stack frame, size, order...). A winner is written raw to build/close_wins/<seg>/<fn>.c with the list of mutations
(<fn>.json), the useless hunks are reverted one by one, and `promote` files it in src/ in the project style."""
import difflib, hashlib, json, os, random, re, shutil, subprocess, sys, time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(d) for d in Path(__file__).resolve().parents[1].glob("*/") if d.name != "vendor"]
import check_style  # noqa: E402
try:
    import client as fastclient  # noqa: E402
except ImportError:
    fastclient = None
import close_mut as mut  # noqa: E402
import match  # noqa: E402
import names as names_mod  # noqa: E402
import objcache  # noqa: E402
import srcpath  # noqa: E402

STATS = ROOT / "config/search/close_stats.json"
RECIPES = ROOT / "tools/search/recipes/default.json"
WINS = ROOT / "build/close_wins"
TMP = ROOT / "build/close_tmp"
EXTRA = ["-I" + str(ROOT / "tools/vendor/m2c")]
objcache.print = lambda *a, **k: None   # a candidate that does not compile is just a dead end: no compiler noise


def recipes() -> dict:
    return json.loads(RECIPES.read_text())


# ---------------------------------------------------------------- the target and the distance to it
class Target:
    def __init__(self, seg, fn):
        self.seg, self.fn = seg, fn
        self.want, _ = match.original(seg, fn)
        self.dir = TMP / f"{seg}_{fn}"
        self.dir = self.dir / "src" / "overlays" / seg[3:] if seg.startswith("ovl") else self.dir
        self.dir.mkdir(parents=True, exist_ok=True)

    def defined(self, text):
        """The name the text defines for the function: the registered name, else the address name."""
        real = match.real_name(self.dir / "x.c", self.fn)
        return real if re.search(r"\b" + re.escape(real) + r"\s*\([^;{]*\)\s*\{", text) else self.fn

    def score(self, text):
        """(score, exact, tags, signature) or None when the text does not compile or lacks the function."""
        if fastclient is not None and not os.environ.get("MM_CLOSE_INPROC"):
            return self.score_many([text])[0]
        return self.score_local(text)

    def score_local(self, text):
        path = self.dir / f"c_{hashlib.sha1(text.encode()).hexdigest()[:14]}.c"
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text)
        try:
            got, masks = match.compiled(path, self.fn, match.file_flags(path) + EXTRA, len(self.want))
        except Exception:
            return None
        finally:
            path.unlink(missing_ok=True)
        return compare(self.want, got, masks)

    def score_many(self, texts, deadline=None):
        """One result per text (None: does not compile, or out of time). The match server (tools/fast) compiles the batch on its own
        slots; without it (MM_CLOSE_INPROC=1, or the server does not start) the texts are compiled here."""
        if fastclient is None or os.environ.get("MM_CLOSE_INPROC"):
            def one(t):
                return None if deadline and time.time() > deadline else self.score_local(t)
            with ThreadPoolExecutor(objcache.JOBS) as ex:
                return list(ex.map(one, texts))
        out = [None] * len(texts)
        for k in range(0, len(texts), 96):
            if deadline and time.time() > deadline:
                break
            cands = [{"id": k + n, "source": project_form(t)} for n, t in enumerate(texts[k:k + 96])]
            for r in fastclient.batch(self.seg, self.fn, cands, disasm=True, max_diffs=200):
                out[r["id"]] = from_server(r)
        return out

    def cleanup(self):
        shutil.rmtree(TMP / f"{self.seg}_{self.fn}", ignore_errors=True)


def from_server(r):
    """(score, exact, tags, signature) from an answer of the match server (tools/lib/score.py); None for an error."""
    if r["status"] == "ERROR":
        return None
    sig = hashlib.sha1(json.dumps([r["first"], [l["ours"] for l in r.get("lines", [])], r["our_len"]]).encode()).hexdigest()[:12]
    if r["match"]:
        return 0.0, True, [], sig
    tags = (["size+" if r["size"] > 0 else "size-"] if r["size"] else []) + (["reg"] if r["reg"] else []) + (["order"] if r["moved"] else []) \
        + (["other"] if r["hard"] else [])
    return r["score"] + 0.01 * r["diff"], False, tags, sig


def compare(want, got, masks):
    if len(got) > len(want) and not any(got[len(want):]):
        got = got[:len(want)]
    a, b = match.mask(want, masks), match.mask(got, masks)
    sig = hashlib.sha1(bytes(str(b), "ascii")).hexdigest()[:12]
    if a == b:
        return 0.0, True, [], sig
    if len(a) == len(b):
        bad = [i for i in range(len(a)) if a[i] != b[i]]
        fine = sum(2 if a[i] >> 26 != b[i] >> 26 else 1 for i in bad)
        return len(bad) + 0.02 * fine, False, tags_of(a, b, bad), sig
    d = sum(max(i2 - i1, j2 - j1) for op, i1, i2, j1, j2 in difflib.SequenceMatcher(None, a, b, autojunk=False).get_opcodes() if op != "equal")
    return d + 0.5 + 0.02 * d, False, ["size+" if len(b) > len(a) else "size-"] + (["frame"] if a[:1] != b[:1] and a[0] >> 16 == 0x27BD else []), sig


def tags_of(a, b, bad):
    """The kind of difference between two same-length instruction lists: what the learning keys on."""
    tags = set()
    if sorted(a) == sorted(b):
        tags.add("order")
    for i in bad:
        x, y = a[i], b[i]
        if x >> 26 != y >> 26:
            tags.add("opcode")
        elif x >> 26 in (4, 5, 20, 21) and ((x >> 21) & 31, (x >> 16) & 31) == ((y >> 16) & 31, (y >> 21) & 31):
            tags.add("opswap")
        elif (x >> 26 == 0 and (x ^ y) & 0x7FF == 0) or (x >> 26 != 0 and (x ^ y) & 0xFFFF == 0):
            tags.add("reg")
        elif x >> 26 != 0 and (x ^ y) >> 16 == 0:
            tags.add("stack" if (x >> 21) & 31 == 29 else "imm")
        else:
            tags.add("other")
    return sorted(tags)


# ---------------------------------------------------------------- learning
class Stats:
    def __init__(self):
        self.d = self.load()
        self.base = json.loads(json.dumps(self.d))
        self.rec = recipes()

    @staticmethod
    def load():
        try:
            d = json.loads(STATS.read_text())
        except (OSError, ValueError):
            d = {}
        return {"mut": d.get("mut", {}), "ctx": d.get("ctx", {}), "wins": d.get("wins", [])}

    def count(self, mname, key, n=1):
        self.d["mut"].setdefault(mname, {"tried": 0, "helped": 0, "wins": 0})[key] += n

    def win(self, seg, fn, seq, tags):
        self.d["wins"].append({"seg": seg, "fn": fn, "seq": seq, "ctx": tags})
        for m in {s.split(":")[0].split("@")[0] for s in seq}:
            self.count(m, "wins")
            for t in tags or ["none"]:
                c = self.d["ctx"].setdefault(t, {})
                c[m] = c.get(m, 0) + 1

    def weight(self, mname, tags):
        m = self.d["mut"].get(mname, {})
        w = self.rec["weights"].get(mname, 1.0)
        w *= 1 + 8 * (m.get("helped", 0) + 1) / (m.get("tried", 0) + 25)
        w *= 1 + 2 * m.get("wins", 0)
        for t in tags:
            w *= 1 + 3 * self.d["ctx"].get(t, {}).get(mname, 0)
        return w

    def save(self):
        """Merge with what other runs wrote meanwhile: only the changes of this process are added."""
        cur = self.load()
        for m, v in self.d["mut"].items():
            for k, n in v.items():
                delta = n - self.base["mut"].get(m, {}).get(k, 0)
                cur["mut"].setdefault(m, {"tried": 0, "helped": 0, "wins": 0})[k] = cur["mut"].get(m, {}).get(k, 0) + delta
        for t, v in self.d["ctx"].items():
            for m, n in v.items():
                delta = n - self.base["ctx"].get(t, {}).get(m, 0)
                cur["ctx"].setdefault(t, {})[m] = cur["ctx"].get(t, {}).get(m, 0) + delta
        known = {(w["seg"], w["fn"]) for w in cur["wins"]}
        cur["wins"] += [w for w in self.d["wins"][len(self.base["wins"]):] if (w["seg"], w["fn"]) not in known]
        STATS.parent.mkdir(parents=True, exist_ok=True)
        STATS.write_text(json.dumps(cur, indent=1, sort_keys=True) + "\n")
        self.d, self.base = cur, json.loads(json.dumps(cur))


# ---------------------------------------------------------------- the search
def norm(text):
    return re.sub(r"\s+", " ", text)


def pick(vs, k, tags, stats, rng):
    """k variants drawn without replacement, the likelier mutators first (a mutator with many sites shares its weight among them)."""
    per = {}
    for v in vs:
        per[v[0]] = per.get(v[0], 0) + 1
    keyed = sorted(vs, key=lambda v: -(rng.random() ** (per[v[0]] ** 0.5 / stats.weight(v[0], tags))))
    return keyed[:k]


class Node:
    __slots__ = ("score", "text", "steps", "visits", "dead")

    def __init__(self, score, text, steps):
        self.score, self.text, self.steps, self.visits, self.dead = score, text, steps, 0, False

    def priority(self):
        """Best first: the distance, a little per step taken (short fixes read better), more for a node already expanded."""
        return self.score + 0.4 * len(self.steps) + 1.5 * self.visits


def search(tg, text, a, stats, log=print):
    """Best-first beam search from `text`: every round expands the `beam` most promising nodes of everything seen so far, so a node that
    is not the best yet can come back when the neighbourhood of the best is exhausted. Returns (winning text, steps, tags of the start),
    or (best text, None, tags) when the time or the candidate budget runs out."""
    rng = random.Random(a.seed)
    start = tg.score(text)
    if start is None:
        log(f"{tg.fn}: the draft does not compile or does not define the function")
        return text, None, []
    ctx = start[2]
    if start[1]:
        return text, [], ctx
    deadline = time.time() + a.time
    archive = [Node(start[0], text, [])]
    seen, sigs, ncand, best = {norm(text)}, {start[3]}, 0, archive[0]
    log(f"{tg.fn}: start {start[0]:.2f} {ctx}")
    while time.time() < deadline and ncand < a.cands:
        live = sorted((n for n in archive if not n.dead), key=lambda n: (n.priority(), rng.random()))[:a.beam]
        if not live:
            break
        kids = []
        for n in live:
            vs = [v for v in mut.variants(n.text, tg.defined(n.text)) if norm(v[2]) not in seen]
            n.visits += 1
            n.dead = len(vs) <= a.per_node
            for mname, site, new in pick(vs, a.per_node, ctx, stats, rng):
                seen.add(norm(new))
                kids.append((mname, site, new, n))
        kids = kids[:max(0, a.cands - ncand)]
        if not kids:
            continue
        res = tg.score_many([k[2] for k in kids], deadline)
        ncand += len(kids)
        for (mname, site, new, parent), r in zip(kids, res):
            if r is None:
                continue
            stats.count(mname, "tried")
            steps = parent.steps + [f"{mname}:{site}"]
            if r[1]:
                stats.count(mname, "helped")
                return new, steps, ctx
            if r[3] in sigs:
                continue   # the same object code as one already seen: nothing moved
            sigs.add(r[3])
            if r[0] < parent.score:
                stats.count(mname, "helped")
            archive.append(Node(r[0], new, steps))
            if r[0] < best.score:
                best = archive[-1]
                log(f"{tg.fn}: {best.score:.2f} after {ncand} candidates  {' > '.join(steps)}")
    log(f"{tg.fn}: stopped after {ncand} candidates, {len(sigs)} distinct object codes, {time.time() - deadline + a.time:.0f}s")
    return best.text, None, ctx


def minimise(tg, orig, win):
    """Revert, hunk by hunk, the parts of the winner that the match does not need (a plateau step can leave a useless change)."""
    a, b = orig.split("\n"), win.split("\n")
    cur = b
    for op, i1, i2, j1, j2 in reversed(difflib.SequenceMatcher(None, a, b, autojunk=False).get_opcodes()):
        if op == "equal":
            continue
        # the hunk's place in `cur` is unchanged since later hunks only touch the lines after it
        trial = cur[:j1] + a[i1:i2] + cur[j2:]
        r = tg.score("\n".join(trial))
        if r and r[1]:
            cur = trial
    return "\n".join(cur)


def reindent(text, name):
    """Body lines indented by their brace depth (4 spaces, `case` one level in): the mutations move and add lines."""
    loc = mut.locate(text, name)
    if not loc:
        return text
    bs, be = loc[2], loc[3]
    depth, cases, out = 1, [False], []
    for line in text[bs:be].split("\n"):
        s = line.strip()
        if not s or s.startswith("#"):
            out.append(s and line)
            continue
        lead = len(s) - len(s.lstrip("}"))
        for _ in range(lead):
            depth -= 1
            cases.pop() if len(cases) > 1 else None
        is_case = bool(re.match(r"(case\b.*|default)\s*:", s))
        out.append("    " * (depth + (1 if cases[-1] and not is_case else 0)) + s)
        if is_case:
            cases[-1] = True
        for c in s[lead:]:
            if c == "{":
                depth += 1
                cases.append(False)
            elif c == "}":
                depth -= 1
                cases.pop() if len(cases) > 1 else None
    return text[:bs] + "\n".join(out) + text[be:]


def project_form(text):
    text = text.replace('#include "m2c_macros.h"', '#include "m2c_compat.h"')
    return re.sub(r"^// STATUS:.*\n", "", text, flags=re.M)


def style_ok(text):
    return not any(pat.search(l) and not (exc and exc.search(l)) for l in text.splitlines() for _, pat, exc in check_style.RULES)


def strict_match(seg, fn, text):
    """What tools/lib/match.py says about the file, as a fresh process (the judge of the project)."""
    p = ROOT / "build" / f"close_final_{seg}_{fn}.c"
    p.write_text(text)
    try:
        r = subprocess.run([sys.executable, str(ROOT / "tools/lib/match.py"), seg, fn, str(p)], capture_output=True, text=True)
        if "MATCH" in r.stdout and r.returncode == 0 and "jtbl_" in match.asm_file(seg).read_text().split(f"glabel {fn}\n", 1)[-1].split("endlabel", 1)[0]:
            r = subprocess.run([sys.executable, str(ROOT / "tools/search/hard_jt.py"), "check", seg, fn, str(p)], capture_output=True, text=True)
            return r.stdout.strip().endswith("MATCH")   # a switch: the jump table must be the ROM's too
    finally:
        p.unlink(missing_ok=True)
    return "MATCH" in r.stdout and r.returncode == 0


def dest(seg, fn):
    return srcpath.overlay_dir(seg[3:]) / f"{fn}.c" if seg.startswith("ovl") else srcpath.path(seg, fn)


def promote(seg, fn, text):
    """File the winner in src/ if it matches (match.py) and obeys the style rules; returns (ok, message)."""
    tg = Target(seg, fn)
    try:
        text = project_form(text)
        if "typedef signed char s8;" in text:   # raw permuter output: the typedef block, Allman braces, two-space indents
            import tidy_perm
            tidy_perm.wins(seg).mkdir(parents=True, exist_ok=True)
            text = tidy_perm.tidy_text(seg, fn, text)[0]
        for step in (lambda x: re.sub(r"\belse\s*\n\s*if\b", "else if", x), lambda x: reindent(x, tg.defined(x))):
            tidy = step(text)
            text = tidy if (tidy == text or (tg.score(tidy) or (0, False))[1]) else text
        text = "\n".join(l.rstrip() for l in text.split("\n")).strip("\n") + "\n"
        d = dest(seg, fn)
        if d.exists():
            return False, f"{d.relative_to(ROOT)} already exists"
        if not style_ok(text):
            return False, "style rules broken"
        if not strict_match(seg, fn, text):
            return False, "match.py does not say MATCH"
        d.parent.mkdir(parents=True, exist_ok=True)
        d.write_text(text)
        wipdir = d.parent / "wip" if seg.startswith("ovl") else ROOT / "src" / seg / "wip"
        for stem in (fn, match.real_name(d, fn)):
            (wipdir / f"{stem}.c").unlink(missing_ok=True)
        return True, str(d.relative_to(ROOT))
    finally:
        tg.cleanup()


# ---------------------------------------------------------------- the permuter as a strategy
def permuter(seg, fn, text, seconds, log=print):
    """Run the decomp-permuter on the best draft when the mutations stall; returns the text it matched, or None."""
    try:
        import permute_list, permute_setup
    except Exception as e:   # the permuter needs its vendor tree
        log(f"{fn}: permuter unavailable ({e})")
        return None
    draft = permute_setup.draft(seg, fn)
    if not draft:
        return None
    saved = draft.read_text()
    try:
        draft.write_text(text)
        status = permute_list.run_one(seg, fn, int(seconds))
    except Exception as e:
        log(f"{fn}: permuter failed ({e})")
        return None
    finally:
        draft.write_text(saved)
    out = (permute_list.WINS / seg if seg.startswith("ovl") else permute_list.WINS) / f"{fn}.c"
    return out.read_text() if status.startswith("MATCH") and out.exists() else None


# ---------------------------------------------------------------- drivers
def find_draft(seg, fn):
    """The wip file or the m2c draft of a function; for an overlay function that has neither, m2c is run now."""
    import permute_list, permute_setup
    found = permute_setup.draft(seg, fn)
    if not found and seg.startswith("ovl"):
        text = match.asm_file(seg).read_text()
        chunk = next((c for c in re.split(r"(?=^nonmatching )", text, flags=re.M)[1:] if c.startswith(f"nonmatching {fn},")), None)
        if chunk and permute_list.make_draft(seg, fn, text[:text.index("nonmatching ")] + chunk):
            found = permute_setup.draft(seg, fn)
    return found


def record_win(seg, fn, text, steps, ctx, stats):
    d = WINS / seg
    d.mkdir(parents=True, exist_ok=True)
    (d / f"{fn}.c").write_text(text)
    (d / f"{fn}.json").write_text(json.dumps({"seg": seg, "fn": fn, "seq": steps, "ctx": ctx}, indent=1) + "\n")
    stats.win(seg, fn, steps, ctx)


def run_target(seg, fn, text, a, stats, log=print):
    """Search one function; returns (status, steps). status: MATCH, `best <score>` or `no compile`."""
    tg = Target(seg, fn)
    try:
        t0 = time.time()
        best, steps, ctx = search(tg, text, a, stats, log)
        first = tg.score(text) if a.permute else None
        if steps is None and a.permute and first and first[0] <= a.permute_max:
            log(f"{fn}: mutations stalled at {(tg.score(best) or (0,))[0]:.2f}, permuter for {a.permute}s")
            won = permuter(seg, fn, best, a.permute, log)
            if won and (tg.score(won) or (0, False))[1]:
                best, steps = won, ["permuter"]
        if steps is None:
            r = tg.score(best)
            return ("no compile" if r is None else f"best {r[0]:.2f}"), None
        win = minimise(tg, text, best) if steps != ["permuter"] else best
        record_win(seg, fn, win, steps, ctx, stats)
        log(f"{fn}: MATCH in {time.time() - t0:.0f}s  {' > '.join(steps) or 'draft as is'}")
        return "MATCH", steps
    finally:
        tg.cleanup()
        stats.save()


def cmd_try(a):
    seg, fn = a.args[:2]
    src = Path(a.args[2]) if len(a.args) > 2 else find_draft(seg, fn)
    if not src or not src.exists():
        sys.exit(f"no draft for {seg} {fn}")
    text = src.read_text().replace("\r", "")
    status, steps = run_target(seg, fn, text, a, Stats())
    print(f"{seg} {fn}: {status}")
    if steps is not None and a.promote:
        print("promote:", *promote(seg, fn, (WINS / seg / f"{fn}.c").read_text()))
    return int(steps is None)


def drafts(spec):
    """[(seg, fn, path)] of the unfinished drafts of a segment or of a range of overlays; a verified file hides its draft."""
    out = []
    m = re.fullmatch(r"(?:ovl)?(\d{4})-(?:ovl)?(\d{4})", spec)
    if spec in ("boot", "code"):
        rev = {v: k for k, v in names_mod.load(spec).items()}
        for p in sorted((ROOT / "src" / spec / "wip").glob("*.c")):
            fn = p.stem if p.stem.startswith("func_") else rev.get(p.stem)
            if fn and not srcpath.path(spec, fn).exists():
                out.append((spec, fn, p))
        return out
    lo, hi = (int(m.group(1)), int(m.group(2))) if m else (int(spec[3:]),) * 2 if re.fullmatch(r"ovl\d{4}", spec) else sys.exit(f"bad target {spec}")
    for idx in sorted({l.split()[0] for l in (ROOT / "config/overlays/list.txt").read_text().splitlines() if l.strip()}):
        if not lo <= int(idx) <= hi:
            continue
        seg, base = f"ovl{idx}", srcpath.overlay_dir(idx)
        rev = {v: k for k, v in names_mod.load(seg).items()}
        got = {}
        for d in (ROOT / "build/auto_drafts" / seg, base / "wip"):   # the wip file wins over the m2c draft
            for p in d.glob("*.c") if d.is_dir() else ():
                fn = p.stem if p.stem.startswith("func_") else rev.get(p.stem)
                if fn:
                    got[fn] = p
        out += [(seg, fn, p) for fn, p in sorted(got.items()) if not (base / f"{fn}.c").exists()]
    return out


def measure(job):
    seg, fn, path, max_size = job
    try:
        if len(match.original(seg, fn)[0]) > max_size:
            return None
        tg = Target(seg, fn)
        try:
            r = tg.score(path.read_text().replace("\r", ""))
        finally:
            tg.cleanup()
    except Exception:
        return None
    return r


def cmd_sweep(a):
    spec = a.args[0]
    todo = drafts(spec)
    if a.limit:
        todo = todo[:a.limit]
    print(f"{len(todo)} drafts; measuring", flush=True)
    rows = []
    with ThreadPoolExecutor(objcache.JOBS) as ex:
        measured = list(ex.map(measure, [(s, f, p, a.max_size) for s, f, p in todo]))
    for (seg, fn, path), r in zip(todo, measured):
        if r and r[0] <= a.max_diff + 0.6:
            rows.append((r[0], seg, fn, path))
    rows.sort(key=lambda x: (x[0], x[1], x[2]))
    stats, won, log = Stats(), 0, ROOT / "build/close"
    log.mkdir(parents=True, exist_ok=True)
    if a.skip_tried:   # the functions an earlier sweep of this target gave up on (`best`), with the same start score
        seen = set()
        old_log = log / f"sweep_{spec}.log"
        for l in (old_log.read_text().splitlines() if old_log.exists() else []):
            f = l.split()
            if len(f) >= 6 and f[2] == "start" and f[4] == "best":
                seen.add((f[0], f[1], f[3]))
        rows = [r for r in rows if (r[1], r[2], f"{r[0]:.2f}") not in seen]
    print(f"{len(rows)} within {a.max_diff} instructions", flush=True)
    with (log / f"sweep_{spec}.log").open("a") as lf:
        for sc, seg, fn, path in rows:
            status, steps = run_target(seg, fn, path.read_text().replace("\r", ""), a, stats, log=lambda s: None)
            line = f"{seg} {fn} start {sc:.2f} {status}" + (f"  {' > '.join(steps)}" if steps is not None else "")
            if steps is not None and not a.no_promote:
                line += "  promote: " + " ".join(map(str, promote(seg, fn, (WINS / seg / f"{fn}.c").read_text())))
            won += steps is not None
            print(line, flush=True)
            lf.write(line + "\n")
            lf.flush()
    print(f"DONE: {won} closed of {len(rows)} tried")


def cmd_score(a):
    seg, fn, src = a.args[:3]
    tg = Target(seg, fn)
    r = tg.score(Path(src).read_text())
    tg.cleanup()
    print("does not compile" if r is None else f"{fn}: {'MATCH' if r[1] else f'{r[0]:.2f}'} {r[2]}")


def cmd_promote(a):
    seg, fn = a.args[:2]
    ok, msg = promote(seg, fn, (WINS / seg / f"{fn}.c").read_text())
    print(("promoted " if ok else "refused: ") + msg)
    return int(not ok)


def cmd_record(a):
    seg, fn, muts = a.args[:3]
    s = Stats()
    s.win(seg, fn, muts.split(","), [])
    s.save()


def cmd_learn(a):
    s = Stats()
    known = {(w["seg"], w["fn"]) for w in s.d["wins"]}
    for j in sorted(WINS.glob("*/*.json")):
        w = json.loads(j.read_text())
        if (w["seg"], w["fn"]) not in known:
            s.win(w["seg"], w["fn"], w["seq"], w["ctx"])
            print("recorded", w["seg"], w["fn"], " > ".join(w["seq"]))
    s.save()
    print(f"{len(s.d['wins'])} wins; mutators (tried, helped, wins):")
    for m, v in sorted(s.d["mut"].items(), key=lambda kv: (-kv[1]["wins"], -kv[1]["helped"])):
        print(f"  {m:14} {v['tried']:6} {v['helped']:5} {v['wins']:4}")
    if a.show:
        for t, v in sorted(s.d["ctx"].items()):
            print(f"  [{t}]", ", ".join(f"{m}={n}" for m, n in sorted(v.items(), key=lambda kv: -kv[1])))


def main():
    import argparse
    p = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    p.add_argument("cmd", choices=["try", "sweep", "score", "promote", "learn", "record"])
    p.add_argument("args", nargs="*")
    rec = recipes()["defaults"]
    p.add_argument("--time", type=float, default=rec["time"])
    p.add_argument("--cands", type=int, default=rec["cands"])
    p.add_argument("--beam", type=int, default=rec["beam"])
    p.add_argument("--per-node", type=int, default=rec["per_node"])
    p.add_argument("--permute", type=int, default=0)
    p.add_argument("--permute-max", type=float, default=6, help="run the permuter only on a draft at most this far from the ROM")
    p.add_argument("--seed", type=int, default=1)
    p.add_argument("--promote", action="store_true")
    p.add_argument("--no-promote", action="store_true")
    p.add_argument("--skip-tried", action="store_true")
    p.add_argument("--max-diff", type=float, default=8)
    p.add_argument("--max-size", type=lambda x: int(x, 0), default=0x300)
    p.add_argument("--limit", type=int, default=0)
    p.add_argument("--show", action="store_true")
    a = p.parse_args()
    sys.exit({"try": cmd_try, "sweep": cmd_sweep, "score": cmd_score, "promote": cmd_promote, "learn": cmd_learn, "record": cmd_record}[a.cmd](a))


if __name__ == "__main__":
    main()
