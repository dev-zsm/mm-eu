// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80A8ABEC(u8 *, s32);                 /* extern */
M2C_UNK func_80A8B02C(u8 *, s32);                 /* extern */

void func_80001494(u8 *arg0, s32 arg1) {
    func_80137070(arg0 + 0x144);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x23C)(arg0, arg1);
    M2C_FIELD(arg0, u16 *, 0x262) = (u16) (M2C_FIELD(arg0, u16 *, 0x262) + 1);
    func_80A8ABEC(arg0, arg1);
    func_80A8B02C(arg0, arg1);
}
