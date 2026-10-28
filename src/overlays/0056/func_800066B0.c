// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801367B4(s32, u8 *, s32, M2C_UNK, f32, f32, s32, f32); /* extern */
s32 func_8082D140(s32);                             /* extern */
M2C_UNK func_808337B4(s32, u8 *);                 /* extern */

void func_800066B0(s32 arg0, u8 *arg1, s32 arg2) {
    if (!(M2C_FIELD(arg1, s32 *, 0xA6C) & 0x80)) {
        func_808337B4(arg0, arg1);
        if (func_8082D140(arg0) != 0) {
            M2C_FIELD(arg1, s16 *, 0xAE8) = -0x1E;
        }
        M2C_FIELD(arg1, s32 *, 0xA6C) = (s32) (M2C_FIELD(arg1, s32 *, 0xA6C) | 0x80);
        func_801367B4(arg0, arg1 + 0x240, arg2, 0x3F800000, 0.0f, 84.0f, 2, -6.0f);
        M2C_FIELD(arg1, s8 *, 0xAE7) = 1;
        M2C_FIELD(arg1, f32 *, 0xAD0) = 0.0f;
    }
}
