// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F0308(M2C_UNK, u8 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8098E010(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_8098E054(u8 *, M2C_UNK);             /* extern */

void func_80000680(u8 *arg0, M2C_UNK arg1) {
    s32 var_s2;
    u8 *temp_s0;
    u8 *var_s1;

    var_s2 = 0;
    var_s1 = arg0;
    do {
        temp_s0 = M2C_FIELD(var_s1, u8 **, 0x2994);
        if ((temp_s0 != NULL) && (M2C_FIELD(var_s1, u8 *, 0x2959) & 2)) {
            func_8098E054(temp_s0, arg1);
            func_8098E010(temp_s0, arg1);
            M2C_FIELD(temp_s0, u8 *, 0xF) = (u8) (M2C_FIELD(temp_s0, u8 *, 0xF) | 4);
            func_800F0308(arg1, temp_s0, 0x14, 0x284E);
        }
        var_s2 += 0x50;
        var_s1 += 0x50;
    } while (var_s2 != 0x640);
}
