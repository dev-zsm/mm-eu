// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B9B978;

void func_800003B0(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80B9B978;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x6C) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x64) = 0.0f;
    M2C_FIELD(arg0, s8 *, 0x158) = 0;
    M2C_FIELD(arg0, s8 *, 0x159) = 1;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
    M2C_FIELD(arg0, s16 *, 0x1A4) = 0x1E;
    M2C_FIELD(arg0, s16 *, 0x1A6) = 0x32;
    M2C_FIELD(arg0, s16 *, 0x1A8) = -0x19;
}
