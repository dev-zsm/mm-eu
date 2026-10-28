// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK, u8 *);        /* extern */

void func_80001D9C(u8 *arg0) {
    s16 temp_v0;
    s16 var_v1;

    if (M2C_FIELD(arg0, u16 *, 0x390) & 0x20) {
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x3BC);
        if (temp_v0 == 0) {
            var_v1 = 0;
        } else {
            M2C_FIELD(arg0, s16 *, 0x3BC) = (s16) (temp_v0 - 1);
            var_v1 = M2C_FIELD(arg0, s16 *, 0x3BC);
        }
        if (var_v1 == 0) {
            M2C_FIELD(arg0, s16 *, 0x3BE) = (s16) (M2C_FIELD(arg0, s16 *, 0x3BE) + 1);
            if (M2C_FIELD(arg0, s16 *, 0x3BE) >= 4) {
                M2C_FIELD(arg0, s16 *, 0x3BC) = func_800FF250(0x1E, 0x1E, arg0);
                M2C_FIELD(arg0, s16 *, 0x3BE) = 0;
            }
        }
    }
}
