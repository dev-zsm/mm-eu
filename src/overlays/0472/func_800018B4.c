// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800018B4(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, u8 *arg4, u8 *arg5) {
    if (arg1 == 0xC) {
        M2C_FIELD(arg4, s16 *, 2) = (s16) (M2C_FIELD(arg4, s16 *, 2) - M2C_FIELD(arg5, s16 *, 0x27A));
    }
    return 0;
}
