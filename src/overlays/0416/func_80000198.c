// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80AB3238();                            /* extern */

void func_80000198(u8 *arg0, M2C_UNK arg1) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0x120);
    if ((M2C_FIELD(temp_v0, s16 *, 0x54A) == 0) && (M2C_FIELD(temp_v0, s16 *, 0x542) == 0)) {
        func_80AB3238();
    }
}
