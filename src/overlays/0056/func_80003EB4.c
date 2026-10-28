// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80123AFC(s32, s32, s32);                   /* extern */
s32 func_8082F474();                                /* extern */
M2C_UNK func_80830F70(s32);                         /* extern */

void func_80003EB4(s32 arg0, s32 arg1) {
    if (func_80123AFC(arg0, arg1, func_8082F474()) == 0xE) {
        func_80830F70(arg0);
    }
}
