# Brief: make a matched function readable WITHOUT changing the machine code

Each `src/<seg>/<fn>.c` you are given already compiles to exactly the original bytes. Your job is to turn it into
clean, readable C that a maintainer could improve the game from. The verifier decides: after every edit run
`tools/mm match <seg> <fn> src/<seg>/<fn>.c`. If it no longer says MATCH, undo that edit (keep the last matching version).

Read `tools/mm asm <seg> <fn>` when you need to understand what the function really does.

## What to improve (in this order)

1. **Names.** Replace `arg0`, `sp1C`, `temp_v0`, `var_s0`, `unk4`... by names that say what the value is
   (`queue`, `mesg`, `flags`, `count`, `thread->priority`). Infer meaning from how the value is used, from the callees,
   and from the N64 SDK (libultra) conventions when the function is clearly an SDK routine (`osCreateMesgQueue`,
   `osSetIntMask`, `osViSetMode`, `osPiStartDma`, ...). If you are not sure, say so in the comment, do not invent.
2. **Types.** Replace `u8 pad0[4]; s32 unk4;` blobs by `typedef struct` with real field names, keeping the exact
   layout (keep padding fields only where needed to preserve offsets). Use `u32`/`s32`/`u16`... types from `types.h`.
3. **Constants.** Replace magic numbers with `#define`s when the meaning is clear (`#define OS_STATE_RUNNING 4`,
   hardware register offsets, bit masks). Hardware addresses like `0xA4040010` become named defines
   (`#define SP_STATUS_REG 0xA4040010`) only if the machine code stays identical.
4. **Comment.** One short comment above the function: what it does and, if known, its likely SDK name.
   Add a short `/* why */` comment only where a codegen trick is needed to match (padding locals, `volatile`,
   odd declaration order). Do not describe what the code already says.

## Hard rules

- Keep the first line `// FLAGS: ...` if present, and keep `#include "types.h"`.
- Do not change control flow, statement order, types of the parameters and return value, the number of
  locals that influence the stack frame, or the order locals are declared. Renaming is free; reordering is not.
- Do not rename the function itself or its callees (other files and the assembly use these names).
- Edit only the files you were given. A shared struct definition goes in the file that uses it.
- After your last edit the file MUST still say MATCH. If you cannot improve something without breaking the match,
  leave it as it was.

## Final report (short)

One line per function: `<fn> OK (MATCH kept)` or `<fn> UNCHANGED (why)`, and the names you gave to the functions you
recognised (e.g. `func_80087A44 = likely osSyncPrintf`).
