// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80968C5C();                            /* extern */
M2C_UNK func_80968DE8();                            /* extern */
M2C_UNK func_80969E94();                            /* extern */

void func_800005C4(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C);
    if (temp_v0 == 2) {
        func_80968DE8();
        return;
    }
    if (temp_v0 == 1) {
        func_80968C5C();
        return;
    }
    if (temp_v0 == 9) {
        func_80969E94();
    }
}
