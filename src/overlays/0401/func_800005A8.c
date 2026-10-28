// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8016A23C(s32);                             /* extern */

void func_800005A8(u8 *arg0, s32 arg1) {
    if (func_8016A23C(arg1) == 0) {
        M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x15C)(arg0, arg1);
    }
}
