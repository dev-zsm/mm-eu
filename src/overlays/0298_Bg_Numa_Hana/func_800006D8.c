// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0298.h"

extern M2C_UNK D_809FF920;

void BgNumaHana_SetupUnfoldOuterPetals(BgNumaHana *this) {
    M2C_FIELD(this, M2C_UNK **, 0x234) = &D_809FF920;
    M2C_FIELD(this, s16 *, 0x33E) = 0;
}
