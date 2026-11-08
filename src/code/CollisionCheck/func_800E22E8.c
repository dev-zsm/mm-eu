// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void CollisionCheck_EnableSAC(struct PlayState *play, struct CollisionCheckContext *colChkCtx) {
    M2C_FIELD(colChkCtx, u16 *, 2) = (u16) (M2C_FIELD(colChkCtx, u16 *, 2) | 1);
}
