#include "types.h"
#include "m2c_compat.h"

extern s32 D_809D69F0[];

s32 func_80002FCC(s32 arg0, s32 arg1, s32 *arg2, M2C_UNK arg3, u8 *arg4, u8 *arg5) {
    if (arg1 != D_809D69F0[M2C_FIELD(arg5, s16 *, 0x1C)]) {
        *arg2 = 0;
    } else if ((s32) M2C_FIELD(arg5, u8 *, 0x15C) >= 2) {
        M2C_FIELD(arg4, s16 *, 0) = (s16) ((M2C_FIELD(arg5, s16 *, 0x160) * 0x3000) + M2C_FIELD(arg4, s16 *, 0));
        M2C_FIELD(arg4, s16 *, 2) = (s16) ((M2C_FIELD(arg5, s16 *, 0x160) * 0x1A00) + M2C_FIELD(arg4, s16 *, 2));
        M2C_FIELD(arg4, s16 *, 4) = (s16) ((M2C_FIELD(arg5, s16 *, 0x160) << 0xD) + M2C_FIELD(arg4, s16 *, 4));
    }
    return 0;
}
