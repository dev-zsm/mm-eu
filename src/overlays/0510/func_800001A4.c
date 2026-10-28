// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B61790;

void func_800001A4(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    M2C_FIELD(arg0, s32 *, 0x13C) = 0;
    M2C_FIELD(arg0, s16 *, 0x30A) = 0xA;
    M2C_FIELD(arg0, M2C_UNK **, 0x2AC) = &D_80B61790;
    M2C_FIELD(arg0, f32 *, 0xC4) = -2000.0f;
}
