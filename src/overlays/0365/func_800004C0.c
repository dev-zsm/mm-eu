// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80147B34(s32);                             /* extern */
M2C_UNK func_80147CC4(s32);                         /* extern */
s32 func_801529DC(s32);                             /* extern */

s32 func_800004C0(s32 arg0) {
    if ((func_801529DC(arg0 + 0x4908) == 5) && (func_80147B34(arg0) != 0)) {
        func_80147CC4(arg0);
        return 1;
    }
    return 0;
}
