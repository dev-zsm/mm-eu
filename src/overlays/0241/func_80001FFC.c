// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490();                            /* extern */

void func_80001FFC(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1D4);
    M2C_FIELD(arg0, s16 *, 0x1D4) = (s16) (temp_v0 - 1);
    if (temp_v0 <= 0) {
        func_800B6490();
    }
}
