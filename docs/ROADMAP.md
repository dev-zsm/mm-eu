# Roadmap

Current numbers: [PROGRESS.md](PROGRESS.md) (`make progress`). Verification: `make verify`.

## 1. `boot` segment (in progress)

- [x] ROM extraction, segment split, lossless reassembly, IDO matching tool, automated search tools.
- [ ] Every function that can be written in C is written in C and verified.
- [ ] Functions that were hand-written assembly in the original (listed in `config/boot.asm_only.txt`) stay as assembly
      and are excluded from the C count.
- [ ] Symbol names: official SDK / libc / libm names where the code proves them, evidence-backed project names otherwise
      (`config/boot.names.txt`).
- [ ] Source organised by module (`src/libultra/os/...`, `src/libc/...`, `src/libm/...`) with shared headers
      (`OSThread`, `OSMesgQueue`, hardware registers).
- [ ] Data (`.data`, `.rodata`, jump tables, strings) expressed in C with proper types.
- [ ] Segment rebuilt without any assembly other than the original hand-written functions, identical to the ROM.

## 2. `code` segment

Same method on the main game code (about 3,500 functions).

## 3. Overlays

Split the file table into overlays (actors, scenes, menus), one source file each.

## 4. Full ROM

Byte-identical recompression of the compressed files and rebuilding of the file table.

## 5. PC port

Rendering, audio and input layers on top of the C code base.
