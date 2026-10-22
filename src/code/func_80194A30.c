// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_80088070(M2C_UNK *, u32 *, M2C_UNK);       /* extern */
extern M2C_UNK D_801FA2F0;

u32 AudioThread_GetExternalLoadQueueMsg(s32 *arg0) {
    u32 sp1C;

    if (func_80088070(&D_801FA2F0, &sp1C, 0) == -1) {
        *arg0 = 0;
        return 0U;
    }
    *arg0 = sp1C & 0xFFFFFF;
    return sp1C >> 0x18;
}
