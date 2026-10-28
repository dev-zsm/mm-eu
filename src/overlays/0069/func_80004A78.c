// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80004A78(u8 *arg0) {
    M2C_FIELD(arg0, u8 *, 0x28A) = (u8) (M2C_FIELD(arg0, u8 *, 0x28A) & ~1);
    M2C_FIELD(arg0, u8 *, 0x2D6) = (u8) (M2C_FIELD(arg0, u8 *, 0x2D6) & ~1);
    M2C_FIELD(arg0, u8 *, 0x322) = (u8) (M2C_FIELD(arg0, u8 *, 0x322) & ~1);
    M2C_FIELD(arg0, s32 *, 0x144) = 1;
    M2C_FIELD(arg0, s32 *, 0x20C) = 4;
    M2C_FIELD(arg0, s32 *, 0x1E8) = (s32) (M2C_FIELD(arg0, s32 *, 0x1E8) | 0x2000);
    M2C_FIELD(arg0, s16 *, 0x250) = 0;
}
