// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B80A04();                            /* extern */
M2C_UNK func_80B80A5C();                            /* extern */

void func_800006A4(u8 *arg0) {
    if (!(((s16) M2C_FIELD(arg0, s16 *, 0x1C) >> 0xF) & 1)) {
        func_80B80A04();
        return;
    }
    func_80B80A5C();
}
