// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK, u8 *);        /* extern */

void func_80000168(u8 *arg0) {
    s16 temp_v0;
    s16 var_v1;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x360);
    if (temp_v0 == 0) {
        var_v1 = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 0x360) = (s16) (temp_v0 - 1);
        var_v1 = M2C_FIELD(arg0, s16 *, 0x360);
    }
    if (var_v1 == 0) {
        M2C_FIELD(arg0, s16 *, 0x362) = (s16) (M2C_FIELD(arg0, s16 *, 0x362) + 1);
        if (M2C_FIELD(arg0, s16 *, 0x362) >= 4) {
            M2C_FIELD(arg0, s16 *, 0x360) = func_800FF250(0x1E, 0x1E, arg0);
            M2C_FIELD(arg0, s16 *, 0x362) = 0;
        }
    }
}
