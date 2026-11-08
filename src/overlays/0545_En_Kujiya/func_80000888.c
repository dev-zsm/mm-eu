// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0545.h"

extern M2C_UNK D_80B95F20;

void EnKujiya_SetupTurnToOpen(EnKujiya *this) {
    M2C_FIELD(this, s16 *, 0x148) = 0;
    M2C_FIELD(this, M2C_UNK **, 0x144) = &D_80B95F20;
}
