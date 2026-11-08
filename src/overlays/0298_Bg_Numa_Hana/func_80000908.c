// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0298.h"

extern M2C_UNK D_809FFB4C;

void BgNumaHana_SetupOpenedIdle(BgNumaHana *this) {
    M2C_FIELD(this, M2C_UNK **, 0x234) = &D_809FFB4C;
}
