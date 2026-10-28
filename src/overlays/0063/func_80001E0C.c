// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80137070(s32);                             /* extern */
M2C_UNK func_80869C04(s32, s32);                    /* extern */
M2C_UNK func_80869FE0(s32);                         /* extern */

void func_80001E0C(s32 arg0, s32 arg1) {
    if (func_80137070(arg0 + 0x144) != 0) {
        func_80869C04(arg0, arg1);
        func_80869FE0(arg0);
    }
}
