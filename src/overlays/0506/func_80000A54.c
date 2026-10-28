// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B55CD0();                            /* extern */

void func_80000A54(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x3F2);
    if (temp_v0 >= 6) {
        func_80B55CD0();
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x3F2) = (s16) (temp_v0 + 1);
}
