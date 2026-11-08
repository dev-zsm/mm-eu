// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0502.h"

extern M2C_UNK D_80B53344;

void BgKin2Bombwall_SetupEndCutscene(BgKin2Bombwall *this) {
    M2C_FIELD(this, s8 *, 0x1AC) = 0x28;
    M2C_FIELD(this, M2C_UNK **, 0x1A8) = &D_80B53344;
}
