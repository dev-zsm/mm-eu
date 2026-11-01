// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Collider_DestroyCylinder(s32, s32);                    /* extern */
M2C_UNK FireObj_DestroyLight(s32, s32);                    /* extern */

void FireObj_Destroy(s32 arg0, s32 arg1) {
    Collider_DestroyCylinder(arg0, arg1 + 0x2C);
    FireObj_DestroyLight(arg0, arg1 + 0x78);
}
