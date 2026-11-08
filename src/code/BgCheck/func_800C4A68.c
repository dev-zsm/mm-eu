#include "types.h"
#include "generated/code_funcs.h"


s32 BgCheck_EntitySphVsWall2(struct CollisionContext *colCtx, struct Vec3f *posResult, struct Vec3f *posNext, struct Vec3f *posPrev, f32 radius, struct CollisionPoly **outPoly, s32 *outBgId, f32 checkHeight) {
    return BgCheck_CheckWallImpl(colCtx, 2, posResult, posNext, posPrev, radius, outPoly, outBgId, 0, checkHeight, 0);
}
