// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(s32, M2C_UNK);                /* extern */
M2C_UNK func_809590B4(s32, M2C_UNK);                /* extern */

void func_800005D8(s32 arg0) {
    func_800B8C4C(arg0, 0x3869);
    func_809590B4(arg0, 1);
}
