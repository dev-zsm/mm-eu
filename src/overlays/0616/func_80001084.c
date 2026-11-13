#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0616.h"

s32 func_80001084(s32 arg0, s32 arg1, s32 *arg2, M2C_UNK arg3, u8 *arg4, u8 *arg5) {
    u8 *this = arg5;
    if (arg1 == 0xF) {
        *arg2 = 0;
    }
    if (arg1 == 0x11) {
        M2C_FIELD(arg4, s16 *, 0) = (s16) (M2C_FIELD(this, s16 *, 0x28A) + M2C_FIELD(arg4, s16 *, 0));
        M2C_FIELD(arg4, s16 *, 4) = (s16) (M2C_FIELD(this, s16 *, 0x288) + M2C_FIELD(arg4, s16 *, 4));
    }
    if (arg1 == 0x13) {
        *arg2 = 0;
    }
    return 0;
}
