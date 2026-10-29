# mm-eu

This is a work-in-progress decompilation of *The Legend of Zelda: Majora's Mask* for the Nintendo 64, European
release, revision 1 (`NZSP`, version 1, SHA-1 `bb4e4757d10727c7584c59c1f2e5f44196e9c293`).

The goal is C code that the original compiler (SGI IDO 7.1, and IDO 5.3 for part of libultra) turns into the exact
machine code of the ROM. Every function is recompiled and compared with the ROM, and one that does not match is not
accepted.

The repository contains no assets, no ROM data and no assembly extracted from the game. You need your own copy of the
game to build anything. Names of files, folders and symbols are still being reorganised from one commit to the next.

Most of the C code and the tooling were written with an AI assistant. All of it goes through the same byte-for-byte check.

## Progress

<!-- progress:start -->
Matching C verified byte-for-byte against the ROM (refreshed by `make progress`, last update 2026-10-29):

```
boot     functions ███████████████████████████░░░  91.4 %  (383 / 419)
boot     code size █████████████████████░░░░░░░░░  70.7 %  (0xfd38 / 0x165f4 bytes)
code     functions ███████████████████░░░░░░░░░░░  63.4 %  (2268 / 3576)
code     code size █████░░░░░░░░░░░░░░░░░░░░░░░░░  17.8 %  (0x2e534 / 0x104acc bytes)
overlays functions █████████░░░░░░░░░░░░░░░░░░░░░  30.1 %  (3914 / 13011)
overlays code size ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░   8.2 %  (0x465e0 / 0x35bcf4 bytes)
```
<!-- progress:end -->

More detail per segment is in [docs/PROGRESS.md](docs/PROGRESS.md), and the plan is in [docs/ROADMAP.md](docs/ROADMAP.md).

## Building

On Windows, install [WSL](https://learn.microsoft.com/windows/wsl/install) with Ubuntu and run everything below inside it
(Python 3 on Windows is only needed for `tools/extract.py` and `tools/mm`).

1. Install the dependencies:

   ```
   sudo apt update
   sudo apt install git build-essential binutils-mips-linux-gnu curl python3 python3-pip python3-venv
   ```

2. Clone the repository and enter it.

3. Put your ROM at `baserom/The Legend of Zelda Majora's Mask (Europe).z64` (big-endian `.z64`).

4. Extract the files and set up the toolchain:

   ```
   python3 tools/extract.py
   make setup
   ```

   `make setup` downloads the compilers, `m2c`, `asm-differ` and `splat` (see [docs/COMPILERS.md](docs/COMPILERS.md)).

5. Split the code and check that it matches:

   ```
   make split
   make verify SEG=boot
   ```

   `make verify` should report that every C function matches and that the rebuilt segment is identical to the ROM.

`make check` runs the full verification before a commit (`make fastcheck` is quicker under WSL). The scripts in `tools/`
are described in [docs/TOOLS.md](docs/TOOLS.md).

## Repository layout

```
baserom/    your copy of the game (not tracked)
config/     splat configuration, symbol names, list of hand-written assembly functions
docs/       guides and progress
include/    types.h and the assembler macros
src/        decompiled C, one file per function, one folder per original source file
tools/      extraction, matching, verification and build scripts
```

`asm/`, `extracted/` and `build/` are generated and not tracked. Unfinished attempts live in `src/<segment>/wip/` and are not
tracked either.

## Documentation

- [CONTRIBUTING.md](docs/CONTRIBUTING.md): how to decompile a function, how symbols are named, how to run the checks
- [BOOT.md](docs/BOOT.md), [CODE.md](docs/CODE.md), [OVERLAYS.md](docs/OVERLAYS.md): one guide per segment
- [TOOLS.md](docs/TOOLS.md) and [COMPILERS.md](docs/COMPILERS.md): the scripts and the IDO compilers
- [PROGRESS.md](docs/PROGRESS.md) and [ROADMAP.md](docs/ROADMAP.md)

## Contributing

Contributions are welcome, see [docs/CONTRIBUTING.md](docs/CONTRIBUTING.md). Do not contribute anything derived from leaked
source code of the Nintendo 64 SDK, libultra or any game that shares much of its code with this one.

The C is derived from our own European ROM: it is written from its assembly and accepted only if it recompiles to the exact
bytes. From other projects we take function names only, from the US decompilation [zeldaret/mm](https://github.com/zeldaret/mm)
(entries tagged `ref:` in `config/*.names.txt`).

There is one exception, by my decision. The library functions of `boot` (libultra, libgu, libm, libc) are shared with other
games and have been decompiled by community projects (so far only zeldaret/mm), so their published work may be consulted for
structure and types. The code is still written here from our assembly and verified byte for byte, with nothing copied
verbatim. `code` and the overlays use nothing from other projects.

## License

The tooling and documentation are MIT-licensed. The reconstructed game code in `src/` is not licensed by this repository: it
describes a work that belongs to Nintendo and no right on it is granted. See [LICENSE](LICENSE).

## Credits

- [splat](https://github.com/ethteck/splat) (ethteck), with [spimdisasm](https://github.com/Decompollaborate/spimdisasm) and
  [rabbitizer](https://github.com/Decompollaborate/rabbitizer) (Decompollaborate): ROM splitting and MIPS disassembly
- [ido-static-recomp](https://github.com/decompals/ido-static-recomp) (decompals): IDO 7.1 and 5.3 for Linux
- [decomp-permuter](https://github.com/simonlindholm/decomp-permuter) and [asm-differ](https://github.com/simonlindholm/asm-differ)
  (Simon Lindholm and contributors)
- [m2c](https://github.com/matt-kempster/m2c) (Matt Kempster and contributors)
- [Ghidra](https://github.com/NationalSecurityAgency/ghidra) (NSA)
- [zeldaret/mm](https://github.com/zeldaret/mm) (the Zelda Decompilation project and contributors): the function names
  (`tools/ref_align.py` aligns them with ours) and, for `boot` only, the structure and types of the Nintendo 64 library
  functions (see Contributing). Nothing is copied verbatim.
- GNU binutils

*The Legend of Zelda: Majora's Mask* is a trademark and a work of Nintendo. This project is not affiliated with or endorsed
by Nintendo.
