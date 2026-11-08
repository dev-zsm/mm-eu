// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void FrameAdvance_Init(struct FrameAdvanceContext *frameAdvCtx) {
    M2C_FIELD(frameAdvCtx, s32 *, 4) = 0;
    M2C_FIELD(frameAdvCtx, s32 *, 0) = 0;
}
