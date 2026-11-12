#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B763C(M2C_UNK, u8 *, f32, f32, f32, s32); /* extern */
M2C_UNK func_809745E8(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80974668(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80974BE8(M2C_UNK, u8 *, M2C_UNK);    /* extern */

void func_80000328(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, M2C_UNK), 0x144)(arg0, arg1);
    func_800B763C(arg1, arg0, 0.0f, 0.0f, 0.0f, 4);
    func_80974668(arg0, arg1);
    func_80974BE8(arg1, arg0 + 0x2F0, 0xA);
    func_809745E8(arg0, arg1);
}
