// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B6B894;

void func_800015C8(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x2D8) = 0;
    M2C_FIELD(arg0, s16 *, 0x2B0) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x2AC) = &D_80B6B894;
}
