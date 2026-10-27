// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern f32 D_801D5654;

s32 Collider_ResetQuadACDist(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, f32 *, 0x3C) = (f32) D_801D5654;
    return 1;
}
