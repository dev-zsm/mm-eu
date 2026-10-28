// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_8097F7C4;

void func_80000000(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C);
    M2C_FIELD(arg0, s8 *, 0x144) = 0;
    M2C_FIELD(arg0, s16 *, 0x146) = (s16) ((temp_v0 >> 8) & 0xFF);
    M2C_FIELD(arg0, s8 *, 0x145) = (s8) ((temp_v0 >> 7) & 1);
    M2C_FIELD(arg0, s16 *, 0x1C) = (s16) (temp_v0 & 0x7F);
    if (M2C_FIELD(arg0, s16 *, 0x146) == 3) {
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_8097F7C4;
    }
}
