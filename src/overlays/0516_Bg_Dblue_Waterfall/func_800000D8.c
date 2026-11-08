// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0516.h"

s32 func_800B5B20(M2C_UNK, s32, u8 *, M2C_UNK);   /* extern */

s32 func_800000D8(BgDblueWaterfall *this, PlayState *play) {
    if (func_800B5B20(play, M2C_FIELD(this, s16 *, 0x1C) & 0x7F, this, play) != 0) {
        return 0;
    }
    return 1;
}
