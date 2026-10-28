// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

u8 *func_8013DD10(M2C_UNK, s32, M2C_UNK, M2C_UNK); /* extern */

s32 func_80000D54(u8 *arg0, M2C_UNK arg1) {
    s32 temp_v1;
    s32 var_s0;
    u8 *temp_v0;

    var_s0 = 0;
loop_1:
    temp_v0 = func_8013DD10(arg1, var_s0, 4, 0x19E);
    if ((temp_v0 != NULL) && (temp_v0 != arg0)) {
        if ((M2C_FIELD(temp_v0, f32 *, 8) == M2C_FIELD(arg0, f32 *, 8)) && (M2C_FIELD(temp_v0, f32 *, 0xC) == M2C_FIELD(arg0, f32 *, 0xC)) && (M2C_FIELD(temp_v0, f32 *, 0x10) == M2C_FIELD(arg0, f32 *, 0x10))) {
            return 1;
        }
        var_s0 = M2C_FIELD(temp_v0, s32 *, 0x12C);
        goto loop_1;
    }
    if (temp_v0 != NULL) {
        temp_v1 = M2C_FIELD(temp_v0, s32 *, 0x12C);
        if (temp_v1 != 0) {
            var_s0 = temp_v1;
            goto loop_1;
        }
    }
    return 0;
}
