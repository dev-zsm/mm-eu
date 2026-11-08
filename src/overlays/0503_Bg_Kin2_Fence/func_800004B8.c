// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0503.h"

s32 func_800FEE3C(u8 *, f32, M2C_UNK, u8 *);    /* extern */
M2C_UNK func_80B53A60(u8 *);                      /* extern */

void BgKin2Fence_RaiseFence(BgKin2Fence *this, PlayState *play) {
    if (func_800FEE3C((u8 *)this + 0x28, M2C_FIELD(this, f32 *, 0xC) + 58.0f, 0x40A00000, this) != 0) {
        func_80B53A60(this);
    }
}
