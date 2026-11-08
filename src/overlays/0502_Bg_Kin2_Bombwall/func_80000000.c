// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0502.h"

f32 func_8017B9A8(u8 *, s32, u8 *);             /* extern */

s32 BgKin2Bombwall_IsHitFromNearby(BgKin2Bombwall *this, PlayState *play) {
    s32 temp_v0;

    if (M2C_FIELD(this, u8 *, 0x16D) & 2) {
        temp_v0 = M2C_FIELD(this, s32 *, 0x164);
        if ((temp_v0 != 0) && (func_8017B9A8((u8 *)this + 0x24, temp_v0 + 0x24, this) < 6400.0f)) {
            return 1;
        }
    }
    return 0;
}
