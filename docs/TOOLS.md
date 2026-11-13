# Tools

The scripts of `tools/`, grouped by use. The day-to-day commands are in [CONTRIBUTING.md](CONTRIBUTING.md) and in the guide of each segment
([BOOT.md](BOOT.md), [CODE.md](CODE.md), [OVERLAYS.md](OVERLAYS.md)).

## Layout of `tools/`

```
tools/
  mm           Windows-side wrapper for the WSL tools
  lib/         modules the other scripts import: match, objcache, names, srcpath, build_seg
  fast/        the persistent match server and its client (milliseconds per match instead of a process per match)
  check/       verification and reports: verify_*, fastcheck, check_style, progress, quarantine
  search/      automatic search for matching C: auto_*, flag_sweep, permute_*, tidy_perm, overlay_auto, wave*
  signatures/  prototypes and typing: retype, sig_actors, sig_header
  split/       extraction and splitting: extract, setup_wsl, overlay_split, overlays
  layout/      one folder per original source file: layout, layout_callers, srcsort
  run/         unattended runs: daily, forever
  research/    Ghidra, reference names, disassembly diff
  agents/      the briefs given to AI agents
  vendor/      external tools fetched by `make setup` (not tracked)
```

A script finds the others through `sys.path` (every folder of `tools/` is added at its top) and the project root from its own location, so
they run from any directory.

## Daily work on one function

| Tool | Purpose |
|---|---|
| `tools/mm` | `asm`, `m2c`, `match` and `diff` for one function (runs the WSL tools from Windows); `fast ...` talks to the match server below |
| `tools/lib/match.py` | compile one C function with IDO (7.1, or 5.3 if the file asks for it) and compare it to the ROM bytes |
| `tools/research/disasm_diff.py` | ROM and compiled instructions side by side for one function (behind `tools/mm diff`) |
| `tools/lib/names.py` | apply the symbol names of `config/<segment>/names.txt` everywhere |
| `tools/check/check_style.sh` | source rules: no inline assembly, no `#pragma` but the `sqrtf`/`fabsf` idiom, no web address or project name in the sources (credits live in the README) |

## The match server (`tools/fast`)

`tools/lib/match.py` starts a process, hashes `include/` and reads the ROM and the assembly through `/mnt/c` on every call: tens of
seconds on a loaded machine. The server does that once and keeps it in memory, on a native copy of the files, and answers in
milliseconds (a cached object), or in the time of one compile (about 0.15 s on the native disk). Nothing to start by hand: the first
call starts it (and mirrors the repository to `~/mmfast/<checkout>/tree`, about 20 s the first time).

```
tools/mm fast match ovl0057 func_80000618 path/to/f.c [--flags "-O1 -g0"] [--json] [--no-disasm]
tools/mm fast batch ovl0057 func_80000618 a.c b.c c.c          # or cands.jsonl, or - for stdin: one JSON line per candidate, as it finishes
tools/mm fast sync [--all] | stats | scrub | stop | path
python3 tools/fast/client.py match ...                          # the same, from inside WSL (stdlib only)
```

A jsonl line is `{"id": "a", "source": "<C text>"}` or `{"id": "a", "file": "x.c", "flags": "-O1", "seg": "code", "fn": "func_..."}`
(`seg` and `fn` default to the command's). The flags of a source are its `// FLAGS:` / `// COMPILER:` lines, as for `match.py`;
`flags` replaces the optimisation flags like that line does. A result carries `status` (`MATCH`, `DIFF`, `SIZE`, `ERROR`), `match`,
`ms`, `compiled` (false: the object came from the cache), `rom_len`, `our_len`, the score fields below, `first` (byte offsets of the
first differing instructions), `lines` (`off`, `rom`, `ours` disassembled; single match, or `--disasm` in a batch) and `error`
(the compiler messages). The exit code is 0 for a match, 1 otherwise (batch: 0 if any candidate matches).

- **Sources are sent with the request**: an edited file needs no sync. Headers, names and tools are read from the mirror: run
  `fast sync` after changing `include/`, `config/` or `tools/lib/` (a second or two, and the server restarts on the new files);
  `--all` also refreshes the ROM files and the assembly.
- **Compilers are capped**: `MM_JOBS` (default 3) compilers at once, counted over every server of the machine (a lock file per slot in
  `~/mmfast/slots`, released by the system if a process dies); the other requests wait. A batch of 50 new sources takes about
  50 / 3 compiles; the same source twice is compiled once. The server keeps the object cache of the process that started it
  (`MM_CACHE`) and exits after `MM_FAST_IDLE` seconds (default 7200) without a request.
- **Cache**: `tools/lib/objcache.py` now ignores and deletes an empty object, writes through a temporary name private to the
  thread, and compiles a key once per process; `fast scrub` deletes the empty files and stale temporary files already there.
  One cache (`~/.cache/mm-n64-decomp`, moved by `MM_CACHE`) is shared by every checkout, mirror and process of the machine: nobody
  needs a private one. Its key holds the headers a file can reach (not the whole of `include/`), so a header change compiles only
  the files that see it. It is capped at `MM_CACHE_MAX` GB (default 8): above the cap the least recently used objects are deleted
  (one scan every five minutes at most, never an object used in the last hour); the verdicts and link objects of a checkout live
  in `<cache>/tree/<checkout>` and go a week after its last check.
- **Scoring** (`tools/lib/score.py`, `score.score(rom_words, our_words)`, usable by any search): `diff` (what `match.py` counts),
  `reg` (differ only in register fields), `moved` (the ROM has the word elsewhere among the differing ones: an ordering
  difference), `hard`, `size` (our length minus the ROM's, in words), `edit` (instructions outside the longest common subsequence: one
  inserted instruction costs 1 here, not the whole shifted tail) and `score = min(hard + |size| + 0.5 moved + 0.25 reg, edit)`
  (0 is a match, lower is closer).
- From Python: `import client; client.match(seg, fn, source=text)` and `client.batch(seg, fn, [{"source": ...}, ...])`.

## Verification and build

| Tool | Purpose |
|---|---|
| `tools/check/verify_src.py`, `tools/check/verify_all.sh`, `tools/check/verify_overlays.sh` | check every C function (boot, code, overlays), then the whole rebuilt segment |
| `tools/check/fastcheck.sh` (`make fastcheck`) | `make check` on the native disk of WSL: when the repository is under `/mnt/`, it takes a machine-wide lock (`~/.mm-fastcheck.lock`: one fastcheck at a time, the others print "waiting for another fastcheck (held by <checkout>)" and wait), mirrors what the checks read (incrementally, two folders at a time) and runs them there, 3-4 times faster; nothing is copied back. The checks are incremental: a function is compared again only when its source, a header it can reach, its ROM bytes, a symbol address it refers to, the compiler or the checking tools changed, and a segment is linked again only when an input of the last identical link changed. `MM_FULL=1 make fastcheck` trusts no earlier verdict and no earlier link (also what a new cache or changed tools give) |
| `tools/check/incremental_selfcheck.py` (`make selfcheck`, or `tools/check/fastcheck.sh selfcheck` on the Windows disk) | about a minute: in a scratch copy of boot, compares the incremental verdict with a full run on an empty cache for a clean tree, a broken function, a broken nested header, a flipped ROM byte and two swapped names; run it after changing `objcache.py`, `verify_src.py` or `build_seg.py` |
| `tools/check/push.sh` (`make push`) | **THE way to push to main.** Works from the main checkout and from any worktree, in WSL (`make push`) or from Windows (`bash tools/mm push`): the checks (`make selftest`, `tools/check/fastcheck.sh`; `MM_FULL=1` for a full one) run in WSL, the git commands (fetch, rebase, push) always run on Windows, never with the git of Linux (inside WSL the `.git` file of a worktree points to a Windows path it cannot read). Started from Git Bash (`bash tools/mm push`, the most robust: git runs natively and WSL is only asked for the checks, so a broken link from WSL to Windows does not matter) the git is Git Bash's; started in WSL (`make push`) it is looked up once, in this order, and named in the output (`git: ...`): `GIT=<path>`, `where git` asked to `cmd.exe`, `git.exe` on the path of WSL, the install folders of Git for Windows, then `cmd.exe /c git` and `powershell.exe -c git`; a git command that fails on the link between WSL and Windows (accept4 failed 110, E_UNEXPECTED) is tried again three times with a pause. The checks are not repeated for a tree that already passed (`~/.mm-push-ok/<checkout>` holds its tree hash: a push that failed, or a script killed after the checks, is resumed without them) and a rebased tree gets the incremental fastcheck only. Refuses a tree with uncommitted changes; when `origin/main` moved it rebases on it (a conflict stops it after `rebase --abort`), checks the rebased tree and runs `git push origin HEAD:main`; if it moved again during the checks (another agent pushed) it rebases and checks once more, three attempts at most. Prints `pushed <hash>` or why not |
| `tools/check/preflight.sh` | refuses to start heavy work (exit 1 and a message) when the drive of the repository or of the home directory has under `MM_MIN_FREE_GB` (default 15) GB free: a full disk crashed WSL. It also checks `MM_WORK` (the mirror of `fastcheck.sh`): it must be an absolute path of WSL, e.g. `MM_WORK=/home/<user>/work_x`; a `~` the shell did not expand is translated to the home of WSL by `fastcheck.sh`, and a Windows path (`C:\x`), a Git Bash path (`/c/x`) or a relative one is refused with that message (they created a folder named `~` or failed with `mkdir: Permission denied`). Called by `tools/mm`, `fastcheck.sh`, `push.sh` and `forever.sh`, and shown as an ALERT by `status.sh` |
| `tools/lib/build_seg.py` | rebuild a segment from per-function objects and compare it to the ROM |
| `tools/check/verify_asm.sh` | reassemble the splat output of a segment and check it is byte-identical to the ROM |
| `tools/lib/objcache.py` | content-addressed cache of compiled objects shared by the checks (about ten times faster re-verification) |
| `tools/check/progress.py` | generate `docs/PROGRESS.md` (functions, drafts, typed signatures, names) and the progress bars of the README |

## Automated search for matching C

| Tool | Purpose |
|---|---|
| `tools/search/auto_match.py`, `tools/search/auto_near.py`, `tools/search/auto_recipes.py` | try the m2c drafts with several IDO flag sets and mechanical tricks, then rank the near misses |
| `tools/search/close.py`, `tools/search/close_mut.py`, `tools/search/recipes/default.json` | the adaptive near-miss closer. Takes a draft that is a few instructions from the ROM and searches source-level mutations until IDO gives the ROM's bytes: operand order of a comparison or an `a + b`, `!x` / `x == 0`, `a < 5` / `a <= 4`, `&&` order, `if`/`else` branches swapped or the `else` dropped after a `return`, statement order (swap or hoist), declaration order, `s32 pad;` locals added or dropped, the type of a local or a parameter, a parameter copied to `this`, a local inlined or a repeated `a->b` extracted, `a = b = 0` chains, `if`/`else` as a ternary, `for` as `while`, `f32` literal forms, casts, the `addu` operand order (also `p + (expr)`), an unused trailing parameter, a float passed as a hex bit pattern or `0` to a callee (`callf32`: the literal becomes an `f32` and the parameter of the prototype too: the ROM then loads `addiu a1, zero, 0` or `lui a1, 0x3C23`), a parameter of the function passed on to a callee (`fwdarg`: `f(x)` to `f(arg0, x)`), the signedness of one `M2C_FIELD` access (`fieldsign`: `addiu 255` against `-1`), an array element (`index`: `M2C_FIELD((p + (i * 4)), s32 *, 0x800)` to `((s32 *)(p + 0x800))[i]`; `symarr`: `*(&D_8000 + (i * 4))` to `D_8000[i]` with the `extern` made an array of the element type of the stride), the comparison through a subtraction (`subcmp`: `a == b` to `!(a - b)` to `(a - b) == 0`), per file the compiler and the flags together (`cc`: `// COMPILER: ido53` added or removed with `-g`/`-g0`/`-g3`, `-mips2`), and the IDO flags (`-O1`/`-O2`, `-g0`/`-g3`, `-trapuv`); `close.py try|sweep --grid` also scores, once from the draft, every combination of IDO 7.1/5.3, `-O0`..`-O3`, `-g`/`-g0`/`-g3`, `-mips1`/`-mips2`, `-G 0`/`-G 8`, `-non_shared`/`-KPIC` and `-Wab,-r4300_mul` (383 compiles; a `// FLAGS:` line with `-G` or `-KPIC` replaces the default of `match.py`); measured: on 153 near misses (start score up to 3, overlays and code) `subcmp` won 2 and `cc` 2 (IDO 5.3 for an overlay function), and on 20 hand-written drafts of code the grid closed none (the ones left are 20 to 60 instructions away, an optimiser-level difference the flags do not change); `inline_local` also inlines a local that is the read of one field (`temp = M2C_FIELD(p, s16 *, 0x16);`, no call) when it is used several times, every use reading the field again as the ROM does: on the same 147 near misses it won 17 functions (the one-use form had already been tried on them without a win), 14 of them at start score 0.26 or 1.02 (`temp_f0`, `temp_v0`, `temp_a1`); all 22 winners of these tests pass `match.py` and the style rules; mutators tried and dropped for winning nothing on the same functions: a display-list command written as `d = ((Ctx *)g)->p++; d->w0 = ..; d->w1 = ..;` instead of the m2c `M2C_FIELD` stores (0 of 151 drafts with such code, alone or with all the other mutators), a trailing `return;` and the inversion of an early exit, an explicit `& 0xFF` / `(u8)` on a store, every small local and parameter as `s32`, `((T *)&sym)[i]` for the elements of a global; never `register`, `volatile` or `#pragma`. Beam search scored by the number of differing instructions (opcode changes weigh more); a mutation whose object code was already seen is dropped, so only changes that move the compiler's output are explored; the useless hunks of a winner are reverted one by one. `close.py try ovlNNNN func_XXXXXXXX [draft.c] [--time S] [--permute S] [--promote]` works on one function (the draft defaults to the wip file or the m2c draft in `build/auto_drafts`; `--permute` hands the best draft to `permute_list.py` when the mutations stall); `close.py sweep ovl0300-0665\|ovlNNNN\|code\|boot [--max-diff 8]` measures every draft of the target, tries those within the limit closest first and promotes the winners (`match.py` MATCH, the style rules of `check_style.py`, project indentation, wip draft deleted) to `src/` unless `--no-promote`; `--skip-tried` leaves out the functions this target's sweep log (`build/close/sweep_<target>.log`) shows as given up on (`best`) with the same start score and the same mutators (the `[v:...]` tag, a hash of `close_mut.py` and `recipes/default.json`: new mutators try them again). Measured on the VPS journal of 11-12 November (1850 tries, 196 wins): every win came within 18 s (median 1 s), the last seven rounds (19 h) retried the same 213 functions for 2 wins, so `daily.sh` runs the closer with `--time 25 --skip-tried`; `close.py score` prints the distance and the kind of difference (`reg`, `opswap`, `stack`, `imm`, `order`, `size+`, `size-`, `frame`). Winners are written raw to `build/close_wins/<seg>/<fn>.c` with the mutation list (`<fn>.json`). Learning: `config/search/close_stats.json` counts, per mutator, the candidates tried, the ones that moved the score closer and the wins, and per kind of difference which mutator won; the next search draws its mutations in that order. `close.py learn [--show]` merges the wins other runs left in `build/close_wins/` and prints the table, `close.py record <seg> <fn> <mutator,...>` notes a fix found by hand. Candidates are compiled in batches by the match server (`tools/fast`, score of `tools/lib/score.py`); `MM_CLOSE_INPROC=1` compiles in process instead. `--permute S` hands a stalled draft (at most `--permute-max` instructions away) to the permuter. `MM_JOBS` caps the compile workers, `MM_CACHE` the object cache |
| `tools/search/permute_setup.py`, `tools/search/flag_sweep.py` | automated search for matching C |
| `tools/search/permute_list.py` | run the permuter on a list of unmatched functions, or with `--auto` on every wip draft (boot, code, and overlays: wip files plus the m2c drafts of what the automatic passes missed) closest first, and keep what matches in `build/perm_wins/`; a function already in its log is not tried again without `--retry` |
| `tools/search/tidy_perm.py` | rewrite the raw permuter output in the project style, checking the match after every step, and move it to `src/` |
| `tools/run/daily.sh` (`make daily HOURS=3`) | unattended: the permuter over the boot, code and overlay drafts, tidy the wins, the overlay passes, the import of what the reference compiles to the bytes of the ROM (`NO_REF=1` skips it), then the adaptive closer `close.py sweep` over code, boot and the overlays with the time the round has left (`NO_CLOSE=1` skips it; its statistics `config/search/close_stats.json` are committed with the round), the typing of the new actor handlers (`tools/signatures/retype.py`) and the prototype headers (`tools/signatures/sig_header.py`), the full check, then commit and push if the check passed. After every step it runs a checkpoint: `tools/check/quarantine.py code\|boot\|overlays --max N` compiles every C file against the headers as they are now (`verify_src.py`) and moves the few that no longer compile or match back to `wip/`; a step that breaks more than N (20, overlays 40: a header changed under the files) is dropped whole (`git reset --hard`, its new files deleted), and what holds is committed at once, so a failing final check keeps every earlier step (`forever.sh` resets to HEAD, `push.sh` checks and pushes those commits); when the final check passes the commits are squashed into the one below. The final `wave_finish.sh` runs with `QUARANTINE=1` (a function that fails after the renaming goes back to wip/ instead of failing the round), and `names.py --apply-src` leaves the `#define X ref_X` / `#undef X` prefix lines of the context headers (`include/generated/mm/`) alone: renaming them made the reference's declaration clash with ours (En_Bubble, round of 2026-11-12). `sig_header.py` gives only an overlay header the types of `actor.h`: the files of boot and code define their own `Vec3f` and `Actor`, and a header that included `actor.h` made 37 of them fail to compile (the round of 2026-11-11). It stops when its terminal closes: start it with `nohup make daily HOURS=3 > build/daily.out 2>&1 &` |
| `tools/signatures/sig_header.py` | prototypes of a whole segment in one header (`include/generated/code_funcs.h`, `include/generated/overlays/NNNN.h`): the definition's own where there is verified C, else the `extern` the other files carry, else read from the assembly (arguments, pointers, floats, result); `--apply` makes each verified file use the header, kept only if it still matches |
| `tools/signatures/sig_ref.py` | the prototypes of the overlay functions that have evidence, written to `config/overlays/protos.txt` (same format as `config/overlays/signatures.txt`, applied by `retype.py` and read by `sig_header.py`): a function named with "bytes identical" in `config/overlays/names.txt`, or imported by `ref_import.py`, takes the prototype of its reference definition (the reference source in `build/ref/mm`, or the definition in its own imported file); a type the header cannot say becomes `void *` for a pointer and skips the function otherwise. Then `derive`: a function that every caller in the overlay gives, untouched, a typed parameter of a handler (`Actor *thisx`, `PlayState *play`) takes that type (the arguments are followed through moves, the stack and the calls through a word of the actor, `this->actionFunc(this, play)`; `EnTest *this` for the first parameter; the actor structures are declared without fields in the header). `sig_header.py` prints the reference-derived and handler prototypes in `include/generated/overlays/NNNN.h`; `make` order: `sig_ref.py`, `retype.py config/overlays/protos.txt`, `sig_header.py overlays --apply`; `sig_ref.py prune` drops the lines whose file no longer matches |
| `tools/search/ref_import.py` | functions of the reference decompilation that compile to the bytes of this ROM, written as files of ours. `run` does `code` (a function that already has a name, or a unique match of bytes in both directions, which also gives its name: registered in `config/code/names.txt` even if the file is not kept); `run overlays` does the overlays (every reference file is matched to one of ours by the vote of its functions, then each function must match one of ours and nothing else). Each function is compiled twice: the first pass names every symbol the way the source spells it, pairing them with our assembly gives the aliases (`#define` to ours, kept from run to run in the header of the reference file, `include/generated/mm/`), the second pass is the one checked. The reference's own address names (`func_8012CB04`) get a `ref_` prefix because they clash with ours; the start of an array reached by an offset and the symbols the compiler calls (`__ull_div`) go to `config/code/bases.txt` for the linker. `run names` writes the names of the overlays and of their functions instead (see [OVERLAYS.md](OVERLAYS.md)). `vendor` copies the headers and the stand-ins of the generated asset headers to `include/mm/` (additive; `REFERENCE_COMMIT` there names the version of the reference). A rejection is counted with its reason. `heal` (start of every round) and `run` call `link_guard`: links the code segment (`build_seg.py`) and deletes the untracked files whose object has an undefined reference, so an import cannot leave a segment that does not link (a link failure with no such file deletes everything the run wrote and exits non-zero). An unsized array of the reference (`T x[] = {...}`) is declared with the count of its initialiser so that `sizeof` works; a name that only a header of the reference declares is prefixed while that header is read; a `.c` file the reference file includes is written in place. Speed (`--time` prints the phases): `include/mm` is not copied again when `REFERENCE_COMMIT` is unchanged (only the stand-ins are), a failed compile of a reference file is remembered by content hash and by the state of the stand-ins, and only the files whose error names a new stand-in are compiled again. `--why` lists, for `run names`, why each reference file has no overlay, and `--validate` hides a quarter of the identical-bytes anchors and checks the names the alignment rules give them. |
| `tools/check/selftest.py` (`make selftest`) | a second: every tool parses, finds the project root and has no control character (a lost backslash), `pyflakes` is clean (the workflow of GitHub fails otherwise), and the pure functions give the right answers; run at the start of every round |
| `tools/run/status.sh` | the service, the last rounds (`build/rounds.log`), the commits not pushed yet, the load; an `ALERT:` line when no round ended with `rc=0` for 24 hours or the disk is nearly full |
| `tools/run/sync_asm.sh <checkout \| user@host:/path>` | copies `asm/` from another checkout with rsync instead of running `make split`. `make split` takes about 30 minutes of disassembly and on the 3.8 GB VPS it made the machine unreachable: never run it there, copy the `asm/` of a checkout made by the same `make split` |
| `tools/run/forever.sh` | for a machine that stays on: `tools/run/daily.sh` in a loop, a failed round restored to the last commit (`git reset --hard`, then the files that the round added to `src/` and `include/` are deleted, the ones present at its start kept: an imported file is untracked, left behind it would lose its `bases.txt` entry and break every later link), a push retried by the next round; five identical failures in a row (same exit code, commit and last lines of the round) make it sleep an hour between rounds with an ALERT line in `build/rounds.log`, and a nearly full disk (`preflight.sh`) makes it wait an hour; run it as a service (`Restart=always`). Several machines may run it on the same repository: `tools/run/push.sh` puts a refused push on top of the other machine's commits, checks the merged tree again and drops the round if it does not hold. `MM_JOBS` limits the workers of a machine |
| `tools/search/wave.py`, `tools/search/wave_finish.sh` | prepare a wave of functions for the AI agents (smallest first, split in chunks), then file the new sources, apply the names and run the full check |
| `tools/agents/AGENT_BRIEF.md`, `tools/agents/CLEANUP_BRIEF.md` | the rules and techniques given to the AI agents that write and tidy the C |

## Drafts for the overlays, and idioms the closer learned

| Tool | Purpose |
|---|---|
| `tools/search/draft_all.py ovlLO-ovlHI [max_size_hex] [jobs]` | writes the m2c draft of every unmatched overlay function of a range to `build/auto_drafts/<seg>/` (a switch function gets the draft of `hard_jt.py`, with its table); what `close.py sweep` reads |
| `tools/search/structify.py all ovlLO-ovlHI` | rewrites each draft with one padded struct per `u8 *` variable (real member accesses instead of `M2C_FIELD`), makes drafts compile (sized unknown types, prototypes without float parameters become `f()`), tries `-Wab,-r4300_mul` on float code, and keeps a version only if it scores closer (the old text goes to `<fn>.c.orig`) |

Libultra flash code (`code`, 0x80187xxx-0x80188xxx) is IDO 5.3 with `// FLAGS: -g` (no `-O`, no `-mips2`): the output looks unoptimised (`lui at` for every access, `or a1, t6, zero` after a constant, a load-delay `nop`). Shape: `if (c) { return A; } else { return B; }`, a trailing `return;` on a void function (each `return;` adds one `b`/`jr ra` pair; an empty function is two `jr ra; nop` pairs), a 64-bit argument (`osSetTimer`) is `u64`, `u8` results are stored with an explicit `& 0xFF`. Audio code: parameters and locals that the ROM never sign-extends are `s32`, `((T *)&sym)[j]` in a loop keeps the second `lui`/`addiu` the ROM has.

Idioms found with them: `-Wab,-r4300_mul` in the FLAGS line gives the `nop` after `mul.s` (a flag mutation of `close.py`); `x * -1` is a negation that IDO does not fold into
a subtraction (`y += a * -1` gives `negu` + `addu`); four argument words read from the stack as floats are a struct passed by value; `B *b; if (this->b != 0) { b = this->b; ...`
(the `late_local` mutator) puts the local in the second register like the ROM; a `Gfx` command written as `{ C *gfx = play->c; s32 pad; { G *g = gfx->g++; g->w0 = ...; g->w1 = ...; } }`
(nested braces, the unused `pad`, both stores on ONE source line) is the shape of `OPEN_DISPS` and gives the ROM's scheduling; a callee that receives the caller's `a0` untouched is
declared with empty parentheses and called `f(this, CONST)`, which m2c drafts miss.

## The functions the automatic tools skip

`tools/search/hard_*.py` and `tools/lib/hardjt.py` take the functions that `auto_match`, `auto_recipes` and the permuter leave alone. Start with
`python3 tools/search/hard_scan.py` (counts per segment and category; `--list jtbl|large|hand_unlisted|other [--max-size HEX]` lists the functions).

| Tool | Purpose |
|---|---|
| `tools/search/hard_scan.py` | counts the unmatched functions (no verified C file) by category: `jtbl` (jump table, a `switch`), `hand` (outside the C todo: marked `Handwritten function` by splat or in `asm_only.txt`), `hand_unlisted`, `m2c_failed`, `large` (over 0x400 bytes), `other` |
| `tools/lib/hardjt.py` | the jump tables of the splat assembly: the table of a function (code, boot, overlays: the entries of an overlay table are link-time addresses, the base is found from the `jal` targets), the case bound, the splat fragments of a switch (see below), and `object_tables`/`tables_agree`, which read the case targets from the relocations of our object |
| `tools/search/hard_jt.py` | `draft`: the m2c draft of a function with a `switch` (m2c refuses it because splat prints the table as raw words: the tool gives m2c the table and a label at every case target); `info`: case values per target; `auto <seg\|overlays> [max_size] [jobs] [--redo]`: draft + the usual flag sets + the recipes of `auto_recipes`, and the **table is checked against the ROM**; matches go to `build/auto_match/<seg>_jt/` and `overlay_auto.py promote` files them; `check <seg> <fn> <file.c>`: `match.py` plus the table, for a hand-written file |
| `tools/search/hard_m2c.py` | `why`: the reasons m2c refuses functions; `draft`: the first m2c variant that gives C (the table for a switch, then `--gotos-only`, `--no-andor`, `--no-switches`, `--no-stack-spill`); `auto`: the variants times the flag sets on the `m2c failed` functions |
| `tools/search/hard_blocks.py` | `hard_blocks.py <seg> <fn> <file.c>`: for a big function, aligns the ROM and our instructions (so that one extra instruction does not shift the rest), judges each basic block and prints the **first block that differs** with context. Write the first part of the function, end it with `STUB();` and `return`, run the tool, extend, repeat |
| `tools/search/hard_hand.py` | classifies the functions that look hand-written: `asm_only` when an instruction proves it (COP0, `cache`, `ll`/`sc`, `eret`, `$k0`/`$k1`, a bare `cfc1`/`ctc1`, trapping `add`/`addi`/`sub`, which IDO never emits), else a C candidate with what looks odd; `--apply` adds the proven ones to `config/<seg>/asm_only.txt` |

**Why m2c fails, and what to do.** Counted with `hard_m2c.py why`: (1) a function that returns a pointer (`void *func_...(`) was logged as failed by an old
check of `auto_match.py` (it looked for ` func_...(`): fixed, such functions are tried now; (2) `jr` to a jump table: m2c needs the table, `hard_jt.py`
gives it; (3) a table whose entries beyond the bound are zero (`Cannot find jtbl target .L00000000`): `hardjt.head_tables` cuts the table at the
`sltiu` bound; (4) the case bodies split off by splat (below). A function that m2c still refuses: `hard_m2c.py draft` tries the options one by one.

**Jump tables and the pieces splat cuts off.** IDO puts the case bodies after the first `jr $ra`; when every body returns, splat ends the function
there and prints each body as a function of its own (`func_800B6DA8` is a case of `func_800B6D4C`, which is `0x5c` bytes of the real `0xC8`). Such a
chunk is no function: nothing calls it, only the table points to it. `hardjt.fragments` lists them. The switches whose bodies are inside the function
(most of them) are not cut. `config/<seg>/merge.txt` lists `head fragment fragment ...` and `tools/split/merge_frags.py` (run by `make split` after splat, idempotent) rewrites `asm/<seg>/text.s` so that the fragments become `alabel`s inside the head: one `nonmatching`, one `endlabel`, size = the sum, the bytes unchanged (`verify_asm.sh` still gives IDENTICAL). `func_800B6D4C` (0xC8, 4 fragments) and `func_8016239C` (0x8C, 7 fragments) are merged and in C; the fragments had been counted as functions of their own (a `return CutsceneCamera_Interp_None;`), they are now cases of one switch.

## Source layout

| Tool | Purpose |
|---|---|
| `tools/layout/layout.py`, `tools/layout/layout_callers.py`, `tools/layout/srcsort.py`, `tools/lib/srcpath.py` | `src/boot` and `src/code` keep one folder per original source file (GitHub shows at most 1000 files per folder): `layout.py` writes the table `config/<segment>/layout.txt` once, `srcsort.py` files new flat `src/<segment>/func_*.c` into their folder, `layout_callers.py` moves a function out of `unknown/` when only one module calls it, `srcpath.py` is the lookup the other tools use |
| `tools/research/ref_align.py` | find candidate function names by aligning function sizes with the symbol list of another decompilation project |

## Overlays

| Tool | Purpose |
|---|---|
| `tools/split/merge_frags.py` | after splat: join the case bodies splat cut off a switch function (`config/<seg>/merge.txt`), see the jump-table paragraph above |
| `tools/split/overlays.py` | list the overlays of the ROM file table in `config/overlays/list.txt` (file, section sizes, relocation count) |
| `tools/split/overlay_split.py` | disassemble every overlay with splat and check that the assembly rebuilds the extracted file (`asm/overlays/`) |
| `tools/search/overlay_auto.py` | automatic pass on the overlays (m2c drafts, mechanical recipes), then promote what matches to `src/overlays/` |

## Setup and research

| Tool | Purpose |
|---|---|
| `tools/split/extract.py` | decode the ROM file table, extract every file, and write `build/boot.bin` |
| `tools/split/setup_wsl.sh` | one-time setup inside WSL (behind `make setup`) |
| `tools/research/decomp.py`, `tools/research/mkelf.py`, `tools/research/ghidra/ExportDecomp.java` | Ghidra pseudo-C for a code segment (research only); set `GHIDRA_HEADLESS` to your `support/analyzeHeadless` script |

External tools used (fetched by `make setup` into `tools/vendor/`, or installed with `apt`; none is tracked):

| Tool | Used for |
|---|---|
| IDO 7.1 and IDO 5.3 (`ido-static-recomp`) | the original compilers, see [COMPILERS.md](COMPILERS.md) |
| GNU binutils for MIPS (`mips-linux-gnu-as`, `-ld`, `-objdump`, `-nm`, `-objcopy`) | assemble, link at the original addresses, inspect objects and cut the rebuilt segment |
| splat (with spimdisasm and rabbitizer) | split the ROM segments into assembly and data |
| m2c | first-draft C from assembly |
| asm-differ | assembly comparison |
| decomp-permuter | automated search for matching C |
| Ghidra | pseudo-C for research |
| WSL (Ubuntu), Python 3, GNU make | run the tools and the checks on Windows |


## What cannot be C (evidence)

`hard_hand.py` decides, `config/<seg>/asm_only.txt` lists. A function stays assembly only with one of these proofs; everything else is a C todo.

| Functions | Proof |
|---|---|
| boot `func_80087CA0 func_800881B0 func_80088250 func_8008A760 func_8008A770 func_8008B850 func_8008B860 func_8008D460 func_80091420 func_80091430 func_80091C00 func_80091C70 func_80093F30 func_800969B0 func_800969C0` and code `func_801AB970` | COP0 `mtc0`/`mfc0`: IDO emits no coprocessor 0 access for any C expression |
| boot `func_8008C100 func_8008EF80 func_80093DA0` | `tlbp`/`tlbr`/`tlbwi` |
| boot `func_8008A780 func_8008F410 func_8008F490 func_80095760` | `cache` |
| boot `func_80088CA0 func_800891FC func_800892E4 func_80089444` | `$k0`/`$k1` used as registers (exception handler), `eret` |
| boot `func_80092E80 func_80092E90` | the whole body is `cfc1`/`ctc1` on fcr31 (osGetFpcCsr/osSetFpcCsr) |
| boot `func_80080000`, code `func_80186E30 func_8019BCE0 func_8019BD60` | trapping `add`/`addi`/`sub`: IDO emits `addiu`/`addu`/`subu` only (the assembler marks them `handwritten instruction`) |
| boot libm `floorf floor ceilf ceil truncf trunc roundf round lnearbyintf lnearbyint` and the float-to-int forms (`func_80086CE0` to `func_80086DB0`) | the result stays in the FPU (`floor.w.s $f12; cvt.s.w $f0,$f12`). The C form `return (f32)(s32)x;` gives `trunc.w.s $f4; mfc1; ...; cvt` (0x20 bytes against the ROM's 0xC), measured with the match server; IDO has no source form for `floor.w.*`, `ceil.w.*`, `round.w.*` |

Not proven, so a C todo: `func_8008942C` (list unlink, 0.5 away: `t9` instead of `t6`), `func_80088440` (guScale) and the other `asm_only.txt` boot entries without an instruction above (`hard_hand.py` prints them as `listed-only`). `func_8008943C` was listed but is an empty function: it matches as C and was taken out of the list.

**The rebase of the rounds.** `tools/run/rebase_ours.py` and `tools/run/clear_untracked.py` are used by `push.sh` and the start of `daily.sh`: the rebase onto origin/main settles a file modified on one side and deleted on the other (the other side wins), and untracked files that origin/main has are deleted first; before, one such conflict made every round's push fail (`rebase failed, local commits dropped`, rc=1) while the checks passed. `heal` failing no longer stops a round.

