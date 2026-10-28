// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_80137C58(s32, M2C_UNK);                    /* extern */
M2C_UNK func_809759AC(u8 *, s32, M2C_UNK);        /* extern */

void func_80000B3C(u8 *arg0, s32 arg1) {
    if ((func_80137C58(arg0 + 0x144, 0x3F800000) != 0) && (M2C_FIELD(arg0, u16 *, 0x90) & 1)) {
        func_809759AC(arg0, arg1, 2);
        func_800B8C4C(arg0, 0x385A);
    }
}
