#include "types.h"
#include "m2c_compat.h"

s32 func_800017B4(s32 arg0, s32 arg1, s32 *arg2, M2C_UNK arg3, s16 *arg4, u8 *arg5) {
    u8 *this = arg5;
    if (arg1 == 0xF) {
        *arg2 = 0;
    }
    if (arg1 == 0x11) {
        *arg4 += M2C_FIELD(arg5, s16 *, 0x28A);
    }
    if ((arg1 == 0x13) && (M2C_FIELD(arg5, s16 *, 0x2F6) == 2)) {
        *arg2 = 0;
    }
    if ((arg1 == 0x14) && (M2C_FIELD(arg5, s16 *, 0x2F6) == 0)) {
        *arg2 = 0;
    }
    return 0;
}
