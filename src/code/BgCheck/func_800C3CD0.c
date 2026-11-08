// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK BgCheck_RaycastFloorImpl(M2C_UNK, s32, M2C_UNK, M2C_UNK, M2C_UNK *, s32, s32, s32, f32, s32); /* extern */

f32 BgCheck_CameraRaycastFloor1(struct CollisionContext *colCtx, struct CollisionPoly **outPoly, struct Vec3f *pos) {
    M2C_UNK sp34;

    BgCheck_RaycastFloorImpl(0, colCtx, 1, outPoly, &sp34, pos, 0, 0x1C, 1.0f, 0);
}
