// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_809DA09C(u8 *, s32, s32);            /* extern */

void func_80000B14(s32 arg0, u8 *arg1) {
    u8 *temp_s1;
    u8 *var_s0;

    var_s0 = M2C_FIELD(arg1, u8 **, 0x1CD8);
    if (var_s0 != NULL) {
        do {
            temp_s1 = var_s0 + 0x24;
            if (M2C_FIELD(var_s0, s16 *, 0x1C) == 1) {
                func_809DA09C(temp_s1, arg0 + 0x7AC, arg0 + 0xC5C);
                func_809DA09C(temp_s1, arg0 + 0xFB8, arg0 + 0x1468);
            }
            var_s0 = M2C_FIELD(var_s0, u8 **, 0x12C);
        } while (var_s0 != NULL);
    }
}
