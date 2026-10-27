// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Collider_DestroyElement(s32, s32);                    /* extern */
M2C_UNK Collider_DestroyJntSphElementDim(s32, s32);                    /* extern */

s32 Collider_DestroyJntSphElement(s32 arg0, s32 arg1) {
    Collider_DestroyElement(arg0, arg1);
    Collider_DestroyJntSphElementDim(arg0, arg1 + 0x28);
    return 1;
}
