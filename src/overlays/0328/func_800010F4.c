#include "types.h"
#include "m2c_compat.h"

s16 func_800B6A58(u8 *, s32);                     /* extern */
M2C_UNK func_80A23EAC(u8 *, u8 *, M2C_UNK);              /* extern */
s32 func_80A2400C(u8 *, u8 *, M2C_UNK, M2C_UNK, f32, f32); /* extern */

s32 func_800010F4(u8 *arg0, u8 *arg1, M2C_UNK arg3, s32 arg3x) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a1;

    func_80A23EAC(arg0, arg1, arg3);
    temp_v0 = func_80A2400C(arg1, arg0, 0x1F2, 6, 100.0f, 20.0f);
    var_a1 = temp_v0;
    if ((temp_v0 != 0) || (temp_v0_2 = func_80A2400C(arg1, arg0, 0x1D5, 4, 100.0f, 20.0f), var_a1 = temp_v0_2, (temp_v0_2 != 0))) {
        M2C_FIELD(arg0, s16 *, 0x16) = func_800B6A58(arg0, var_a1);
    }
    M2C_FIELD(arg1, M2C_UNK (**)(u8 *, u8 *, M2C_UNK), 0x1877C)(arg1, arg0, 0x61);
    return 1;
}
