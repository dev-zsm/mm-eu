// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B6404(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_80ADB6C4(u8 *);                      /* extern */

void func_800001F8(u8 *arg0, M2C_UNK arg1) {
    s32 temp_v0;

    temp_v0 = func_800B6404(arg1, 0x1D2, arg1);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s32 *, 0x198) = temp_v0;
        func_80ADB6C4(arg0);
    }
}
