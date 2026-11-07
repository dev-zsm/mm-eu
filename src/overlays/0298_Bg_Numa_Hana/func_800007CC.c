// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0298.h"

extern M2C_UNK D_809FFA10;

void BgNumaHana_SetupRaiseFlower(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x234) = &D_809FFA10;
}
