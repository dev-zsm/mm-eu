// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_801529DC(s32);                             /* extern */

s32 Actor_TextboxIsClosing(void *arg0, s32 arg1) {
    if (func_801529DC(arg1 + 0x4908) == 2) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~0x100);
        return 1;
    }
    return 0;
}
