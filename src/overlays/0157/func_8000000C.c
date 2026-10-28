// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BAE44(s32, u8 *, s32, M2C_UNK, f32, f32, f32, s32, s32, s32, s32); /* extern */

void func_8000000C(u8 *arg0, s32 arg1) {
    if (((s16) M2C_FIELD(arg0, s16 *, 0x1C) >> 5) & 1) {
        func_800BAE44(arg1 + 0x1CA0, arg0, arg1, 0x8E, M2C_FIELD(arg0, f32 *, 0x24), M2C_FIELD(arg0, f32 *, 0x28), M2C_FIELD(arg0, f32 *, 0x2C), (s32) M2C_FIELD(arg0, s16 *, 0x30), (s32) M2C_FIELD(arg0, s16 *, 0x32), (s32) M2C_FIELD(arg0, s16 *, 0x34), 0xFF64);
    }
}
