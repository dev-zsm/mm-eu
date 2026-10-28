// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8364(u8 *, s32, M2C_UNK, M2C_UNK); /* extern */
s32 func_80147B34(s32);                             /* extern */
s32 func_801529DC(s32);                             /* extern */

void func_80000D2C(u8 *arg0, s32 arg1) {
    if ((func_801529DC(arg1 + 0x4908) == 6) && (func_80147B34(arg1) != 0)) {
        func_800B8364(arg0, arg1, 0x43C80000, -1);
        M2C_FIELD(arg0, s16 *, 0x3B2) = 0xD;
    }
}
