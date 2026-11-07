// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0503.h"

extern M2C_UNK D_80B53A88;

void BgKin2Fence_SetupDoNothing(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x27C) = &D_80B53A88;
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0xC) + 58.0f);
}
