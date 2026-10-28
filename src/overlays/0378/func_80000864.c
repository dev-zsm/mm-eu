// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(s32, M2C_UNK);                /* extern */

void func_80000864(s32 arg0, u8 *arg1) {
    if (M2C_FIELD(arg1, u16 *, 0x1F34) == 3) {
        func_800B8C4C(arg0, 0x3A7A);
        func_800B8C4C(arg0, 0x3A84);
    }
}
