#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B763C(s32, u8 *, f32, f32, f32, s32); /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
s32 func_80ACE87C(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_80ACE8FC(u8 *, s32);                 /* extern */
M2C_UNK func_80AD0860(u8 *, s32);                 /* extern */

void func_80002154(u8 *arg0, s32 arg1) {
    func_80137070(arg0 + 0x190);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x1D4)(arg0, arg1);
    func_80AD0860(arg0, arg1);
    func_800B763C(arg1, arg0, 0.0f, 0.0f, 0.0f, 4);
    func_80ACE8FC(arg0, arg1);
    if (func_80ACE87C(0, 2) != 0) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    }
}
