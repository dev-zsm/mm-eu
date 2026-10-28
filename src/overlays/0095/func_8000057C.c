// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6564(s32, M2C_UNK);                /* extern */
M2C_UNK func_800B8D94(s32, M2C_UNK);                /* extern */

void func_8000057C(s32 arg0, M2C_UNK arg1) {
    func_800B6564(arg0, 0x40600000);
    func_800B8D94(arg0, 0x217D);
}
