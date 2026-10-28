// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_809735E8();                            /* extern */
M2C_UNK func_80973640();                            /* extern */

void func_80000404(u8 *arg0) {
    if (!(((s16) M2C_FIELD(arg0, s16 *, 0x1C) >> 0xF) & 1)) {
        func_809735E8();
        return;
    }
    func_80973640();
}
