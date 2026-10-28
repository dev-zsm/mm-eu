// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800EDCC4(s32, s32, s32);               /* extern */
s32 func_800EDFA0(s32, M2C_UNK);                    /* extern */
s32 func_800EE03C(s32, M2C_UNK);                    /* extern */

void func_800003A0(s32 arg0, s32 arg1) {
    if (func_800EE03C(arg1, 0x7E) != 0) {
        func_800EDCC4(arg0, arg1, func_800EDFA0(arg1, 0x7E));
    }
}
