# Contributing

Goal: C code that the original compiler (IDO 7.1) turns into the **exact bytes** of the retail ROM, readable enough
to modify the game. All checks run inside WSL / Linux (`make setup` first, see the README).

## Adding or fixing a function

1. Look at the original: `tools/mm asm boot func_XXXXXXXX`. `tools/mm m2c boot func_XXXXXXXX` gives a first draft;
   it is frequently wrong (argument order, types), so read the assembly.
2. Write `src/boot/func_XXXXXXXX.c` (same flat form for `code`; `python3 tools/srcsort.py`,
   which `tools/wave_finish.sh` runs, then files it into its source-file folder from `config/<segment>.layout.txt`). The optional first line `// FLAGS: ...` sets the compiler flags when the
   default (`-O2 -g3 -mips2`) is not what the function was built with.
3. `tools/mm match boot func_XXXXXXXX src/boot/func_XXXXXXXX.c` must print `MATCH`. `tools/mm diff ...` shows the
   original and the compiled instructions side by side. Unfinished attempts go to `src/boot/wip/`.
   On Linux, without the Windows wrapper, run the underlying tools directly (after `. ~/mm-venv/bin/activate`):
   `awk '/^glabel FN$/{p=1} p{print} /^endlabel FN$/{exit}' asm/boot/text.s` (assembly),
   `python3 tools/vendor/m2c/m2c.py -t mips-ido-c -f FN asm/boot/text.s` (draft),
   `python3 tools/match.py boot FN src/boot/FN.c` and `python3 tools/disasm_diff.py boot FN src/boot/FN.c`.
4. Call functions that have a name in `config/boot.names.txt` by that name, and every other function by its `func_`
   address name; never invent a name. `make names SEG=boot` rewrites the sources with the registered names, and
   `tools/match.py` ignores `jal` targets, so a wrong callee is only caught by step 5.
5. `make check` must pass before any commit. It runs `make verify` for `boot` and for `code` (every C function equals
   the ROM bytes, and the segment rebuilt from the C plus the remaining assembly is byte-identical to the ROM), then
   the source style rules of `tools/check_style.sh`. While working on one segment, `make verify SEG=boot` or
   `SEG=code` alone is enough; compiled objects are cached, so only the files you changed are compiled again.

Compiler: IDO 7.1 by default. A function that only differs by the scratch register of struct copies (`$at` in the ROM,
`t`-registers in ours), or that no source form can match with 7.1, may have been built with IDO 5.3: add
`// COMPILER: ido53` in the first three lines (after the `// FLAGS:` line) and run `tools/match.py` again. See the
Compilers section of the README. Do not use 5.3 just to get a match: it must match as plain, natural C.

Techniques that make the compiler produce the original code are collected in `tools/AGENT_BRIEF.md`. For register
allocation and stack layout problems, use the automated tools: `tools/permute_all.py` (decomp-permuter) and
`tools/flag_sweep.py` (compiler flag combinations).

## Symbol names (`config/<segment>.names.txt`)

One line per renamed symbol: `old_name new_name   # sdk|inferred: evidence`.

* `sdk:` the function is a known N64 SDK / libc / libm routine and the code proves it (structure, constants, hardware
  registers). Use the official name (`osCreateMesgQueue`, `__osDisableInt`, `sinf`).
* `inferred:` a project name chosen from the behaviour (`Module_Verb`, e.g. `Arena_Free`). State the evidence. Never
  present a guess as an SDK name.
* A wrong name is worse than the address name. When unsure, keep `func_XXXXXXXX` and describe the behaviour in a
  comment.

`tools/names.py` and `tools/build_seg.py` apply the names to the C, the assembly, the data and the link. File names keep
the address.

## Code style

* Use the types of `include/types.h` (`s32`, `u32`, `f32`, ...). No inline assembly and no `#pragma intrinsic`, except
  the documented `sqrtf` idiom.
* Anything that exists only to make the compiler match (padding locals, `volatile`, an unusual declaration order, an
  alias symbol from `config/<segment>.aliases.txt`) gets a one-line comment saying why.
* Structures keep their exact offsets. Name the fields you understand; keep `unkXX` / `padXX` for the others.
* `config/<segment>.aliases.txt` (an extra symbol at a known address, only to steer IDO) is technical debt: each entry
  has a comment saying why and is removed once the real expression is found.
* Keep generated and ROM-derived content out of git (`baserom/`, `extracted/`, `asm/`, `decomp/`, `build/`).

## Legal

This project is built only from the analysis of a legally owned copy of the game. Do not contribute material derived
from leaked source code (Nintendo 64 SDK, libultra, or any game sharing significant code with this one).

## Overlays

Overlays (actors, scenes, menus) are the next stage after `boot` and `code`; the steps are in [OVERLAYS.md](OVERLAYS.md).
`python3 tools/overlays.py` (after `tools/extract.py`) lists them in `config/overlays.txt`. Until the overlay build
exists, the useful contributions are tooling: disassembly configurations, the relocation-aware builder and its
verification. The rules of the other segments apply unchanged: only the assembly of our ROM and the local tools,
no code from other projects, English only, no inline assembly.
