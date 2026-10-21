# Brief: match functions byte-for-byte

Goal: write C for Zelda: Majora's Mask (N64) functions that the IDO 7.1 compiler turns into **exactly** the
original machine code. The verifier is the only judge. Work from the project root with the Bash tool.

## Loop, for each function you were given (segment `boot`, or the segment named in your task)

1. `tools/mm asm <seg> <fn>` : original MIPS assembly. This is the ground truth.
2. `tools/mm m2c <seg> <fn>` : automatic draft. **Often wrong** (argument order, types); read the assembly.
3. Write `src/<seg>/<fn>.c`. First line `#include "types.h"` (s8/u8/s16/u16/s32/u32/s64/u64/f32/f64).
   Declare callees and globals with the names used in the assembly (`func_800897D0`, `D_80096CE0`),
   as `extern`/prototypes. Use a `typedef struct` with padding for struct accesses (`pad0[4]`, `unk4`, ...).
   C89: variables declared at the top of a block.
4. `tools/mm match <seg> <fn> src/<seg>/<fn>.c` : prints MATCH or the number of differing instructions.
   `tools/mm diff <seg> <fn> src/<seg>/<fn>.c` : ROM vs ours side by side (`!!` = differs).
   jal targets and %hi/%lo address parts are ignored.
5. Iterate until MATCH. Give up on a function after ~12 attempts; keep the best attempt in the file.

## Compiler flags (first line of the .c file: `// FLAGS: <flags>`; default `-O2 -g3 -mips2`)

Allowed: `-O1`/`-O2`, `-g0`/`-g3`, `-mips2`, `-mips3 -32` (only for functions with ld/sd/dmtc1/cvt.*.l), and
`-trapuv` (REQUIRED when the function starts with a stack-fill loop: `lui ..., 0xFFFA` / `ori ..., 0x5A5A`; then it
matches with the normal flags plus `-trapuv`, e.g. `// FLAGS: -O2 -g3 -mips2 -trapuv`; a SIZE DIFFERS of +0x1C..0x20 is the sign).

- Try `-O2 -g0`, then default `-O2 -g3`; `-O1` when the ROM has a filled branch delay slot that `-O2` unrolls.
- Pure forwarding wrappers (arguments shuffled into one call, no locals) usually match with `-O2 -g0`.
- 64-bit integer/float conversions and multiplies: `// FLAGS: -O1 -g0 -mips3 -32` with `u64`/`s64`.
  Example that matches: `f64 f(u64 x) { return (f64)x; }`.

## Idioms that decide matches

- `return G = expr;` puts the store in the `jr` delay slot. Splitting it into temp + store + return does not.
- Branch layout comes from the source: `if (p != 0) { ... return x; } return -1;` can match where
  `if (p == 0) return -1;` does not. `if (!a)` vs `if (a == 0)` can change register allocation.
- Pointer-walk loops written as `while` with an early `if` give the branch-likely pattern.
- Signedness (`s32` vs `u32`, `u8` vs `s8`) changes slt/sltu, lb/lbu, shifts. Check the instructions.
- Statement order and temporaries change register allocation and scheduling.
- EXCEPTION for inline `sqrt.s`: declare first, THEN the pragma (the order matters): `float sqrtf(float);` newline
  `#pragma intrinsic (sqrtf)`, then call `sqrtf(x)`. This matched func_80086C88 (`-O2 -g0 -mips2`).
- Otherwise do NOT use `#pragma intrinsic` or inline asm. Never write a function that matches by embedding raw
  instruction words; it must be real C.

- Local declaration order decides stack slots and which saved register a local gets: sweep it (cheap).
  Example: `u8 sp48[0x20]; u8 sp30[0x18]; u8 sp2C[4];` matched, other orders did not.
- A stack-spill-only function with unused args (`sw a0..a3`) matches as varargs: `void f(s32 a0, ...) {}` (`-O2 -g0`).
- A global reached via `lui`+`addiu` then `lw/sb` needs the `*(T *)&SYM` form; a plain `extern T SYM` gives `lui`+`lw %lo`.
- A hardware register load matches as a literal address: `*(u32 *)0xA4040010`.
- `if (a < b) x = a; else x = b;` (explicit else) matches a `b` with the assignment in the delay slot.
- Write `CONST == x` instead of `x == CONST` if branch operand order differs. `-g3` keeps parameters spilled.
- If the ROM reads `0x34(sp)` in a small frame, the function has a 5th unused argument.
- A loop whose condition load sits in a `bnel` delay slot: put the condition in a temp.

## Rules

- Only create/edit `src/<seg>/<fn>.c` for the functions you were given. Never touch tools/, asm/, config/,
  include/ or other agents' files. If a struct/type is shared, define it locally in your file.
- An unmatched function is acceptable. Do not fake a match.

## Final report (short)

One line per function: `<fn> MATCH` or `<fn> FAIL (<n> instr differ; what you tried)`, then at most 3 lines of
new lessons (flags/idioms) not listed above.

## Second pass: functions that are already close (read this if your function has an existing draft in src/boot/wip/)

Start from the existing `src/boot/wip/<fn>.c` (move/copy it to `src/boot/<fn>.c` to test with `tools/mm match`; move it back
to wip/ if it still fails). Use `tools/mm diff` and fix ONE difference at a time, re-running match after each edit.
The remaining differences are almost always register allocation or stack layout. Things that worked on other functions:

- Keep a global's address in a pointer local (`u8 *p = &G;`): IDO then keeps it in a saved register like the ROM does.
- `register` on locals that live across calls moves them to callee-saved registers (and can flip a stack spill into a register).
- A local struct that groups several locals pins their stack offsets (`struct { u8 a[0x18]; u8 b[0x20]; s64 c; } l;`);
  separate locals do not. Unused padding locals/arrays fix a frame that is 8/16 bytes short.
- Local declaration order decides stack slot and callee-saved register; try every permutation of 2-4 locals.
- `a->x != b->x` vs `b->x != a->x` flips operand order of a branch. `CONST == x` vs `x == CONST`, `!x` vs `x == 0` too.
- Splitting or merging an expression into a temp changes scheduling; so does `return G = e;` vs separate store+return.
- `-O1` keeps one `lui`+`lw` per global access (matches ROMs that reload); `-O2` hoists the address. Try both, with -g0 and -g3.
- A loop the ROM does NOT unroll but -O2 unrolls: index loop, non-constant bound, or -O1.
- Unaligned halfword/word store/load (`swl/swr`, `lwl/lwr`): `*(u32 *)0x...1` style or a `u8 b[8]` struct copy.
- `u8`/`u16` parameters produce the `sw aN` spill + `andi` the ROM shows; `s32` does not.
- For the ROM's `-trapuv` prologue the register choice (t0/t1 vs t9/t0) follows register pressure of the body.
- Large functions: try `-O2 -g0` first; it can fix the whole prologue ordering that `-g3` gets wrong.
- One extra/missing instruction shifts every later offset, so `tools/mm match` then reports hundreds of differences:
  read `tools/mm diff` by instruction content to count the real ones.
- The decomp-permuter is also running over all wip functions in the background (CPU only); do not start your own permuter.
