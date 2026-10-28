// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

u8 *func_801812C4();                              /* extern */

void func_80001F74(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, u8 *arg4) {
    if (arg1 == 1) {
        M2C_FIELD(arg4, f32 *, 0x2AC) = (f32) M2C_FIELD(func_801812C4(), f32 *, 0x34);
    }
}
