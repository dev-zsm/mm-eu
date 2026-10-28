// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B5BA4(M2C_UNK, s32);                /* extern */
u8 *func_8013DD10(M2C_UNK, u8 *, M2C_UNK, M2C_UNK); /* extern */

void func_80000520(s32 arg0, M2C_UNK arg1) {
    u8 *temp_v0;
    u8 *var_s0;

    var_s0 = NULL;
    do {
        temp_v0 = func_8013DD10(arg1, var_s0, 1, 0x17E);
        var_s0 = temp_v0;
        if (temp_v0 != NULL) {
            func_800B5BA4(arg1, ((s16) M2C_FIELD(temp_v0, s16 *, 0x1C) >> 4) & 0x7F);
            var_s0 = M2C_FIELD(var_s0, u8 **, 0x12C);
        }
    } while (var_s0 != NULL);
}
