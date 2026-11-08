// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0545.h"

extern M2C_UNK func_80B95CD8;

void EnKujiya_SetupGivePrize(EnKujiya *this) {
    M2C_FIELD(this, M2C_UNK **, 0x144) = &func_80B95CD8;
}
