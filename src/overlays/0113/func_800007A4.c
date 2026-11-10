#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
s32 func_808D70E4(u8 *);                          /* extern */

void func_800007A4(u8 *arg0, f32 arg1) {
    s32 temp_f16;
    s32 temp_v0;
    s32 var_s0;
    u8 *temp_v0_2;
    u8 *var_s1;

    temp_v0 = func_808D70E4(arg0);
    var_s0 = 0;
    if (temp_v0 > 0) {
        var_s1 = arg0;
        do {
            temp_v0_2 = M2C_FIELD(var_s1, u8 **, 0x150);
            if (temp_v0_2 != NULL) {
                M2C_FIELD(temp_v0_2, s32 *, 0x124) = 0;
                if (func_8008704C() <= arg1) {
                    temp_f16 = (s32) (func_8008704C() * ((f32) temp_v0 - 0.5f));
                    if (var_s0 != temp_f16) {
                        M2C_FIELD(M2C_FIELD(var_s1, u8 **, 0x150), s32 *, 0x124) = (s32) ((s32 *)(arg0 + 0x150))[temp_f16];
                    }
                }
            }
            var_s0 += 1;
            var_s1 += 4;
        } while (var_s0 < temp_v0);
    }
}
