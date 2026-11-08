// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80002F80(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s16 *arg4, u8 *arg5) {
    if (arg1 == 0x17) {
        arg4[1] += M2C_FIELD(arg5, s16 *, 0x3D8);
    } else if (arg1 == 0xC) {
        arg4[1] += M2C_FIELD(arg5, s16 *, 0x3DA);
    }
    return 0;
}
