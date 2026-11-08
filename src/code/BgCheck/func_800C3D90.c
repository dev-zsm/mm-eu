#include "types.h"
#include "generated/code_funcs.h"


f32 BgCheck_EntityRaycastFloor2(struct PlayState *play, struct CollisionContext *colCtx, struct CollisionPoly **outPoly, struct Vec3f *pos) {
    s32 sp34;

    BgCheck_RaycastFloorImpl(play, colCtx, 2, outPoly, &sp34, pos, 0, 0x1C, 1.0f, 0);
}
