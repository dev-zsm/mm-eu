// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Collider_InitJntSph(s32, s32);                    /* extern */
M2C_UNK Collider_SetJntSph(s32, s32, s32, s32, s32);     /* extern */

s32 Collider_InitAndSetJntSph(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Collider_InitJntSph(arg0, arg1);
    Collider_SetJntSph(arg0, arg1, arg2, arg3, arg4);
    return 0;
}
