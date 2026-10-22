// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Collider_DestroyCylinder(M2C_UNK, s32, s32, M2C_UNK);  /* extern */

void EnItem00_Destroy(s32 arg0, M2C_UNK arg1) {
    Collider_DestroyCylinder(arg1, arg0 + 0x158, arg0, arg1);
}
