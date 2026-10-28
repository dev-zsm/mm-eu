// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013B284(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_80BA4C2C(s32, M2C_UNK);                /* extern */
extern u8 D_801E7F00;

s32 func_80000E5C(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    if (!(D_801E7F00 & 8)) {
        func_8013B284(arg0 + 0x262, 3, 7);
    } else {
        func_8013B284(arg0 + 0x262, 4, 7);
    }
    func_80BA4C2C(arg0, 0);
    return 1;
}
