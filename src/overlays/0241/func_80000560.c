// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8013E684(s32, s16, M2C_UNK, M2C_UNK);      /* extern */
M2C_UNK func_8097CD80(s32, u8 *);                 /* extern */

void func_80000560(s32 arg0, u8 *arg1) {
    if (func_8013E684(arg0, M2C_FIELD(arg1, s16 *, 0x1879C), -1, 1) != 0) {
        func_8097CD80(arg0, arg1);
    }
}
