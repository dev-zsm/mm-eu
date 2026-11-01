// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8017B8E4(f32, f32, s32, s32);              /* extern */
extern f32 D_80A50784;
extern f32 D_80A50788;

s32 func_80000170(u8 *arg0, u8 *arg1) {
    f32 temp_f0;
    f32 temp_f28;
    f32 temp_f2;
    f32 var_f20;
    s32 temp_s2;
    s32 var_s6;
    u8 *var_s0;

    var_s0 = M2C_FIELD(arg1, u8 **, 0x1D08);
    var_f20 = D_80A50784;
    var_s6 = 0;
    M2C_FIELD(arg0, u8 **, 0x34C) = NULL;
    if (var_s0 != NULL) {
        temp_f28 = D_80A50788;
        do {
            if ((M2C_FIELD(var_s0, s16 *, 0) == 0x91) && ((temp_s2 = ((s16) M2C_FIELD(var_s0, s16 *, 0x1C) >> 0xE) & 3, (temp_s2 == 1)) || (temp_s2 == 2)) && (M2C_FIELD(arg0, s8 *, 3) == M2C_FIELD(var_s0, s8 *, 3))) {
                temp_f0 = func_8017B8E4(M2C_FIELD(arg0, f32 *, 0x24), M2C_FIELD(arg0, f32 *, 0x2C), M2C_FIELD(var_s0, s32 *, 0x24), M2C_FIELD(var_s0, s32 *, 0x2C));
                temp_f2 = M2C_FIELD(var_s0, f32 *, 0x28) - M2C_FIELD(arg0, f32 *, 0x28);
                if ((temp_f0 < var_f20) && (temp_f2 < 100.0f) && (temp_f2 > -50.0f)) {
                    var_s6 = 1;
                    var_f20 = temp_f0;
                    M2C_FIELD(arg0, u8 **, 0x34C) = var_s0;
                    if (temp_s2 == 1) {
                        M2C_FIELD(arg0, f32 *, 0x350) = 900.0f;
                    } else {
                        M2C_FIELD(arg0, f32 *, 0x350) = temp_f28;
                    }
                }
            }
            var_s0 = M2C_FIELD(var_s0, u8 **, 0x12C);
        } while (var_s0 != NULL);
    }
    return var_s6;
}
