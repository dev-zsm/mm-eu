// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8090C204();                            /* extern */
M2C_UNK func_8090C25C();                            /* extern */

void func_80000258(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x18);
    if (temp_v0 == 1) {
        func_8090C204();
        return;
    }
    if (temp_v0 == 2) {
        func_8090C25C();
    }
}
