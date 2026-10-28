// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80AE1904;
extern M2C_UNK D_80AE1BC4;

void func_80000234(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x14);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80AE1BC4;
        M2C_FIELD(arg0, s16 *, 0x14) = (s16) (temp_v0 - 1);
        return;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = NULL;
    M2C_FIELD(arg0, s16 *, 0x14) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x150) = &D_80AE1904;
}
