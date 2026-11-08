// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s32 Collider_DestroyJntSphElementDim(struct PlayState *play, struct ColliderJntSphElementDim *dim) {
    return 1;
}
