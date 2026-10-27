// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Collider_InitBase(s32, s32);                    /* extern */
M2C_UNK Collider_InitElement(s32, s32);                    /* extern */
M2C_UNK Collider_InitCylinderDim(s32, s32);                    /* extern */

s32 Collider_InitCylinder(s32 arg0, s32 arg1) {
    Collider_InitBase(arg0, arg1);
    Collider_InitElement(arg0, arg1 + 0x18);
    Collider_InitCylinderDim(arg0, arg1 + 0x40);
    return 1;
}
