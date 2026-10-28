// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B6EE0(M2C_UNK);                         /* extern */
M2C_UNK func_800FFCBC(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80AE3938(u8 *);                      /* extern */

void func_800002DC(u8 *arg0, M2C_UNK arg1) {
    if ((M2C_FIELD(arg0, f32 *, 0x98) <= 150.0f) && (func_800B6EE0(arg1) != 0)) {
        func_80AE3938(arg0);
    }
    func_800FFCBC(arg0 + 0x3E0, 0, 1, 0x64, 0);
    func_800FFCBC(arg0 + 0x3E6, 0, 1, 0x64, 0);
}
