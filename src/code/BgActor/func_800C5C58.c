// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK ScaleRotPos_IsEqual(s32, s32, s32);               /* extern */

s32 BgActor_IsTransformUnchanged(struct BgActor *bgActor) {
    ScaleRotPos_IsEqual((u8 *)bgActor + 0x14, (u8 *)bgActor + 0x34, bgActor);
}
