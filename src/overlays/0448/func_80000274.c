// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80AE1690();                            /* extern */
extern M2C_UNK D_80AE18C4;

void func_80000274(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x14) > 0) {
        func_80AE1690();
        M2C_FIELD(arg0, M2C_UNK **, 0x150) = &D_80AE18C4;
    }
}
