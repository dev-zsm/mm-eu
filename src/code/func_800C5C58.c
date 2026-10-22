// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK ScaleRotPos_IsEqual(s32, s32, s32);               /* extern */

void BgActor_IsTransformUnchanged(s32 arg0) {
    ScaleRotPos_IsEqual(arg0 + 0x14, arg0 + 0x34, arg0);
}
