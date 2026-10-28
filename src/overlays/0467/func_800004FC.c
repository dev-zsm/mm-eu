// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B06D70;

void func_800004FC(u8 *arg0) {
    M2C_FIELD(arg0, u16 *, 0x90) = (u16) (M2C_FIELD(arg0, u16 *, 0x90) & 0xFFFE);
    M2C_FIELD(arg0, u8 *, 0x15C) = (u8) (M2C_FIELD(arg0, u8 *, 0x15C) & ~2);
    M2C_FIELD(arg0, u8 *, 0x15E) = (u8) (M2C_FIELD(arg0, u8 *, 0x15E) & ~2);
    M2C_FIELD(arg0, s32 *, 0x13C) = 0;
    M2C_FIELD(arg0, s16 *, 0x1C) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80B06D70;
}
