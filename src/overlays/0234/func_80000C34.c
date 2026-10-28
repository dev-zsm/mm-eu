// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_809725B0();                            /* extern */
M2C_UNK func_80972608();                            /* extern */
M2C_UNK func_809726DC();                            /* extern */

void func_80000C34(u8 *arg0) {
    s16 temp_v0;
    s32 temp_v1;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C);
    temp_v1 = ((temp_v0 >> 0xE) & 2) | ((temp_v0 >> 7) & 1);
    if (temp_v1 == 0) {
        func_809725B0();
        return;
    }
    if (temp_v1 == 1) {
        func_80972608();
        return;
    }
    func_809726DC();
}
