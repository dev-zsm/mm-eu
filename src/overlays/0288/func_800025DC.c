// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFC68(s32, M2C_UNK, M2C_UNK, u8 *); /* extern */
M2C_UNK func_809D4EFC(u8 *, s32);                 /* extern */

void func_800025DC(u8 *arg0, s32 arg1) {
    func_800FFC68(arg0 + 0x70, 0x3F800000, 0x40200000, arg0);
    if (M2C_FIELD(arg0, s16 *, 0x162) == 0) {
        func_809D4EFC(arg0, arg1);
    }
}
