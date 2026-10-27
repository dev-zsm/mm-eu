// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Collider_SetBaseToActor(s32, s32, s32);               /* extern */
M2C_UNK Collider_SetElement(s32, s32, s32);               /* extern */
M2C_UNK Collider_SetCylinderDim(s32, s32, s32);               /* extern */

s32 Collider_SetCylinderToActor(s32 arg0, s32 arg1, s32 arg2) {
    Collider_SetBaseToActor(arg0, arg1, arg2);
    Collider_SetElement(arg0, arg1 + 0x18, arg2 + 8);
    Collider_SetCylinderDim(arg0, arg1 + 0x40, arg2 + 0x20);
    return 1;
}
