// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800027A0(s32 arg0, s32 arg1, s32 *arg2, M2C_UNK arg3, s16 *arg4, u8 *arg5) {
    if (!(M2C_FIELD(arg5, u16 *, 0x29C) & 1)) {
        if (arg1 == 0x11) {
            goto block_4;
        }
    } else if (arg1 == 0x10) {
block_4:
        *arg2 = 0;
    }
    if (arg1 == 0xB) {
        *arg4 += M2C_FIELD(arg5, s16 *, 0x2CE);
    }
    return 0;
}
