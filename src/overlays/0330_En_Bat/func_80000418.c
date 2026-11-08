// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0330.h"

extern M2C_UNK D_80A2868C;

void EnBat_SetupFlyIdle(EnBat *this) {
    M2C_FIELD(this, s16 *, 0x14C) = 0x64;
    M2C_FIELD(this, u8 *, 0x195) = (u8) (M2C_FIELD(this, u8 *, 0x195) | 1);
    M2C_FIELD(this, M2C_UNK **, 0x144) = &D_80A2868C;
    M2C_FIELD(this, f32 *, 0x70) = 3.5f;
}
