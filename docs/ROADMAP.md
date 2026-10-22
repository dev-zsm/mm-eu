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

## Later: names, layout and readability (after all the C matches)

These are deliberately postponed until every function is written in C and verified: with the whole code base in
hand, how each variable and structure field is used across the game is visible, and the work is easier and more
reliable. Matching comes first.

- [ ] **Remaining function names.** About 750 functions still carry their address name (`func_8009XXXX`). Names are
      added only with evidence (`sdk:`, `ref:` or `inferred:` in `config/*.names.txt`).
- [ ] **Variable names.** No data symbol (`D_XXXXXXXX`) is named yet. They can be aligned with the reference
      research the same way functions were (`tools/ref_align.py`), then confirmed from their use in the code.
- [ ] **Source files named after their function** instead of their address, then grouped into modules
      (one file per module, in the original order of the code).
- [ ] **Structure types.** Replace the local `typedef struct` with padding (`unk1C`, `pad0`) by shared types in
      `include/`, with named fields.
- [ ] **Drafts to clean up.** Rewrite the verified drafts that still use raw field offsets (`M2C_FIELD`) once the
      structures are known (the count is in [PROGRESS.md](PROGRESS.md)).
- [ ] Data (`.data`, `.rodata`, strings, jump tables) expressed in C with proper types.
