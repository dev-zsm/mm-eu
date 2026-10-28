// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80BE984C(u8 *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK D_80BE9B2C;

void func_800003D0(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x2C2);
    if ((temp_v0 == 0) || (temp_v0 == 1)) {
        func_80BE984C(arg0, 5, 0x3F800000);
    } else {
        func_80BE984C(arg0, 1, 0x3F800000);
    }
    M2C_FIELD(arg0, s32 *, 0x2A8) = 0;
    if (M2C_FIELD(arg0, u8 *, 0x2AC) != 0) {
        func_80BE984C(arg0, 6, 0x3F800000);
    }
    M2C_FIELD(arg0, s16 *, 0x2C0) = 1;
    M2C_FIELD(arg0, M2C_UNK **, 0x284) = &D_80BE9B2C;
}
