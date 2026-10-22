// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Collider_InitCylinder(s32, s32);                    /* extern */
M2C_UNK Collider_SetCylinder(s32, s32, s32, s32);          /* extern */

s32 Collider_InitAndSetCylinder(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Collider_InitCylinder(arg0, arg1);
    Collider_SetCylinder(arg0, arg1, arg2, arg3);
    return 1;
}
