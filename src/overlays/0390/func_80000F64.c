#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A99DE0(u8 *, M2C_UNK);                     /* extern */

void func_80000F64(u8 *arg0, u8 *arg1) {
    s32 temp_v0;

    func_80A99DE0(arg0, 1);
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x3C4);
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    if (temp_v0 != -1) {
        M2C_FIELD(arg0, s32 *, 0x3AC) = (s32) (M2C_FIELD(arg1, s32 *, 0x18864) + (temp_v0 * 8));
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x3AC) = 0;
}
