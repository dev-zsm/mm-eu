#include "types.h"
#include "m2c_compat.h"

s32 func_800010BC(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, u8 *arg4, u8 *arg5) {
    u8 *this = arg5;
    if (arg1 == 0xD) {
        M2C_FIELD(arg4, s16 *, 2) = (s16) (M2C_FIELD(this, s16 *, 0x262) + M2C_FIELD(arg4, s16 *, 2));
    }
    if ((arg1 == 0xB) || (arg1 == 7)) {
        M2C_FIELD(arg4, s16 *, 2) = (s16) (M2C_FIELD(this, s16 *, 0x25E) + M2C_FIELD(arg4, s16 *, 2));
        M2C_FIELD(arg4, s16 *, 4) = (s16) (M2C_FIELD(this, s16 *, 0x260) + M2C_FIELD(arg4, s16 *, 4));
    }
    return 0;
}
