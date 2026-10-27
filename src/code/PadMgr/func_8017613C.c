// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern void *D_801C9E40;

void PadMgr_SetInputRetraceCallback(s32 arg0, s32 arg1) {
    M2C_FIELD(D_801C9E40, s32 *, 0xC) = arg0;
    M2C_FIELD(D_801C9E40, s32 *, 0x10) = arg1;
}
