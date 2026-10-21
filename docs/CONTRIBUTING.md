# Contributing

Goal: C code that the original compiler (IDO 7.1) turns into the **exact bytes** of the retail ROM, readable enough
to modify the game. All checks run inside WSL / Linux (`make setup` first, see the README).

## Adding or fixing a function

1. Look at the original: `tools/zmm asm boot func_XXXXXXXX`. `tools/zmm m2c boot func_XXXXXXXX` gives a first draft;
   it is frequently wrong (argument order, types), so read the assembly.
2. Write `src/boot/func_XXXXXXXX.c`. The optional first line `// FLAGS: ...` sets the compiler flags when the
   default (`-O2 -g3 -mips2`) is not what the function was built with.
3. `tools/zmm match boot func_XXXXXXXX src/boot/func_XXXXXXXX.c` must print `MATCH`. `tools/zmm diff ...` shows the
   original and the compiled instructions side by side. Unfinished attempts go to `src/boot/wip/`.
4. `make verify SEG=boot` must pass before any commit: every C function equals the ROM bytes, and the segment rebuilt
   from the C plus the remaining assembly is byte-identical to the ROM.

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
* Keep generated and ROM-derived content out of git (`baserom/`, `extracted/`, `asm/`, `decomp/`, `build/`).

## Legal

This project is built only from the analysis of a legally owned copy of the game. Do not contribute material derived
from leaked source code (Nintendo 64 SDK, libultra, or any game sharing significant code with this one).
