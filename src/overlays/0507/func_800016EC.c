// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
M2C_UNK func_800B372C(u8 *, s32, s32, s32, s32);  /* extern */

void func_800016EC(s32 arg0, u8 *arg1) {
    s16 temp_v0;

    temp_v0 = (s16) (s32) ((func_8008704C() * 20.0f) + 30.0f);
    if (!(M2C_FIELD(arg1, s32 *, 0x9C) & 7)) {
        func_800B372C(arg1, arg0 + 0x3A4, arg0 + 0x3B0, arg0 + 0x3BC, (s32) temp_v0);
    }
}
