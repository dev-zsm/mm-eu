// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0630.h"

M2C_UNK func_800C604C(s32, s32, s32, s32);          /* extern */

void func_800000F8(BgIkninSusceil *this, PlayState *play) {
    func_800C604C(play, (u8 *)play + 0x880, M2C_FIELD(this, s32 *, 0x144), play);
}
