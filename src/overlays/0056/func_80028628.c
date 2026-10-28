// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B273C(s32, s32, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_8083EF9C(s32, s32, M2C_UNK, M2C_UNK, f32, s32, s32, s32); /* extern */

void func_80028628(s32 arg0, s32 arg1) {
    if (func_8083EF9C(arg0, arg1, 0x41400000, 4, 0.0f, 0xA, 0x32, 1) != 0) {
        func_800B273C(arg0, arg1 + 0x24, 0x40400000, 0, 4, 8, 2, -1, 0xA, 0);
    }
}
