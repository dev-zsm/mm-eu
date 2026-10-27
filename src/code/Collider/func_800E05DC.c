// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Collider_DestroyElementDamageInfoAT(s32, s32);                    /* extern */
M2C_UNK Collider_DestroyElementDamageInfoAC(s32, s32);                    /* extern */

s32 Collider_DestroyElement(s32 arg0, s32 arg1) {
    Collider_DestroyElementDamageInfoAT(arg0, arg1);
    Collider_DestroyElementDamageInfoAC(arg0, arg1 + 8);
    return 1;
}
