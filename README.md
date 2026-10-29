# mm-eu

A from-scratch **matching decompilation** of *The Legend of Zelda: Majora's Mask* (Europe, Rev 1) for the Nintendo 64.

The goal is a readable, modifiable C code base that the original compiler turns into **exactly the same machine code as
the retail game**. Nothing is trusted on its word: every function is recompiled with the original compiler and compared
to the ROM by an automated check, and a function that does not match is not accepted.

| Item | Detail |
|---|---|
| Game | *The Legend of Zelda: Majora's Mask*, Nintendo 64, European release, revision 1 (game code `NZSP`, version 1) |
| ROM | `The Legend of Zelda - Majora's Mask (Europe) (En,Fr,De,Es) (Rev 1)` |
| SHA-1 | `bb4e4757d10727c7584c59c1f2e5f44196e9c293` |
| Compilers | SGI IDO 7.1 (default) and IDO 5.3 (some libultra files) |
| Status | Work in progress. File names, folders and symbol names are still being reorganised from one commit to the next. |

This repository contains **no assets, no ROM data and no assembly extracted from the game**. A legally obtained copy of
the game is required.

Most of the work is carried out by artificial intelligence: the C code, the search for matching variants and the
tooling are largely AI-written, and everything it produces goes through the same byte-for-byte check.

**Contents:** [Progress](#progress) · [How it works](#how-it-works) · [Getting started](#getting-started) ·
[Repository layout](#repository-layout) · [Tools](#tools) · [Compilers](#compilers) · [Documentation](#documentation) ·
[Contributing](#contributing) · [License](#license) · [Credits](#credits)

## Progress

<!-- progress:start -->
Matching C verified byte-for-byte against the ROM (refreshed by `make progress`, last update 2026-10-29):

```
boot     functions ██████████████████████████░░░░  87.8 %  (373 / 425)
boot     code size ███████████████████░░░░░░░░░░░  63.3 %  (0xe28c / 0x165f4 bytes)
code     functions ███████████████████░░░░░░░░░░░  62.3 %  (2227 / 3576)
code     code size █████░░░░░░░░░░░░░░░░░░░░░░░░░  16.9 %  (0x2c184 / 0x104acc bytes)
overlays functions █████████░░░░░░░░░░░░░░░░░░░░░  29.3 %  (3813 / 13011)
overlays code size ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░   8.1 %  (0x455b8 / 0x35bcf4 bytes)
```
<!-- progress:end -->

Details per segment are in [docs/PROGRESS.md](docs/PROGRESS.md); planned work is in [docs/ROADMAP.md](docs/ROADMAP.md).

## How it works

```
ROM ──► extract ──► split ──► per-function C ──► per-function objects ──► linked segment ──► compare with ROM
        (files,      (asm,      (IDO 7.1)           (C where it matches,     (original          (byte-identical
        Yaz0)        data)                           assembly elsewhere)      addresses)         or rejected)
```

1. **Extract**: the file table (`dmadata`) of the ROM is decoded and every file is written out, Yaz0-decompressed.
2. **Split**: the code segments (`boot`, `code`) are disassembled into assembly and data by
   [splat](https://github.com/ethteck/splat), and are first reassembled to prove the split is lossless.
3. **Decompile**: each function is rewritten in C and compiled with the original compiler (IDO 7.1, or IDO 5.3 for the
   files that were built with the older compiler, with the flags the game was built with). The result must equal the
   original bytes of that function, apart from relocated fields.
4. **Link**: a segment is rebuilt from one object per function, taking the C version where it matches and the original
   assembly everywhere else, and linked at the original addresses.
5. **Compare**: the rebuilt segment must be byte-identical to the one in the ROM.

## Getting started

### Windows

Install WSL with an Ubuntu distribution ([Microsoft's installation guide](https://learn.microsoft.com/windows/wsl/install)),
then follow the Linux instructions inside it. Python 3 on Windows is only needed for `tools/extract.py` and `tools/mm`.

### Linux (native, WSL or VM)

1. Install the dependencies:

   ```
   sudo apt update
   sudo apt install git build-essential binutils-mips-linux-gnu curl python3 python3-pip python3-venv
   ```

2. Clone the repository and enter it.

3. Place your ROM at `baserom/The Legend of Zelda Majora's Mask (Europe).z64` (big-endian `.z64`, SHA-1 above).

4. Extract the files and set up the toolchain:

   ```
   python3 tools/extract.py
   make setup
   ```

   `tools/extract.py` also writes `build/boot.bin`, the `boot` segment cut out of the ROM (bytes `0x1000` to `0x1A8D0`),
   which `make split` and `make verify` need.

   `make setup` fetches the original compilers (IDO 7.1 and IDO 5.3, see [Compilers](#compilers)), `m2c`, `asm-differ`,
   and creates a Python environment with `splat`.

5. Split the code and verify:

   ```
   make split
   make verify SEG=boot
   ```

   If everything is correct, `make verify` reports that every C function matches the ROM and that the rebuilt segment is
   identical to it:

   ```
   boot: N MATCH, 0 not matching
   boot: N C functions + M asm -> IDENTICAL to ROM
   ```

Other targets: `make check` (verification before every commit), `make progress` refreshes `docs/PROGRESS.md`,
`make names` applies the symbol names to the sources.

## Repository layout

```
.
├── baserom/              your copy of the game (not tracked)
├── config/               splat configuration, symbol names, aliases, list of hand-written assembly functions
├── docs/                 PROGRESS.md, ROADMAP.md, CONTRIBUTING.md, BOOT.md, CODE.md, OVERLAYS.md
├── include/              types.h and the assembler macros used by the generated assembly
├── src/<segment>/        one C file per decompiled function (src/<segment>/wip/ holds unfinished attempts, not tracked);
│                         both segments have one folder per original source file (config/<segment>.layout.txt)
├── tools/                extraction, matching, verification and build scripts (tools/vendor/ is fetched, not tracked)
├── asm/  extracted/  build/   generated, not tracked
└── Makefile
```

## Tools

### Daily work on one function

| Tool | Purpose |
|---|---|
| `tools/mm` | `asm`, `m2c`, `match` and `diff` for one function (runs the WSL tools from Windows) |
| `tools/match.py` | compile one C function with IDO (7.1, or 5.3 if the file asks for it) and compare it to the ROM bytes |
| `tools/disasm_diff.py` | ROM and compiled instructions side by side for one function (behind `tools/mm diff`) |
| `tools/names.py` | apply the symbol names of `config/<segment>.names.txt` everywhere |
| `tools/check_style.sh` | source rules: no inline assembly, no `#pragma` but the `sqrtf`/`fabsf` idiom, no web address or reference to another project |

### Verification and build

| Tool | Purpose |
|---|---|
| `tools/verify_src.py`, `tools/verify_all.sh` | check every C function, then the whole rebuilt segment |
| `tools/fastcheck.sh` (`make fastcheck`) | `make check` on the native disk of WSL: when the repository is under `/mnt/`, it mirrors what the checks read (incrementally) and runs them there, 3-4 times faster; nothing is copied back |
| `tools/build_seg.py` | rebuild a segment from per-function objects and compare it to the ROM |
| `tools/verify_asm.sh` | reassemble the splat output of a segment and check it is byte-identical to the ROM |
| `tools/objcache.py` | content-addressed cache of compiled objects shared by the checks (about ten times faster re-verification) |
| `tools/progress.py` | generate `docs/PROGRESS.md` and the progress bars of this README |

### Automated search for matching C

| Tool | Purpose |
|---|---|
| `tools/auto_match.py`, `tools/auto_near.py`, `tools/auto_recipes.py` | try the m2c drafts with several IDO flag sets and mechanical tricks, then rank the near misses |
| `tools/rank_wip.py` | rank the unmatched functions by how close they are |
| `tools/permute_setup.py`, `tools/permute_all.py`, `tools/flag_sweep.py` | automated search for matching C |
| `tools/permute_list.py` | run the permuter on a list of unmatched functions, or with `--auto` on every wip draft closest first, and keep what matches in `build/perm_wins/` |
| `tools/tidy_perm.py` | rewrite the raw permuter output in the project style, checking the match after every step, and move it to `src/` |
| `tools/auto_loop.sh` (`make auto HOURS=2`) | unattended: permuter queue, tidy the wins, then names and the full check; nothing is committed |
| `tools/wave.py`, `tools/wave_finish.sh` | prepare a wave of functions for the AI agents (smallest first, split in chunks), then file the new sources, apply the names and run the full check |
| `tools/AGENT_BRIEF.md`, `tools/CLEANUP_BRIEF.md` | the rules and techniques given to the AI agents that write and tidy the C |

### Source layout

| Tool | Purpose |
|---|---|
| `tools/layout.py`, `tools/layout_callers.py`, `tools/srcsort.py`, `tools/srcpath.py` | `src/boot` and `src/code` keep one folder per original source file (GitHub shows at most 1000 files per folder): `layout.py` writes the table `config/<segment>.layout.txt` once, `srcsort.py` files new flat `src/<segment>/func_*.c` into their folder, `layout_callers.py` moves a function out of `unknown/` when only one module calls it, `srcpath.py` is the lookup the other tools use |
| `tools/ref_align.py` | find candidate function names by aligning function sizes with a public symbol list (names only, see [Contributing](#contributing)) |

### Overlays

| Tool | Purpose |
|---|---|
| `tools/overlays.py` | list the overlays of the ROM file table in `config/overlays.txt` (file, section sizes, relocation count) |
| `tools/overlay_split.py` | disassemble every overlay with splat and check that the assembly rebuilds the extracted file (`asm/overlays/`) |
| `tools/overlay_auto.py` | automatic pass on the overlays (m2c drafts, mechanical recipes), then promote what matches to `src/overlays/` |

### Setup and research

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

## Compilers

The game was not built with a single compiler version. Two builds of the original SGI IDO compiler are used, both
fetched by `make setup` into `tools/vendor/` (not tracked):

| Compiler | Folder | Used for |
|---|---|---|
| IDO 7.1 | `tools/vendor/ido71` | everything, by default |
| IDO 5.3 | `tools/vendor/ido53` | the files marked `// COMPILER: ido53` (part of libultra, e.g. the controller / Controller Pak routines and `ldiv`), which only match with the older compiler |

If you ran `make setup` before IDO 5.3 was added, just run it again: it only downloads what is missing. To install IDO 5.3
by hand (from the project root, on Linux / WSL):

```
mkdir -p tools/vendor/ido53
curl -sL https://github.com/decompals/ido-static-recomp/releases/download/v1.2/ido-5.3-recomp-linux.tar.gz | tar -xz -C tools/vendor/ido53
```

IDO 7.1 is the same with `ido-7.1-recomp-linux.tar.gz` and `tools/vendor/ido71`. Check with
`ls tools/vendor/ido71/cc tools/vendor/ido53/cc`.

A source file picks its compiler and flags in its first lines:

```c
// FLAGS: -O2 -g0 -mips2        optional, first line: optimisation flags (default -O2 -g3 -mips2)
// COMPILER: ido53              optional, within the first three lines: build this file with IDO 5.3
```

Without the second line a file is built with IDO 7.1. `tools/match.py`, `tools/verify_src.py` and
`tools/build_seg.py` all read these two lines, so a file is compiled the same way by every tool. Never switch a file to
IDO 5.3 to make it match: use it only when the original really was built with it, which shows as a function that
matches with 5.3 and not with 7.1 (typically struct copies going through `$at`).

## Documentation

| Document | Content |
|---|---|
| [docs/CONTRIBUTING.md](docs/CONTRIBUTING.md) | how to decompile a function, how symbols are named, how to run the checks |
| [docs/BOOT.md](docs/BOOT.md), [docs/CODE.md](docs/CODE.md), [docs/OVERLAYS.md](docs/OVERLAYS.md) | one guide per segment: sources, commands, what stays assembly |
| [docs/PROGRESS.md](docs/PROGRESS.md) | the numbers per segment, refreshed by `make progress` |
| [docs/ROADMAP.md](docs/ROADMAP.md) | the planned work |

## Contributing

Contributions are welcome. Start with [docs/CONTRIBUTING.md](docs/CONTRIBUTING.md).

This project is built exclusively from the analysis of a legally owned copy of the game. Anyone who wishes to
contribute must not have accessed leaked source code for the Nintendo 64 SDK, libultra, or any game that shares a
significant part of its code with this one, and must not contribute material derived from such sources.

### Sources of the code (rule for everyone, humans and AI agents)

The C code of this repository is derived from **one source only: our own European ROM** (its machine code, analysed and
verified byte for byte with the tools above).

The **only** thing taken from another project is **names**: the function names published by the US-version
decompilation, [zeldaret/mm](https://github.com/zeldaret/mm), which we register in `config/*.names.txt` (entries tagged
`ref:`) after checking that they fit our own assembly. Nothing else is taken from it or from any other project:
no C code, no function bodies, no structure layouts, no algorithms, no comments. Do not copy, paraphrase or reproduce
from memory the source of another decompilation project, of the Nintendo 64 SDK, of libultra, or of any other game, and
do not use any of it as a guide to how a function should be written. Every function must be written from the assembly of
our ROM and accepted only if it recompiles to the exact bytes. A function that cannot be written without such help stays
unfinished.

## License

The tooling and documentation are MIT-licensed. The reconstructed game code in `src/` is not licensed by this
repository: it describes a work that belongs to Nintendo and is shared for study and interoperability only. See
[LICENSE](LICENSE) for the exact scope.

## Credits

This project rests on the work of the N64 decompilation community. Thanks to the authors of:

* [splat](https://github.com/ethteck/splat) (ethteck): splits a ROM into assembly and data segments
* [spimdisasm](https://github.com/Decompollaborate/spimdisasm) and [rabbitizer](https://github.com/Decompollaborate/rabbitizer) (Decompollaborate): the MIPS disassembler used by splat
* [ido-static-recomp](https://github.com/decompals/ido-static-recomp) (decompals): the original IDO 7.1 and 5.3 compilers, recompiled for Linux
* [decomp-permuter](https://github.com/simonlindholm/decomp-permuter) (Simon Lindholm and contributors): automated search for matching C
* [m2c](https://github.com/matt-kempster/m2c) (Matt Kempster and contributors): MIPS to C decompiler
* [asm-differ](https://github.com/simonlindholm/asm-differ) (Simon Lindholm and contributors): assembly comparison
* [Ghidra](https://github.com/NationalSecurityAgency/ghidra) (NSA): initial analysis and pseudo-C
* [zeldaret/mm](https://github.com/zeldaret/mm) (the Zelda Decompilation project and contributors): decompilation of the
  US version, whose published function names (`tools/ref_align.py` aligns them with ours, entries tagged `ref:` in
  `config/*.names.txt`) are the only thing we take from it. No code, structure or other material is taken from it.
* GNU binutils: assembler, linker and `objcopy`

The names, licences and rights of these tools remain with their authors.

*The Legend of Zelda: Majora's Mask* is a trademark and a work of Nintendo. This project is not affiliated with or
endorsed by Nintendo.
