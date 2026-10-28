// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_808ACFD8;

void func_80000F68(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x30) = -0x4000;
    M2C_FIELD(arg0, u8 *, 0x21C) = (u8) (M2C_FIELD(arg0, u8 *, 0x21C) | 1);
    M2C_FIELD(arg0, s16 *, 0x1DC) = 4;
    M2C_FIELD(arg0, M2C_UNK **, 0x1D0) = &D_808ACFD8;
}
