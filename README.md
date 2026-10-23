# mm-n64-europe

A from-scratch matching decompilation of *The Legend of Zelda: Majora's Mask* (Europe, Rev 1) for the Nintendo 64.

> **Status: early stage.** Most of the game is not decompiled yet, and file names, folders and symbol names are
> still being reorganised from one commit to the next. Treat everything here as unstable for now.

This is a work-in-progress, from-scratch **matching decompilation** of *The Legend of Zelda: Majora's Mask* for the
Nintendo 64, European release, revision 1 (game code `NZSP`, version 1). The goal is to recreate a readable and
modifiable C code base that the original compiler turns into **exactly the same machine code as the retail game**,
and, once that is done, to build further tooling on top of it (including a native PC port).

Most of the work in this repository is carried out by artificial intelligence: the C code, the search for matching
variants and the tooling are largely AI-written. Nothing is trusted on its word. Every function is recompiled with the
original compiler and compared to the ROM by an automated check (`make verify`), and a function that does not match is
not accepted.

This repository contains **no assets, no ROM data and no assembly extracted from the game**. A legally obtained copy of
the game is required. Current progress is tracked in [docs/PROGRESS.md](docs/PROGRESS.md) and planned work in
[docs/ROADMAP.md](docs/ROADMAP.md).

* ROM: `The Legend of Zelda - Majora's Mask (Europe) (En,Fr,De,Es) (Rev 1)`
* SHA-1: `bb4e4757d10727c7584c59c1f2e5f44196e9c293`

## Progress

<!-- progress:start -->
Matching C verified byte-for-byte against the ROM (refreshed by `make progress`, last update 2026-10-23):

```
boot  functions █████████████████████████░░░░░  84.7 %  (360 / 425)
boot  code size █████████████████░░░░░░░░░░░░░  57.5 %  (0xcde4 / 0x165f4 bytes)
code  functions ████████░░░░░░░░░░░░░░░░░░░░░░  28.3 %  (1013 / 3576)
code  code size ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░   5.5 %  (0xe60c / 0x104acc bytes)
overlays   (actors, scenes, menus): not started
```
<!-- progress:end -->

## How it works

```
ROM ──► extract ──► split ──► per-function C ──► per-function objects ──► linked segment ──► compare with ROM
        (files,      (asm,      (IDO 7.1)           (C where it matches,     (original          (byte-identical
        Yaz0)        data)                           assembly elsewhere)      addresses)         or rejected)
```

1. **Extract**: the file table (`dmadata`) of the ROM is decoded and every file is written out, Yaz0-decompressed.
2. **Split**: the code segments (`boot`, `code`) are disassembled into assembly and data by
   [splat](https://github.com/ethteck/splat), and are first reassembled to prove the split is lossless.
3. **Decompile**: each function is rewritten in C and compiled with the original compiler (IDO 7.1, or IDO 5.3 for the files
   that were built with the older compiler, with the flags the game was built with). The result must equal the original bytes of that function, apart from relocated fields.
4. **Link**: a segment is rebuilt from one object per function, taking the C version where it matches and the original
   assembly everywhere else, and linked at the original addresses.
5. **Compare**: the rebuilt segment must be byte-identical to the one in the ROM.

## Repository layout

```
.
├── baserom/              your copy of the game (not tracked)
├── config/               splat configuration, symbol names, aliases, list of hand-written assembly functions
├── docs/                 PROGRESS.md, ROADMAP.md, CONTRIBUTING.md
├── include/              types.h and the assembler macros used by the generated assembly
├── src/<segment>/        one C file per decompiled function (src/<segment>/wip/ holds unfinished attempts)
├── tools/                extraction, matching, verification and build scripts (tools/vendor/ is fetched, not tracked)
├── asm/  extracted/  build/   generated, not tracked
└── Makefile
```

Main tools:

| Tool | Purpose |
|---|---|
| `tools/extract.py` | decode the ROM file table, extract every file, and write `build/boot.bin` |
| `tools/mm` | `asm`, `m2c`, `match` and `diff` for one function (runs the WSL tools from Windows) |
| `tools/match.py` | compile one C function with IDO (7.1, or 5.3 if the file asks for it) and compare it to the ROM bytes |
| `tools/verify_src.py`, `tools/verify_all.sh` | check every C function, then the whole rebuilt segment |
| `tools/build_seg.py` | rebuild a segment from per-function objects and compare it to the ROM |
| `tools/names.py` | apply the symbol names of `config/<segment>.names.txt` everywhere |
| `tools/permute_setup.py`, `tools/permute_all.py`, `tools/flag_sweep.py` | automated search for matching C |
| `tools/progress.py` | generate `docs/PROGRESS.md` |

## Installation

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

Other targets: `make progress` refreshes `docs/PROGRESS.md`, `make names` applies the symbol names to the sources.

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

## Contributing

Contributions are welcome. Start with [docs/CONTRIBUTING.md](docs/CONTRIBUTING.md), which explains how to decompile a
function, how symbols are named and how to run the checks.

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
