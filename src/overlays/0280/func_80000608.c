#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B763C(M2C_UNK, u8 *, f32, f32, f32, s32); /* extern */
M2C_UNK func_809B0D90(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_809B0F04(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_809B0FA0(u8 *, M2C_UNK);             /* extern */

void func_80000608(u8 *arg0, M2C_UNK arg1) {
    func_809B0F04(arg0, arg1);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, M2C_UNK), 0x144)(arg0, arg1);
    func_800B763C(arg1, arg0, 0.0f, 0.0f, 0.0f, 4);
    func_809B0D90(arg0, arg1);
    func_809B0FA0(arg0, arg1);
}
