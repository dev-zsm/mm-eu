#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B763C(M2C_UNK, u8 *, f32, f32, f32, s32); /* extern */
s32 func_801244EC(M2C_UNK);                         /* extern */
M2C_UNK func_808F2960(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_808F29D0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_808F29F4(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_808F2AD4(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_808F2FB8(u8 *, M2C_UNK);             /* extern */

void func_80003198(u8 *arg0, M2C_UNK arg1) {
    s32 temp_v1;

    func_808F29D0(arg0, arg1);
    func_808F29F4(arg0, arg1);
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x4AC);
    if (temp_v1 & 2) {
        M2C_FIELD(arg0, s32 *, 0x4AC) = (s32) (temp_v1 & ~2);
        func_808F2FB8(arg0, arg1);
    }
    if (func_801244EC(arg1) == 8) {
        M2C_FIELD(arg0, s32 *, 0x4AC) = (s32) (M2C_FIELD(arg0, s32 *, 0x4AC) | 0x40);
    } else {
        M2C_FIELD(arg0, s32 *, 0x4AC) = (s32) (M2C_FIELD(arg0, s32 *, 0x4AC) & ~0x40);
    }
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, M2C_UNK), 0x144)(arg0, arg1);
    func_800B763C(arg1, arg0, 0.0f, 0.0f, 0.0f, 4);
    func_808F2AD4(arg0, arg1);
    func_808F2960(arg0, arg1);
}
