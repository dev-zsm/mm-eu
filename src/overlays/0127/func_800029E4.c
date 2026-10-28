// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800F3F94(s32, s32);                        /* extern */
M2C_UNK func_808F4DE8(s32, s32, M2C_UNK, s32);      /* extern */
extern s32 D_801E6F08;

void func_800029E4(s32 arg0, s32 arg1) {
    if (func_800F3F94(arg1, arg1 + 0x1CA0) != 0) {
        if (D_801E6F08 == 3) {
            func_808F4DE8(arg1, arg0, 7, arg0 + 0x48C);
            return;
        }
        func_808F4DE8(arg1, arg0, 3, arg0 + 0x48C);
        return;
    }
    if (D_801E6F08 == 3) {
        func_808F4DE8(arg1, arg0, 5, arg0 + 0x48C);
        return;
    }
    func_808F4DE8(arg1, arg0, 1, arg0 + 0x48C);
}
