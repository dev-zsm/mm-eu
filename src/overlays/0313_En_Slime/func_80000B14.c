// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0313.h"

extern M2C_UNK D_80A14610;

void EnSlime_SetupTurnToPlayer(EnSlime *this) {
    M2C_FIELD(this, s16 *, 0xBC) = 0;
    M2C_FIELD(this, s16 *, 0xC0) = 0;
    M2C_FIELD(this, s16 *, 0x14C) = 8;
    M2C_FIELD(this, M2C_UNK **, 0x144) = &D_80A14610;
    M2C_FIELD(this, f32 *, 0x70) = 0.0f;
}
