// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013F090(f32, u8, u8, u8);             /* extern */

void func_800004B8(u8 *arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4, s32 arg5) {
    if (arg1 == M2C_FIELD(arg0, s32 *, 0x1CCC)) {
        func_8013F090((f32) arg5, arg2, arg3, arg4);
    }
}
