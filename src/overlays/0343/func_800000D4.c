// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK, u8 *);        /* extern */

s32 func_800000D4(u8 *arg0) {
    s16 temp_v0;
    s16 var_v1;
    s32 var_a1;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x29E);
    var_a1 = 0;
    if (temp_v0 == 0) {
        var_v1 = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 0x29E) = (s16) (temp_v0 - 1);
        var_v1 = M2C_FIELD(arg0, s16 *, 0x29E);
    }
    if (var_v1 == 0) {
        M2C_FIELD(arg0, s16 *, 0x2A0) = (s16) (M2C_FIELD(arg0, s16 *, 0x2A0) + 1);
        if (M2C_FIELD(arg0, s16 *, 0x2A0) >= 3) {
            M2C_FIELD(arg0, s16 *, 0x29E) = func_800FF250(0x14, 0x14, arg0);
            M2C_FIELD(arg0, s16 *, 0x2A0) = 0;
        }
        var_a1 = 1;
    }
    return var_a1;
}
