// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Collider_ResetATBase(s32, s32);                    /* extern */
M2C_UNK Collider_ResetATElement(s32, s32);                    /* extern */

s32 func_800E1180(s32 arg0, s32 arg1) {
    Collider_ResetATBase(arg0, arg1);
    Collider_ResetATElement(arg0, arg1 + 0x18);
    return 1;
}
