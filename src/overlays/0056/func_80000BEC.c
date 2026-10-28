// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80136480(s32, s32);                        /* extern */
M2C_UNK func_8082D1EC(s32, s32, s32);               /* extern */

s32 func_80000BEC(s32 arg0, s32 arg1, s32 arg2) {
    if (func_80136480(arg0, arg1 + 0x240) != 0) {
        func_8082D1EC(arg0, arg1, arg2);
        return 1;
    }
    return 0;
}
