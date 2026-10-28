// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_8092A414(s32, s32);                    /* extern */

void func_8000065C(s32 arg0, s32 arg1) {
    func_80137070(arg0 + 0x194);
    func_8092A414(arg0, arg1);
}
