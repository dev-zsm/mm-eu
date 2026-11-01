// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

extern void *D_801C9E40;

void PadMgr_RumblePause(void) {
    M2C_FIELD(D_801C9E40, s8 *, 0x47C) = 0xC;
}
