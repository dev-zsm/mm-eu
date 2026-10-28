// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BF550(s32, u8 *, u8 *, M2C_UNK, s32, f32, f32); /* extern */
extern f32 D_8086D164;
extern f32 D_8086D168;

void func_800002D8(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s16 *, 0x2BC) = 0;
    if (M2C_FIELD(arg0, u8 *, 0x2AC) == 0xA) {
        M2C_FIELD(arg0, u8 *, 0x2AC) = 0U;
        M2C_FIELD(arg0, s8 *, 0x398) = 6;
        M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x3A0), s8 *, 0x14) = 1;
        M2C_FIELD(arg0, f32 *, 0x2C4) = 0.0f;
        func_800BF550(arg1, arg0, arg0 + 0x2F4, 0xC, 2, D_8086D164, D_8086D168);
    }
}
