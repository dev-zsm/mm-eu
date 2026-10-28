// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80182B28(M2C_UNK *, s32, s32);         /* extern */
extern M2C_UNK D_801C9EE0;
extern M2C_UNK D_80BE1B00;

void func_80001650(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    if (arg1 == 0xB) {
        func_80182B28(&D_80BE1B00, arg4 + 0x3C, arg1);
    }
    if (arg1 == 3) {
        func_80182B28(&D_801C9EE0, arg4 + 0x414, arg1);
    }
}
