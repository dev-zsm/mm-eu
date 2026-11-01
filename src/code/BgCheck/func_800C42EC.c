// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK BgCheck_RaycastFloorImpl(M2C_UNK, s32, M2C_UNK, s32, s32, s32, s32, s32, f32, s32); /* extern */

void BgCheck_EntityRaycastFloor9(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    BgCheck_RaycastFloorImpl(0, arg0, 2, arg1, arg2, arg3, 0, 6, 1.0f, 0);
}
