// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BF550(s32, u8 *, u8 *, M2C_UNK, s32, f32, f32); /* extern */
extern f32 D_80ABDBFC;
extern f32 D_80ABDC00;

void func_80000248(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, u8 *, 0x29D) == 0xA) {
        M2C_FIELD(arg0, u8 *, 0x29D) = 0U;
        M2C_FIELD(arg0, s8 *, 0x354) = 6;
        M2C_FIELD(arg0, f32 *, 0x2B0) = 0.0f;
        func_800BF550(arg1, arg0, arg0 + 0x2C8, 0xA, 2, D_80ABDBFC, D_80ABDC00);
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x400);
    }
}
