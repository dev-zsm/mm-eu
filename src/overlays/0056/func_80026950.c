#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEE3C(u8 *, M2C_UNK, M2C_UNK, u8 *); /* extern */
M2C_UNK func_80136480(s32, s32, s32, u8 *);            /* extern */
M2C_UNK func_80833150(u8 *, s32);                 /* extern */

void func_80026950(u8 *arg0, s32 arg1, s32 arg2x) {
    f32 temp_f0;

    M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
    func_80136480(arg1, arg0 + 0x240, arg2x, arg0);
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x68);
    if (temp_f0 < 0.0f) {
        func_80833150(arg0, arg1);
        return;
    }
    if (temp_f0 < 6.0f) {
        func_800FEE3C(arg0 + 0xAD0, 0x40400000, 0x3F000000, arg0);
    }
}
