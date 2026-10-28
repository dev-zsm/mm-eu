// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEE3C(s32, s32, s32);               /* extern */

void func_800060BC(u8 *arg0) {
    f32 temp_f0;
    s32 var_s2;
    s32 var_s3;
    u8 *var_s0;
    u8 *var_s1;

    var_s2 = 0;
    var_s0 = arg0;
    var_s1 = arg0 + 0x9F8;
    var_s3 = arg0 + 0x9FC;
    do {
        func_800FEE3C(var_s3, M2C_FIELD(var_s0, s32 *, 0xA04), M2C_FIELD(var_s0, s32 *, 0xA08));
        temp_f0 = M2C_FIELD(var_s1, f32 *, 0x10);
        var_s2 += 0x28;
        var_s0 += 0x28;
        var_s3 += 0x28;
        if (temp_f0 > 0.0f) {
            M2C_FIELD(var_s1, f32 *, 0x10) = (f32) (temp_f0 + 6.0f);
        }
        var_s1 += 0x28;
    } while (var_s2 != 0x5A0);
}
