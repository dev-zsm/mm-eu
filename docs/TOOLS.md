# Tools

The scripts of `tools/`, grouped by use. The day-to-day commands are in [CONTRIBUTING.md](CONTRIBUTING.md) and in the guide of each segment
([BOOT.md](BOOT.md), [CODE.md](CODE.md), [OVERLAYS.md](OVERLAYS.md)).

## Layout of `tools/`

```
tools/
  mm           Windows-side wrapper for the WSL tools
  lib/         modules the other scripts import: match, objcache, names, srcpath, build_seg
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
| `tools/mm` | `asm`, `m2c`, `match` and `diff` for one function (runs the WSL tools from Windows) |
| `tools/lib/match.py` | compile one C function with IDO (7.1, or 5.3 if the file asks for it) and compare it to the ROM bytes |
| `tools/research/disasm_diff.py` | ROM and compiled instructions side by side for one function (behind `tools/mm diff`) |
| `tools/lib/names.py` | apply the symbol names of `config/<segment>/names.txt` everywhere |
| `tools/check/check_style.sh` | source rules: no inline assembly, no `#pragma` but the `sqrtf`/`fabsf` idiom, no web address or project name in the sources (credits live in the README) |

## Verification and build

| Tool | Purpose |
|---|---|
| `tools/check/verify_src.py`, `tools/check/verify_all.sh`, `tools/check/verify_overlays.sh` | check every C function (boot, code, overlays), then the whole rebuilt segment |
| `tools/check/fastcheck.sh` (`make fastcheck`) | `make check` on the native disk of WSL: when the repository is under `/mnt/`, it mirrors what the checks read (incrementally) and runs them there, 3-4 times faster; nothing is copied back |
| `tools/lib/build_seg.py` | rebuild a segment from per-function objects and compare it to the ROM |
| `tools/check/verify_asm.sh` | reassemble the splat output of a segment and check it is byte-identical to the ROM |
| `tools/lib/objcache.py` | content-addressed cache of compiled objects shared by the checks (about ten times faster re-verification) |
| `tools/check/progress.py` | generate `docs/PROGRESS.md` (functions, drafts, typed signatures, names) and the progress bars of the README |

## Automated search for matching C

| Tool | Purpose |
|---|---|
| `tools/search/auto_match.py`, `tools/search/auto_near.py`, `tools/search/auto_recipes.py` | try the m2c drafts with several IDO flag sets and mechanical tricks, then rank the near misses |
| `tools/search/permute_setup.py`, `tools/search/flag_sweep.py` | automated search for matching C |
| `tools/search/permute_list.py` | run the permuter on a list of unmatched functions, or with `--auto` on every wip draft (boot, code, and overlays: wip files plus the m2c drafts of what the automatic passes missed) closest first, and keep what matches in `build/perm_wins/`; a function already in its log is not tried again without `--retry` |
| `tools/search/tidy_perm.py` | rewrite the raw permuter output in the project style, checking the match after every step, and move it to `src/` |
| `tools/run/daily.sh` (`make daily HOURS=3`) | unattended: the permuter over the boot, code and overlay drafts, tidy the wins, the overlay passes, the typing of the new actor handlers (`tools/signatures/retype.py`) and the prototype headers (`tools/signatures/sig_header.py`), the full check, then commit and push if the check passed. It stops when its terminal closes: start it with `nohup make daily HOURS=3 > build/daily.out 2>&1 &` |
| `tools/signatures/sig_header.py` | prototypes of a whole segment in one header (`include/generated/code_funcs.h`, `include/generated/overlays/NNNN.h`): the definition's own where there is verified C, else the `extern` the other files carry, else read from the assembly (arguments, pointers, floats, result); `--apply` makes each verified file use the header, kept only if it still matches |
| `tools/search/ref_import.py` | compiles the reference sources of `code` with this project's IDO flags, keeps the functions whose bytes are the ROM's (relocations masked) and that we do not have in C, pairs their symbols with the ones of our assembly (the reference's unnamed ones get a `ref_` prefix and a `#define` to ours), and writes them as files of ours. The headers it needs are in `include/mm/` (with stand-ins for the generated asset headers); `ref_import.py vendor` refreshes them |
| `tools/check/selftest.py` (`make selftest`) | a second: every tool parses and finds the project root, and the pure functions give the right answers; run at the start of every round and by the workflow of GitHub |
| `tools/run/status.sh` | the service, the last rounds (`build/rounds.log`), the commits not pushed yet, the load |
| `tools/run/forever.sh` | for a machine that stays on: `tools/run/daily.sh` in a loop, a failed round restored to the last commit, a push retried by the next round; run it as a service (`Restart=always`). Several machines may run it on the same repository: `tools/run/push.sh` puts a refused push on top of the other machine's commits, checks the merged tree again and drops the round if it does not hold. `MM_JOBS` limits the workers of a machine |
| `tools/search/wave.py`, `tools/search/wave_finish.sh` | prepare a wave of functions for the AI agents (smallest first, split in chunks), then file the new sources, apply the names and run the full check |
| `tools/agents/AGENT_BRIEF.md`, `tools/agents/CLEANUP_BRIEF.md` | the rules and techniques given to the AI agents that write and tidy the C |

## Source layout

| Tool | Purpose |
|---|---|
| `tools/layout/layout.py`, `tools/layout/layout_callers.py`, `tools/layout/srcsort.py`, `tools/lib/srcpath.py` | `src/boot` and `src/code` keep one folder per original source file (GitHub shows at most 1000 files per folder): `layout.py` writes the table `config/<segment>/layout.txt` once, `srcsort.py` files new flat `src/<segment>/func_*.c` into their folder, `layout_callers.py` moves a function out of `unknown/` when only one module calls it, `srcpath.py` is the lookup the other tools use |
| `tools/research/ref_align.py` | find candidate function names by aligning function sizes with the symbol list of another decompilation project |

## Overlays

| Tool | Purpose |
|---|---|
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

