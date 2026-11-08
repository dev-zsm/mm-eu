// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0629.h"

extern M2C_UNK D_80BEF1B8;

void BgAstrBombwall_SetupExploding(BgAstrBombwall *this, PlayState *play) {
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80BEF1B8;
}
