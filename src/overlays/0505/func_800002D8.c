// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B54860();                            /* extern */
M2C_UNK func_80B549D4();                            /* extern */

void func_800002D8(u8 *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x164) & 0xA) {
        func_80B54860();
        return;
    }
    func_80B549D4();
}
