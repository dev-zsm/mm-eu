// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80147B34(s32);                             /* extern */
s32 func_801529DC(s32);                             /* extern */
M2C_UNK func_809F1DE8(s32, s32);                    /* extern */

void func_80000BB4(s32 arg0, s32 arg1) {
    if ((func_801529DC(arg1 + 0x4908) == 6) && (func_80147B34(arg1) != 0)) {
        func_809F1DE8(arg1, arg0);
    }
}
