// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80136480(s32, s32);                        /* extern */
M2C_UNK func_8082E1C8(s32, u8 *, s32);            /* extern */

void func_8002B770(s32 arg0, u8 *arg1, s32 arg2) {
    if (func_80136480(arg0, arg1 + 0x240) != 0) {
        func_8082E1C8(arg0, arg1, arg2);
        M2C_FIELD(arg1, s16 *, 0xAE8) = 1;
    }
}
