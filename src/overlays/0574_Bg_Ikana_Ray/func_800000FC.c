// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0574.h"

s32 func_800B5B20(M2C_UNK, s32, M2C_UNK);           /* extern */
M2C_UNK func_80BBA2A0(u8 *);                      /* extern */

void BgIkanaRay_UpdateCheckForActivation(BgIkanaRay *this, PlayState *play) {
    if (func_800B5B20(play, M2C_FIELD(this, s16 *, 0x1C) & 0x7F, play) != 0) {
        func_80BBA2A0(this);
    }
}
