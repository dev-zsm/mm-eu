// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80137070(s32);                             /* extern */
M2C_UNK func_80874968(s32);                         /* extern */

void func_80000D5C(s32 arg0, M2C_UNK arg1) {
    if (func_80137070(arg0 + 0x144) != 0) {
        func_80874968(arg0);
    }
}
