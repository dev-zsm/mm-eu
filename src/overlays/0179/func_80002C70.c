#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800B763C(M2C_UNK, u8 *, f32, f32, f32, s32); /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_8094686C(M2C_UNK);                     /* extern */
M2C_UNK func_80946B8C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80948B24(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80948BC8(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80948DD0(u8 *, M2C_UNK);             /* extern */

void func_80002C70(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, M2C_UNK), 0x1D4)(arg0, arg1);
    func_80948DD0(arg0, arg1);
    func_800B680C(arg0);
    func_80946B8C(arg0, arg1);
    func_800B763C(arg1, arg0, 0.0f, 0.0f, 0.0f, 4);
    func_80137070(arg0 + 0x190);
    func_8094686C(arg1);
    func_80948BC8(arg0, arg1);
    func_80948B24(arg0, arg1);
}
