// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0522.h"

extern M2C_UNK D_80B77380;

void BgDblueElevator_SetupMove(BgDblueElevator *this) {
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80B77380;
    M2C_FIELD(this, f32 *, 0x160) = 0.0f;
}
