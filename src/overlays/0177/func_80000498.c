// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80944BAC;

void func_80000498(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x1B6) = 0;
    M2C_FIELD(arg0, s16 *, 0x1A8) = 0x26C0;
    M2C_FIELD(arg0, s16 *, 0x1AA) = 0x1F40;
    M2C_FIELD(arg0, s16 *, 0x1AC) = 0x3FC0;
    M2C_FIELD(arg0, s16 *, 0x1AE) = 0x3FC0;
    M2C_FIELD(arg0, M2C_UNK **, 0x1A4) = &D_80944BAC;
}
