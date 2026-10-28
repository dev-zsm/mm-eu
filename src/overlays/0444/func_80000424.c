// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800B763C(s32, u8 *, M2C_UNK, M2C_UNK, f32, s32); /* extern */
M2C_UNK func_80ADB870(u8 *, s32);                 /* extern */

void func_80000424(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x190)(arg0, arg1);
    func_800B680C(arg0);
    func_800B763C(arg1, arg0, 0x42000000, 0x41F00000, 0.0f, 0xC);
    func_80ADB870(arg0, arg1);
}
