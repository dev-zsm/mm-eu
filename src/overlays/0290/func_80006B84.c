#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0290.h"

s32 func_80006B84(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, u8 *arg4, u8 *arg5) {
    u8 *this = arg5;
    if (arg1 == 0x1A) {
        M2C_FIELD(arg4, s16 *, 0) = (s16) (M2C_FIELD(this, s16 *, 0x17DA) + M2C_FIELD(arg4, s16 *, 0));
        M2C_FIELD(arg4, s16 *, 2) = (s16) (M2C_FIELD(this, s16 *, 0x17D8) + M2C_FIELD(arg4, s16 *, 2));
        M2C_FIELD(arg4, s16 *, 4) = (s16) (M2C_FIELD(this, s16 *, 0x17DC) + M2C_FIELD(arg4, s16 *, 4));
    }
    return 0;
}
