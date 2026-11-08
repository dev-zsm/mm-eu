// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0327.h"

void EnTest2_UpdateForLens(Actor *thisx, PlayState *play) {
    if (M2C_FIELD(play, s8 *, 0x1CA4) == 0x64) {
        M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) | 0x80);
        return;
    }
    M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) & ~0x80);
}
