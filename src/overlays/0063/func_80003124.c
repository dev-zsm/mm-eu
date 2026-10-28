// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80137070(s32);                             /* extern */
M2C_UNK func_8086C610(s32, s32);                    /* extern */

void func_80003124(s32 arg0, s32 arg1) {
    if (func_80137070(arg0 + 0x144) != 0) {
        func_8086C610(arg0, arg1);
    }
}
