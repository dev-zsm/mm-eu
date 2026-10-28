// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_801529DC(s32);                             /* extern */

s32 func_8000041C(s32 arg0, s32 arg1) {
    if (func_801529DC(arg1 + 0x4908) == 2) {
        return 1;
    }
    return 0;
}
