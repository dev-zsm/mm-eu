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

About 600 files of the ROM file table are overlays (actors, scenes, menus): code that the game loads on demand.
Each one is a small relocatable program: `text | data | rodata | header | relocations | footer`.

- [x] Inventory: `tools/overlays.py` finds them in `extracted/` and writes `config/overlays.txt`
      (file index, start in the virtual ROM, section sizes, relocation count). 616 found, about 3.5 MB of code.
- [x] Disassembly: `tools/overlay_split.py` generates one splat configuration per overlay, writes the assembly to
      `asm/overlays/<index>/` and checks that it rebuilds the file: 595 of 616 overlays are byte-identical (13,011
      functions). The other 21 differ in the read-only data (strings, alignment), a known limit to fix.
- [ ] Relocations: use the relocation table to name the symbols that point into the same overlay (`D_`/`func_`
      with the overlay index), and keep the header, relocations and footer as data in the rebuild.
- [ ] Build: a segment builder for overlays (like `tools/build_seg.py`, but linking the relocated sections and
      checking the relocation table too), so that each overlay is verified byte for byte against its file.
- [ ] Order of work: the smallest overlays first (they match fastest), then the large ones; one folder per
      overlay under `src/overlays/`, and the progress numbers are counted per overlay in `docs/PROGRESS.md`.
- [ ] Layout: `src/overlays/<kind>/ovl_<name>/` with one folder per overlay and the kinds `actors`, `effects`,
      `fbdemos`, `gamestates` and `kaleido_scope` (the usual layout of decompilation projects of this game). Until an
      overlay has a name its folder is `ovl_<file index>` and its kind is `unknown`.
- [ ] Names: `config/overlays.names.txt` (`<file index> <name>  # <evidence>`), checked like the other name files. A name
      is added only with evidence (the order of the file table, the number of overlays and the relocations of an
      overlay that points to a known function), never from memory of another project's source code.

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
- [x] `src/boot` and `src/code` are already split into one folder per original source file (`config/<segment>.layout.txt`, boundaries
      inferred from the registered names, so approximate).
- [ ] **Source files named after their function** instead of their address, then merged into one file per module
      (in the original order of the code), checking the boundaries of `config/<segment>.layout.txt`.
- [ ] **Structure types.** Replace the local `typedef struct` with padding (`unk1C`, `pad0`) by shared types in
      `include/`, with named fields.
- [ ] **Drafts to clean up.** Rewrite the verified drafts that still use raw field offsets (`M2C_FIELD`) once the
      structures are known (the count is in [PROGRESS.md](PROGRESS.md)).
- [ ] Data (`.data`, `.rodata`, strings, jump tables) expressed in C with proper types.
