// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A98538;

void func_800010F0(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x154);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s16 *, 0x154) = (s16) (temp_v0 - 1);
        return;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x174) = &D_80A98538;
    M2C_FIELD(arg0, s16 *, 0x154) = 0;
}
