// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B8B1E0();                            /* extern */
M2C_UNK func_80B8B404();                            /* extern */

void func_80001204(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    if (M2C_FIELD(arg0, u8 *, 0x11C) == 0) {
        if (M2C_FIELD(arg0, u8 *, 0xB7) == 0) {
            func_80B8B404();
        } else {
            func_80B8B1E0();
        }
    }
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x3F2);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s16 *, 0x3F2) = (s16) (temp_v0 - 1);
    }
}
