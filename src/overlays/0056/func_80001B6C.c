// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80001B6C(u8 *arg0, u8 *arg1) {
    M2C_FIELD(arg0, u8 **, 0x34C) = arg1;
    M2C_FIELD(arg0, u8 **, 0x388) = arg1;
    M2C_FIELD(arg0, s16 *, 0x384) = 0;
    M2C_FIELD(arg0, s16 *, 0x35E) = (s16) (M2C_FIELD(arg1, s16 *, 0xBE) - M2C_FIELD(arg0, s16 *, 0xBE));
    M2C_FIELD(arg0, s32 *, 0xA6C) = (s32) (M2C_FIELD(arg0, s32 *, 0xA6C) | 0x800);
}
