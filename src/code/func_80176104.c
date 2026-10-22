// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern void *D_801C9E40;

void PadMgr_UnsetRumbleRetraceCallback(s32 arg0, s32 arg1) {
    if ((arg0 == M2C_FIELD(D_801C9E40, s32 *, 4)) && (arg1 == M2C_FIELD(D_801C9E40, s32 *, 8))) {
        M2C_FIELD(D_801C9E40, s32 *, 4) = 0;
        M2C_FIELD(D_801C9E40, s32 *, 8) = 0;
    }
}
