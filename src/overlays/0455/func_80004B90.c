// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_801A0070(s32, M2C_UNK);                /* extern */
M2C_UNK func_80AEB330(s32, s32, s32);               /* extern */
s32 func_80AEBFBC(s32);                             /* extern */
M2C_UNK func_80AEE7C4(s32, s32);                    /* extern */

void func_80004B90(s32 arg0, s32 arg1) {
    func_80137070(arg0 + 0x144);
    func_801A0070(arg0 + 0x458, 0x314B);
    if (func_80AEBFBC(arg0) != 0) {
        func_80AEB330(arg0, arg0 + 0x380, arg1);
        func_80AEE7C4(arg0, arg1);
    }
}
