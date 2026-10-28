// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_808360A4(s32, s32);                    /* extern */
M2C_UNK func_808393B0(s32, s32);                    /* extern */

void func_8000C3D4(s32 arg0, s32 arg1) {
    func_808360A4(arg0, arg1);
    func_808393B0(arg0, arg1);
}
