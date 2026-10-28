// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80990168();                            /* extern */
M2C_UNK func_809901B4();                            /* extern */

void func_80000578(u8 *arg0, M2C_UNK arg1) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0x190);
    if (temp_v0 != NULL) {
        if (M2C_FIELD(temp_v0, s16 *, 0x3292) != M2C_FIELD(arg0, s16 *, 0x1C)) {
            func_809901B4();
            return;
        }
        func_80990168();
    }
}
