// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490();                            /* extern */

void func_800000FC(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;
    s16 var_v1;

    if (M2C_FIELD(arg0, s16 *, 0x1A2) != 0) {
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x1A0);
        if (temp_v0 == 0) {
            var_v1 = 0;
        } else {
            M2C_FIELD(arg0, s16 *, 0x1A0) = (s16) (temp_v0 - 1);
            var_v1 = M2C_FIELD(arg0, s16 *, 0x1A0);
        }
        if (var_v1 == 0) {
            func_800B6490();
        }
    }
}
