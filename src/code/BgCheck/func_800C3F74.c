#include "types.h"

extern f32 BgCheck_RaycastFloorImpl(void *play, void *colCtx, s32 xpFlags, void *arg3, void *arg4, void *arg5,
                                    void *arg6, s32 arg7, f32 arg8, s32 arg9);

f32 BgCheck_EntityRaycastFloor5_3(struct PlayState *play, struct CollisionContext *colCtx, struct CollisionPoly **outPoly, s32 *bgId, struct Actor *actor, struct Vec3f *pos) {
    return BgCheck_RaycastFloorImpl(play, colCtx, 2, outPoly, bgId, pos, actor, 60, 1.0f, 0);
}
