// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Math_Vec3f_Copy(s32, s32);                    /* extern */

s32 Collider_SetLinePoints(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Math_Vec3f_Copy(arg1, arg2);
    Math_Vec3f_Copy(arg1 + 0xC, arg3);
    return 1;
}
