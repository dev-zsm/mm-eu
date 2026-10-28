// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80137C58(s32, M2C_UNK);                    /* extern */
M2C_UNK func_80AD0710(s32, s32);                    /* extern */

void func_80001F14(s32 arg0, s32 arg1) {
    if (func_80137C58(arg0 + 0x190, 0x40A00000) != 0) {
        func_80AD0710(arg0, arg1);
    }
}
