#include "types.h"

extern s32 BgCheck_GetWaterSurface(s32 arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5, f32 *arg6);

s32 BgCheck_GetWaterSurfaceNoBgId(struct PlayState *play, struct CollisionContext *colCtx, f32 x, f32 z, f32 *outWaterSurface, struct WaterBox **outWaterBox) {
    f32 surface;

    return BgCheck_GetWaterSurface(play, colCtx, x, z, outWaterSurface, outWaterBox, &surface);
}
