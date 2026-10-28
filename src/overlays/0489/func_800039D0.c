// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B2C114;

void func_800039D0(u8 *arg0) {
    M2C_FIELD(arg0, u8 *, 0x2B0) = (u8) (M2C_FIELD(arg0, u8 *, 0x2B0) & ~1);
    M2C_FIELD(arg0, u8 *, 0x2B1) = (u8) (M2C_FIELD(arg0, u8 *, 0x2B1) & ~1);
    M2C_FIELD(arg0, u8 *, 0x2B2) = (u8) (M2C_FIELD(arg0, u8 *, 0x2B2) & ~1);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & 0x7FFFFFFF);
    M2C_FIELD(arg0, s8 *, 0x389) = 0;
    M2C_FIELD(arg0, s32 *, 0x13C) = 0;
    M2C_FIELD(arg0, s8 *, 0x38B) = 0;
    M2C_FIELD(arg0, s8 *, 0x38C) = 0;
    M2C_FIELD(arg0, s8 *, 0x38D) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x2EC) = &D_80B2C114;
}
