// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0276.h"

extern M2C_UNK D_809AEAF4;

void BgIcicle_Wait(BgIcicle *this, PlayState *play) {
    if (M2C_FIELD(this, f32 *, 0x98) < 60.0f) {
        M2C_FIELD(this, s16 *, 0x162) = 0xA;
        M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_809AEAF4;
    }
}
