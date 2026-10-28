// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8018122C();                            /* extern */
M2C_UNK func_8018125C();                            /* extern */
M2C_UNK func_80B07CD8(s32, s32);                    /* extern */

void func_80000E38(s32 arg0, s32 arg1) {
    func_8018122C();
    func_80B07CD8(arg0 + 0x148, arg1);
    func_8018125C();
}
