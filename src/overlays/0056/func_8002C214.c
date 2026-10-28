// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80136480(s32, s32);                    /* extern */
M2C_UNK func_8085929C(s32, s32);                    /* extern */

void func_8002C214(s32 arg0, s32 arg1, s32 arg2) {
    if (arg2 != 0) {
        func_8085929C(arg0, arg1);
    }
    func_80136480(arg0, arg1 + 0x240);
}
