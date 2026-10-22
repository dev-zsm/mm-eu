// FLAGS: -O2 -g3 -mips2
#include "types.h"

void BgCheck_GetWaterSurfaceNoBgId(s32, s32, f32, f32, s32, s32);

void BgCheck_GetWaterSurfaceNoBgIdAlt(s32 arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5) {
    BgCheck_GetWaterSurfaceNoBgId(arg0, arg1, arg2, arg3, arg4, arg5);
}
