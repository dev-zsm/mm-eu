// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BF550(s32, u8 *, u8 *, M2C_UNK, s32, f32, f32); /* extern */
extern f32 D_808C2F0C;
extern f32 D_808C2F10;

void func_80000234(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, u8 *, 0x24D) == 0xA) {
        M2C_FIELD(arg0, u8 *, 0x24D) = 0U;
        M2C_FIELD(arg0, f32 *, 0x26C) = 0.0f;
        func_800BF550(arg1, arg0, arg0 + 0x278, 5, 2, D_808C2F0C, D_808C2F10);
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x200);
    }
}
