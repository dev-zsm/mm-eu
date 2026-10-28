// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B5D948(s32, s32);                    /* extern */
M2C_UNK func_80B5DA38(s32, s32);                    /* extern */

s32 func_80001680(s32 arg0, s32 arg1) {
    func_80B5D948(arg0, arg1);
    func_80B5DA38(arg0, arg1);
    return 0;
}
