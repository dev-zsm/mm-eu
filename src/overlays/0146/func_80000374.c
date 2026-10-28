// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK, u8 *);        /* extern */

void func_80000374(u8 *arg0) {
    s16 temp_v0;
    s16 var_v1;

    if (M2C_FIELD(arg0, u16 *, 0x2C6) & 0x40) {
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x2DE);
        if (temp_v0 == 0) {
            var_v1 = 0;
        } else {
            M2C_FIELD(arg0, s16 *, 0x2DE) = (s16) (temp_v0 - 1);
            var_v1 = M2C_FIELD(arg0, s16 *, 0x2DE);
        }
        if (var_v1 == 0) {
            M2C_FIELD(arg0, s16 *, 0x2E0) = (s16) (M2C_FIELD(arg0, s16 *, 0x2E0) + 1);
            if (M2C_FIELD(arg0, s16 *, 0x2E0) >= 4) {
                M2C_FIELD(arg0, s16 *, 0x2DE) = func_800FF250(0x1E, 0x1E, arg0);
                M2C_FIELD(arg0, s16 *, 0x2E0) = 0;
            }
        }
    }
}
