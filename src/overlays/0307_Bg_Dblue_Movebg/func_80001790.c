// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0307.h"

s32 func_8013E684(u8 *, s16, M2C_UNK, M2C_UNK);   /* extern */

void BgDblueMovebg_Update(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK (**)(), 0x15C)();
    if ((M2C_FIELD(thisx, u16 *, 0x172) & 8) && (func_8013E684(thisx, M2C_FIELD(thisx, s16 *, 0x1D2), -1, 0) != 0)) {
        M2C_FIELD(thisx, u16 *, 0x172) = (u16) (M2C_FIELD(thisx, u16 *, 0x172) & 0xFFF7);
    }
}
