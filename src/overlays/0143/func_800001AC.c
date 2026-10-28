// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

u32 func_80087010();                                /* extern */
u8 *func_800BA9E4(s32, s32, M2C_UNK, s32, f32, f32, s32, u32, s32, s32); /* extern */
s32 func_8090C0B0(u8 *, s32);                     /* extern */

void func_800001AC(u8 *arg0, s32 arg1, M2C_UNK arg2) {
    s32 pad;
    s32 sp38;
    u8 *temp_v0;

    if (func_8090C0B0(arg0, arg1) != 0) {
        sp38 = ((M2C_FIELD(arg0, s16 *, 0x1C) & 0x1F) * 4) | 0xFF01;
        temp_v0 = func_800BA9E4(arg1 + 0x1CA0, arg1, 0x50, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, f32 *, 0x28), M2C_FIELD(arg0, f32 *, 0x2C), 0, func_80087010() >> 0x10, 0, sp38);
        if (temp_v0 != NULL) {
            M2C_FIELD(temp_v0, u8 **, 0x120) = arg0;
            M2C_FIELD(temp_v0, f32 *, 0x68) = 0.0f;
            M2C_FIELD(temp_v0, f32 *, 0x70) = 0.0f;
        }
    }
}
