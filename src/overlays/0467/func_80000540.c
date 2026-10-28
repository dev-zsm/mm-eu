// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B06DD8();                            /* extern */
M2C_UNK func_80B06FDC();                            /* extern */
M2C_UNK func_80B073DC();                            /* extern */

void func_80000540(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C);
    if (temp_v0 == 1) {
        func_80B06DD8();
        return;
    }
    if (temp_v0 == 2) {
        func_80B06FDC();
        return;
    }
    if (temp_v0 == 4) {
        func_80B073DC();
    }
}
