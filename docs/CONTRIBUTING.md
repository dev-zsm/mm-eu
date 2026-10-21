# Conventions

Goal: C that compiles with IDO 7.1 to the **exact bytes** of the PAL Rev 1 ROM, readable enough to modify the game.

## Adding a function
1. `tools/zmm asm boot func_XXXXXXXX` for the original; `tools/zmm m2c ...` for a draft (it is often wrong).
2. Write `src/boot/func_XXXXXXXX.c`. First line `// FLAGS: ...` when the default `-O2 -g3 -mips2` is not what the function was built with.
3. `tools/zmm match boot func_XXXXXXXX src/boot/func_XXXXXXXX.c` must print `MATCH`. Unfinished attempts go in `src/boot/wip/`.
4. `make verify` must pass before a commit.

Techniques that decide matches are listed in `tools/AGENT_BRIEF.md`. For register-allocation problems use
`tools/permute_setup.py` + `tools/vendor/decomp-permuter` (see `tools/permute_all.py`).

## Names (`config/<seg>.names.txt`)
`old_name new_name   # sdk|inferred: evidence`
- `sdk:` the function is a known N64 SDK / libc / libm routine and the code shows it (structure, constants, strings, hardware registers). Use the official name (`osCreateMesgQueue`, `__osDisableInt`, `sinf`).
- `inferred:` project name chosen from behaviour (`Module_Verb`, e.g. `Arena_Free`). Say what the evidence is. Never present a guess as an SDK name.
- A wrong name is worse than `func_XXXXXXXX`: when unsure, keep the address name and describe the behaviour in a comment.
Names are applied to the C, the assembly, the data and the link by `tools/names.py` / `tools/build_seg.py`; file names keep the address.

## Style
- `include/types.h` types only (`s32`, `u32`, `f32`...). No `#pragma intrinsic` / inline asm, except the documented `sqrtf` idiom.
- Padding locals, `volatile`, odd declaration order that exist only to match get a one-line `/* why */`.
- Structs keep exact offsets; name the fields you understand, keep `unkXX` / `padXX` for the rest.
- No ROM data or ROM-derived files in git (`baserom/`, `extracted/`, `asm/`, `decomp/`, `build/`).
