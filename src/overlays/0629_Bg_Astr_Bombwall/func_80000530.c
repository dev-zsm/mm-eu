// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0629.h"

extern M2C_UNK D_80BEF1B8;

void BgAstrBombwall_SetupExploding(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80BEF1B8;
}
