# mm-eu

This is a work-in-progress decompilation of *The Legend of Zelda: Majora's Mask* for the Nintendo 64, European
release, revision 1 (`NZSP`, version 1, SHA-1 `bb4e4757d10727c7584c59c1f2e5f44196e9c293`).

The goal is C code that the original compiler (SGI IDO 7.1, and IDO 5.3 for part of libultra) turns into the exact
machine code of the ROM. Every function is recompiled and compared with the ROM, and one that does not match is not
accepted.

The repository contains no assets, no ROM data and no assembly extracted from the game. You need your own copy of the
game to build anything. Names of files, folders and symbols are still being reorganised from one commit to the next.

This project is vibe coded: most of the C code and the tooling were written with an AI assistant. All of it goes through the
same byte-for-byte check.

## Progress

<!-- progress:start -->
Matching C verified byte-for-byte against the ROM (refreshed by `make progress`, last update 2026-10-30):

```
boot     ████████████████████████████░░  93.1 %  (390 / 419)
code     ███████████████████░░░░░░░░░░░  63.4 %  (2268 / 3576)
overlays ██████████░░░░░░░░░░░░░░░░░░░░  31.7 %  (4128 / 13011)
```
<!-- progress:end -->

`boot` and `code` are also rebuilt whole and compared with the ROM. The overlays are only checked function by function for
now, with relocated fields masked, so a wrong call target or data address is not caught until the overlay build exists.

More detail per segment is in [docs/PROGRESS.md](docs/PROGRESS.md), and the plan is in [docs/ROADMAP.md](docs/ROADMAP.md).

## Building

On Windows, install [WSL](https://learn.microsoft.com/windows/wsl/install) with Ubuntu and run everything below inside it
(outside WSL only the `tools/mm` wrapper is used; it needs a bash such as Git Bash).

1. Install the dependencies:

   ```
   sudo apt update
   sudo apt install git build-essential binutils-mips-linux-gnu curl rsync python3 python3-pip python3-venv
   ```

2. Clone the repository and enter it.

3. Put your ROM at `baserom/The Legend of Zelda Majora's Mask (Europe).z64` (big-endian `.z64`).

4. Extract the files and set up the toolchain:

   ```
   python3 tools/extract.py
   make setup
   ```

   `make setup` downloads the compilers, `m2c`, `asm-differ`, `decomp-permuter` and `splat` (see
   [docs/COMPILERS.md](docs/COMPILERS.md)).

5. Split the code and check that it matches:

   ```
   make split
   make verify SEG=boot
   ```

   `make split` also disassembles the 616 overlays, which takes a while. `make verify` should report that every C
   function matches and that the rebuilt segment is identical to the ROM.

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

Contributions are welcome, see [docs/CONTRIBUTING.md](docs/CONTRIBUTING.md). Whatever the source of a function, it is accepted
only if it recompiles with IDO to the exact bytes of this ROM.

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
- [zeldaret/mm](https://github.com/zeldaret/mm) (the Zelda Decompilation project and contributors): the decompilation of the
  US release of this game, which this project draws inspiration from.
- GNU binutils

*The Legend of Zelda: Majora's Mask* is a trademark and a work of Nintendo. This project is not affiliated with or endorsed
by Nintendo.
