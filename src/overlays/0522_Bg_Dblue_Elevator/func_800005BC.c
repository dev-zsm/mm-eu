// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0522.h"

extern M2C_UNK D_80B77218;

void BgDblueElevator_SetupWaitActivation(BgDblueElevator *this) {
    M2C_FIELD(this, s8 *, 0x169) = 0x3C;
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80B77218;
}
