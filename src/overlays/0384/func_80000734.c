// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A91A3C;

void func_80000734(u8 *arg0, M2C_UNK arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1AC);
    if (temp_v0 < 0x3CF) {
        M2C_FIELD(arg0, s32 *, 0x1AC) = (s32) (temp_v0 + 0x19);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x1AC) = 0x3E4;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80A91A3C;
}
