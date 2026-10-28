// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800023B4(s32 arg0, s32 arg1, s32 *arg2, M2C_UNK arg3, s16 *arg4, u8 *arg5) {
    *arg2 = 0;
    if (arg1 == 9) {
        *arg4 += M2C_FIELD(arg5, s16 *, 0x466);
    }
    return 0;
}
