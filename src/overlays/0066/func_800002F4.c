// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BF550(s32, u8 *, u8 *, M2C_UNK, s32, f32, f32); /* extern */
extern f32 D_80875B1C;
extern f32 D_80875B20;

void func_800002F4(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, u8 *, 0x18C) == 0xA) {
        M2C_FIELD(arg0, u8 *, 0x18C) = 0U;
        M2C_FIELD(arg0, s8 *, 0x36C) = 0;
        M2C_FIELD(arg0, f32 *, 0x2C8) = 0.0f;
        func_800BF550(arg1, arg0, arg0 + 0x2D4, 0xB, 2, D_80875B1C, D_80875B20);
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x400);
    }
}
