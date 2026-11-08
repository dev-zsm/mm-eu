// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0148.h"

extern M2C_UNK D_809140DC;

void EnHonotrap_SetupFlameChase(EnHonotrap *this) {
    s16 temp_v0;

    M2C_FIELD(this, s16 *, 0x34) = 0;
    temp_v0 = M2C_FIELD(this, s16 *, 0x34);
    M2C_FIELD(this, M2C_UNK **, 0x144) = &D_809140DC;
    M2C_FIELD(this, f32 *, 0x70) = 0.0f;
    M2C_FIELD(this, f32 *, 0x6C) = 0.0f;
    M2C_FIELD(this, f32 *, 0x68) = 0.0f;
    M2C_FIELD(this, f32 *, 0x64) = 0.0f;
    M2C_FIELD(this, s16 *, 0x220) = 0x64;
    M2C_FIELD(this, s16 *, 0x32) = temp_v0;
    M2C_FIELD(this, s16 *, 0x30) = temp_v0;
}
