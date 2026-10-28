// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BF550(s32, u8 *, u8 *, M2C_UNK, s32, f32, f32); /* extern */
extern f32 D_808700A8;
extern f32 D_808700AC;

void func_800002D0(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, u8 *, 0x18C) == 0xA) {
        M2C_FIELD(arg0, u8 *, 0x18C) = 0U;
        M2C_FIELD(arg0, f32 *, 0x254) = 0.0f;
        func_800BF550(arg1, arg0, arg0 + 0x270, 0xA, 2, D_808700A8, D_808700AC);
        M2C_FIELD(arg0, s8 *, 0x2FC) = 0;
    }
}
