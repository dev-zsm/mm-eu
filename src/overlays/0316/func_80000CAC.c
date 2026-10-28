// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A19774(s32, s32);                    /* extern */
M2C_UNK func_80A19858(s32, s32);                    /* extern */

void func_80000CAC(s32 arg0, s32 arg1) {
    func_80A19858(arg0, arg1);
    func_80A19774(arg0, arg1);
}
