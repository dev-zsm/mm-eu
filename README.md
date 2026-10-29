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
boot     functions ███████████████████████████░░░  91.2 %  (382 / 419)
boot     code size █████████████████████░░░░░░░░░  70.1 %  (0xfb10 / 0x165f4 bytes)
code     functions ███████████████████░░░░░░░░░░░  63.4 %  (2268 / 3576)
code     code size █████░░░░░░░░░░░░░░░░░░░░░░░░░  17.8 %  (0x2e534 / 0x104acc bytes)
overlays functions █████████░░░░░░░░░░░░░░░░░░░░░  29.7 %  (3868 / 13011)
overlays code size ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░   8.1 %  (0x45f6c / 0x35bcf4 bytes)
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

The scripts of `tools/` (matching, verification, automatic search, source layout, overlays) and the external tools they use are
described in [docs/TOOLS.md](docs/TOOLS.md). The commands needed most:

```
tools/mm match <segment> <function> <file.c>   check one function against the ROM
make check                                      verify everything before a commit (make fastcheck on WSL: faster)
make progress                                   refresh the numbers
```

## Compilers

The game is built with the original SGI IDO compiler: **IDO 7.1** by default, and **IDO 5.3** for the files marked
`// COMPILER: ido53` (part of libultra). `make setup` fetches both into `tools/vendor/`. Installation, the source-file header and
the rules for choosing the compiler are in [docs/COMPILERS.md](docs/COMPILERS.md).

## Documentation

| Document | Content |
|---|---|
| [docs/CONTRIBUTING.md](docs/CONTRIBUTING.md) | how to decompile a function, how symbols are named, how to run the checks |
| [docs/BOOT.md](docs/BOOT.md), [docs/CODE.md](docs/CODE.md), [docs/OVERLAYS.md](docs/OVERLAYS.md) | one guide per segment: sources, commands, what stays assembly |
| [docs/PROGRESS.md](docs/PROGRESS.md) | the numbers per segment, refreshed by `make progress` |
| [docs/ROADMAP.md](docs/ROADMAP.md) | the planned work |
| [docs/TOOLS.md](docs/TOOLS.md) | the scripts of `tools/` and the external tools |
| [docs/COMPILERS.md](docs/COMPILERS.md) | the IDO compilers: installation, the header of a source file, when to use IDO 5.3 |

## Contributing

Contributions are welcome: start with [docs/CONTRIBUTING.md](docs/CONTRIBUTING.md). The project is built only from the analysis of a
legally owned copy of the game: do not contribute material derived from leaked source code of the Nintendo 64 SDK, libultra or any game
that shares much of its code with this one.

**Sources of the code.** The C is derived from our own European ROM only: written from its assembly and accepted only if it recompiles
to the exact bytes. From other projects we take only the **function names** of the US decompilation
[zeldaret/mm](https://github.com/zeldaret/mm), registered in `config/*.names.txt` (entries tagged `ref:`) once they fit our assembly.
No code, structure, algorithm or comment is copied from any project or SDK.

**Exception, `boot` only (my decision).** The library functions of `boot` (libultra, libgu, libm, libc) are shared with other games and
have been decompiled by community projects: their published work may be consulted as a reference for structure and types. The C is
still written here from our ROM's assembly and verified byte for byte, with nothing copied verbatim. `code` and the overlays stay
ROM-only. The projects consulted are credited in [Credits](#credits).

## License

The tooling and documentation are MIT-licensed. The reconstructed game code in `src/` is not licensed by this
repository: it describes a work that belongs to Nintendo, and no right on it is granted. See
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
* Community decompilation projects of the Nintendo 64 libraries (for example [zeldaret/mm](https://github.com/zeldaret/mm)
  and other decompilation projects): consulted as a reference for the structure and typing of the libultra, libgu, libm and
  libc functions of the `boot` segment only (see the exception in [Contributing](#contributing)). The C here is written and
  verified against our own ROM.
* GNU binutils: assembler, linker and `objcopy`

The names, licences and rights of these tools remain with their authors.

*The Legend of Zelda: Majora's Mask* is a trademark and a work of Nintendo. This project is not affiliated with or
endorsed by Nintendo.
