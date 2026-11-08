// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s32 func_801529DC(s32);                             /* extern */

s32 Actor_TextboxIsClosing(struct Actor *actor, struct PlayState *play) {
    if (func_801529DC((u8 *)play + 0x4908) == 2) {
        M2C_FIELD(actor, s32 *, 4) = (s32) (M2C_FIELD(actor, s32 *, 4) & ~0x100);
        return 1;
    }
    return 0;
}
