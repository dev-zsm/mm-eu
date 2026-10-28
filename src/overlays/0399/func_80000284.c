// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80AA6E48;

void func_80000284(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;
    s16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1A6);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s16 *, 0x1A6) = (s16) (temp_v0 - 1);
        return;
    }
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x1A4);
    if (temp_v0_2 >= -0x3FFF) {
        M2C_FIELD(arg0, s16 *, 0x1A4) = (s16) (temp_v0_2 - 0x800);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x1A4) = -0x4000;
    M2C_FIELD(arg0, M2C_UNK **, 0x1F8) = &D_80AA6E48;
}
