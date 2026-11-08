// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0522.h"

s8 func_800C9C4C(s32, s32, s32, s32, u8 *, M2C_UNK *, M2C_UNK *); /* extern */

void BgDblueElevator_CheckWaterBoxInfo(BgDblueElevator *this, PlayState *play2) {
    s32 pad;
    M2C_UNK sp30;
    M2C_UNK sp2C;

    M2C_FIELD(this, s8 *, 0x16B) = func_800C9C4C(play2, (u8 *)play2 + 0x830, M2C_FIELD(this, s32 *, 0x24), M2C_FIELD(this, s32 *, 0x2C), (u8 *)this + 0x16C, &sp30, &sp2C);
}
