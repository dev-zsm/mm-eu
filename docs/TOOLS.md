# Tools

The scripts of `tools/`, grouped by use. The day-to-day commands are in [CONTRIBUTING.md](CONTRIBUTING.md) and in the guide of each segment
([BOOT.md](BOOT.md), [CODE.md](CODE.md), [OVERLAYS.md](OVERLAYS.md)).

## Daily work on one function

| Tool | Purpose |
|---|---|
| `tools/mm` | `asm`, `m2c`, `match` and `diff` for one function (runs the WSL tools from Windows) |
| `tools/match.py` | compile one C function with IDO (7.1, or 5.3 if the file asks for it) and compare it to the ROM bytes |
| `tools/disasm_diff.py` | ROM and compiled instructions side by side for one function (behind `tools/mm diff`) |
| `tools/names.py` | apply the symbol names of `config/<segment>.names.txt` everywhere |
| `tools/check_style.sh` | source rules: no inline assembly, no `#pragma` but the `sqrtf`/`fabsf` idiom, no web address or reference to another project |

## Verification and build

| Tool | Purpose |
|---|---|
| `tools/verify_src.py`, `tools/verify_all.sh`, `tools/verify_overlays.sh` | check every C function (boot, code, overlays), then the whole rebuilt segment |
| `tools/fastcheck.sh` (`make fastcheck`) | `make check` on the native disk of WSL: when the repository is under `/mnt/`, it mirrors what the checks read (incrementally) and runs them there, 3-4 times faster; nothing is copied back |
| `tools/build_seg.py` | rebuild a segment from per-function objects and compare it to the ROM |
| `tools/verify_asm.sh` | reassemble the splat output of a segment and check it is byte-identical to the ROM |
| `tools/objcache.py` | content-addressed cache of compiled objects shared by the checks (about ten times faster re-verification) |
| `tools/progress.py` | generate `docs/PROGRESS.md` and the progress bars of this README |

## Automated search for matching C

| Tool | Purpose |
|---|---|
| `tools/auto_match.py`, `tools/auto_near.py`, `tools/auto_recipes.py` | try the m2c drafts with several IDO flag sets and mechanical tricks, then rank the near misses |
| `tools/rank_wip.py` | rank the unmatched functions by how close they are |
| `tools/diff_kind.py` | classify the difference of each unfinished draft (size, order, registers, other) to choose the right tool |
| `tools/decl_sweep.py` | try every order of the plain local declarations of each unfinished draft (stack layout and registers) |
| `tools/permute_setup.py`, `tools/permute_all.py`, `tools/flag_sweep.py` | automated search for matching C |
| `tools/permute_list.py` | run the permuter on a list of unmatched functions, or with `--auto` on every wip draft closest first, and keep what matches in `build/perm_wins/` |
| `tools/tidy_perm.py` | rewrite the raw permuter output in the project style, checking the match after every step, and move it to `src/` |
| `tools/auto_loop.sh` (`make auto HOURS=2`) | unattended: permuter queue, tidy the wins, then names and the full check; nothing is committed |
| `tools/wave.py`, `tools/wave_finish.sh` | prepare a wave of functions for the AI agents (smallest first, split in chunks), then file the new sources, apply the names and run the full check |
| `tools/AGENT_BRIEF.md`, `tools/CLEANUP_BRIEF.md` | the rules and techniques given to the AI agents that write and tidy the C |

## Source layout

| Tool | Purpose |
|---|---|
| `tools/layout.py`, `tools/layout_callers.py`, `tools/srcsort.py`, `tools/srcpath.py` | `src/boot` and `src/code` keep one folder per original source file (GitHub shows at most 1000 files per folder): `layout.py` writes the table `config/<segment>.layout.txt` once, `srcsort.py` files new flat `src/<segment>/func_*.c` into their folder, `layout_callers.py` moves a function out of `unknown/` when only one module calls it, `srcpath.py` is the lookup the other tools use |
| `tools/ref_align.py` | find candidate function names by aligning function sizes with a public symbol list (names only, see [Contributing](#contributing)) |

## Overlays

| Tool | Purpose |
|---|---|
| `tools/overlays.py` | list the overlays of the ROM file table in `config/overlays.txt` (file, section sizes, relocation count) |
| `tools/overlay_split.py` | disassemble every overlay with splat and check that the assembly rebuilds the extracted file (`asm/overlays/`) |
| `tools/overlay_auto.py` | automatic pass on the overlays (m2c drafts, mechanical recipes), then promote what matches to `src/overlays/` |

## Setup and research

| Tool | Purpose |
|---|---|
| `tools/extract.py` | decode the ROM file table, extract every file, and write `build/boot.bin` |
| `tools/setup_wsl.sh` | one-time setup inside WSL (behind `make setup`) |
| `tools/decomp.py`, `tools/mkelf.py`, `tools/ghidra/ExportDecomp.java` | Ghidra pseudo-C for a code segment (research only) |

External tools used (fetched by `make setup` into `tools/vendor/`, or installed with `apt`; none is tracked):

| Tool | Used for |
|---|---|
| IDO 7.1 and IDO 5.3 (`ido-static-recomp`) | the original compilers, see [Compilers](#compilers) |
| GNU binutils for MIPS (`mips-linux-gnu-as`, `-ld`, `-objdump`, `-nm`, `-objcopy`) | assemble, link at the original addresses, inspect objects and cut the rebuilt segment |
| splat (with spimdisasm and rabbitizer) | split the ROM segments into assembly and data |
| m2c | first-draft C from assembly |
| asm-differ | assembly comparison |
| decomp-permuter | automated search for matching C |
| Ghidra | pseudo-C for research |
| WSL (Ubuntu), Python 3, GNU make | run the tools and the checks on Windows |

