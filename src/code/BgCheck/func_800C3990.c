// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void BgCheck_SetContextFlags(struct CollisionContext *colCtx, u32 flags) {
    M2C_FIELD(colCtx, s32 *, 0x146C) = (s32) (M2C_FIELD(colCtx, s32 *, 0x146C) | flags);
}
