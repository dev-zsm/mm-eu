// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80A69978(s32);                             /* extern */
M2C_UNK func_80A69CC8(s32);                         /* extern */

void func_80000340(s32 arg0, M2C_UNK arg1) {
    if (func_80A69978(arg0) != 0) {
        func_80A69CC8(arg0);
    }
}
