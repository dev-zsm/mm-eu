// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

extern f32 D_801D5654;

s32 Collider_ResetQuadACDist(struct PlayState *play, struct ColliderQuadDim *dim) {
    M2C_FIELD(dim, f32 *, 0x3C) = (f32) D_801D5654;
    return 1;
}
