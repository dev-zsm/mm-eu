// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BF550(s32, u8 *, u8 *, M2C_UNK, s32, f32, f32); /* extern */
extern f32 D_808F2500;
extern f32 D_808F2504;

void func_80000174(u8 *arg0, s32 arg1) {
    M2C_UNK var_a3;

    if (M2C_FIELD(arg0, u8 *, 0x1EC) == 0xA) {
        M2C_FIELD(arg0, u8 *, 0x1EC) = 0U;
        M2C_FIELD(arg0, f32 *, 0x1F0) = 0.0f;
        if (M2C_FIELD(arg0, s16 *, 0x1C) == 2) {
            var_a3 = 1;
        } else {
            var_a3 = 4;
        }
        func_800BF550(arg1, arg0, arg0 + 0x1FC, var_a3, 4, D_808F2500, D_808F2504);
    }
}
