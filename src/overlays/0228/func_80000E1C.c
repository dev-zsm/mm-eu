// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80969488;

void func_80000E1C(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x14A) = 0x14;
    M2C_FIELD(arg0, u8 *, 0x170) = (u8) (M2C_FIELD(arg0, u8 *, 0x170) | 1);
    M2C_FIELD(arg0, u8 *, 0x171) = (u8) (M2C_FIELD(arg0, u8 *, 0x171) | 1);
    M2C_FIELD(arg0, s16 *, 0x1C) = 3;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80969488;
}
