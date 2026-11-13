#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0169.h"

M2C_UNK func_800FF30C(s32, s32);                    /* extern */

void func_80000000(u8 *arg0, u8 *arg1) {
    s32 temp_s2;
    s32 var_s0;
    s32 var_s1;

    s32 temp_s2_t;
    var_s0 = 0;
    temp_s2_t = M2C_FIELD(arg1, s32 *, 0x1CCC);
    temp_s2 = temp_s2_t + 0x24;
    var_s1 = arg0 + 0x2A4;
    do {
        func_800FF30C(var_s1, temp_s2);
        var_s0 += 0xC;
        var_s1 += 0xC;
    } while (var_s0 != 0xF0);
    M2C_FIELD(arg0, s16 *, 0x14) = 0;
    M2C_FIELD(arg0, s16 *, 0x18) = 0;
}
