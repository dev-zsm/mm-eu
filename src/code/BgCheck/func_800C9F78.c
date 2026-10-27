#include "types.h"

extern s32 BgCheck_GetWaterSurface(s32 arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5, f32 *arg6);

s32 BgCheck_GetWaterSurfaceNoBgId(s32 arg0, s32 arg1, f32 x, f32 z, s32 arg4, s32 arg5) {
    f32 surface;

    return BgCheck_GetWaterSurface(arg0, arg1, x, z, arg4, arg5, &surface);
}
