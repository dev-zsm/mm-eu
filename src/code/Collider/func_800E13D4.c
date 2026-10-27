// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Collider_SetElement(s32, s32, s32);               /* extern */
M2C_UNK Collider_SetTrisElementDim(s32, s32, s32);               /* extern */

s32 func_800E13D4(s32 arg0, s32 arg1, s32 arg2) {
    Collider_SetElement(arg0, arg1, arg2);
    Collider_SetTrisElementDim(arg0, arg1 + 0x28, arg2 + 0x18);
    return 1;
}
