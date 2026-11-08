// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0574.h"

M2C_UNK func_800E2318(s32, s32, s32, s32);          /* extern */

void BgIkanaRay_UpdateActivated(BgIkanaRay *this, PlayState *play) {
    func_800E2318(play, (u8 *)play + 0x18884, (u8 *)this + 0x144, play);
}
