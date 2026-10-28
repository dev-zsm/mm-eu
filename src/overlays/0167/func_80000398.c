// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BA9E4(s32, s32, M2C_UNK, M2C_UNK, f32, f32, s32, s32, s32, s32); /* extern */

void func_80000398(s32 arg0) {
    func_800BA9E4(arg0 + 0x1CA0, arg0, 0x199, 0x42E60000, 32.0f, -121.0f, 0, 0, 0, 3);
}
