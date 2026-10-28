// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80134AE8(s32);                             /* extern */
M2C_UNK func_801367B4(s32, s32, s32, M2C_UNK, f32, f32, s32, f32); /* extern */

void func_80000A14(s32 arg0, s32 arg1, s32 arg2) {
    func_801367B4(arg0, arg1 + 0x240, arg2, 0x3F2AAAAB, 0.0f, (f32) func_80134AE8(arg2), 2, -6.0f);
}
