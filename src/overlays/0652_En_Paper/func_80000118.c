// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0652.h"

extern M2C_UNK D_80C0429C;

void EnPaper_SetupFlyConfettiGroup(EnPaper *this) {
    M2C_FIELD(this, M2C_UNK **, 0x144) = &D_80C0429C;
}
