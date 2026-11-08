// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"


s32 BgCheck_GetWaterSurfaceNoBgIdAlt(struct PlayState *play, struct CollisionContext *colCtx, f32 x, f32 z, f32 *outWaterSurface, struct WaterBox **outWaterBox) {
    BgCheck_GetWaterSurfaceNoBgId(play, colCtx, x, z, outWaterSurface, outWaterBox);
}
