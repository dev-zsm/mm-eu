// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80944D50;

void func_80000634(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x1B6) = 2;
    M2C_FIELD(arg0, s16 *, 0x1A8) = 0x3FC0;
    M2C_FIELD(arg0, s16 *, 0x1AA) = 0x3FC0;
    M2C_FIELD(arg0, s16 *, 0x1AC) = 0x3FC0;
    M2C_FIELD(arg0, s16 *, 0x1AE) = 0x3FC0;
    M2C_FIELD(arg0, s16 *, 0x1B2) = -0xAA;
    M2C_FIELD(arg0, s8 *, 0x1B4) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x1A4) = &D_80944D50;
}
