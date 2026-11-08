#include "types.h"
#include "generated/code_funcs.h"


s32 BgCheck_EntitySphVsWall1(struct CollisionContext *colCtx, struct Vec3f *posResult, struct Vec3f *posNext, struct Vec3f *posPrev, f32 radius, struct CollisionPoly **outPoly, f32 checkHeight) {
    s32 outValue;

    BgCheck_CheckWallImpl(colCtx, 2, posResult, posNext, posPrev, radius, outPoly, &outValue, 0, checkHeight, 0);
}
