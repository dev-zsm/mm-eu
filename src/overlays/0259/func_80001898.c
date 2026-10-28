// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8098EFB8(s32, s32);                    /* extern */
M2C_UNK func_8098F28C(s32, s32);                    /* extern */
M2C_UNK func_8098F4D8(s32, s32);                    /* extern */

void func_80001898(s32 arg0, s32 arg1) {
    func_8098EFB8(arg0, arg1);
    func_8098F28C(arg0, arg1);
    func_8098F4D8(arg0, arg1);
}
