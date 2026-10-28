// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80AE4430();                            /* extern */
M2C_UNK func_80AE45B0();                            /* extern */

void func_80000E00(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    if (M2C_FIELD(arg0, u8 *, 0x11C) == 0) {
        if (M2C_FIELD(arg0, u8 *, 0xB7) == 0) {
            func_80AE45B0();
        } else {
            func_80AE4430();
        }
    }
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x3EA);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s16 *, 0x3EA) = (s16) (temp_v0 - 1);
    }
}
