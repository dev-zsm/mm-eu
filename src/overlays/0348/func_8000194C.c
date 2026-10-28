// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490();                            /* extern */
M2C_UNK func_80A3BEE0();                            /* extern */

void func_8000194C(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x1C) == 1) {
        func_80A3BEE0();
        return;
    }
    func_800B6490();
}
