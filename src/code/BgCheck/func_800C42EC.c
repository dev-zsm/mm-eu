// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK BgCheck_RaycastFloorImpl(M2C_UNK, s32, M2C_UNK, s32, s32, s32, s32, s32, f32, s32); /* extern */

f32 BgCheck_EntityRaycastFloor9(struct CollisionContext *colCtx, struct CollisionPoly **outPoly, s32 *bgId, struct Vec3f *pos) {
    BgCheck_RaycastFloorImpl(0, colCtx, 2, outPoly, bgId, pos, 0, 6, 1.0f, 0);
}
