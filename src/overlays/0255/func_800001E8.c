// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80988F00();                            /* extern */
M2C_UNK func_80988FE0();                            /* extern */

void func_800001E8(u8 *arg0) {
    if (!(((s16) M2C_FIELD(arg0, s16 *, 0x1C) >> 0xE) & 1)) {
        func_80988F00();
        return;
    }
    func_80988FE0();
}
