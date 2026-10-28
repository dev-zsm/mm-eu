// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK, u8 *);        /* extern */

void func_800001DC(u8 *arg0, s32 arg1) {
    s16 temp_v0;
    s16 var_v1;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x420);
    if (temp_v0 == 0) {
        var_v1 = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 0x420) = (s16) (temp_v0 - 1);
        var_v1 = M2C_FIELD(arg0, s16 *, 0x420);
    }
    if (var_v1 == 0) {
        M2C_FIELD(arg0, s16 *, 0x41E) = (s16) (M2C_FIELD(arg0, s16 *, 0x41E) + 1);
        if (M2C_FIELD(arg0, s16 *, 0x41E) >= arg1) {
            M2C_FIELD(arg0, s16 *, 0x41E) = 0;
            M2C_FIELD(arg0, s16 *, 0x420) = func_800FF250(0x1E, 0x1E, arg0);
        }
    }
}
