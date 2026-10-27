#include "types.h"

extern s32 BgCheck_CheckWallImpl(void *a0, s32 a1, void *a2, void *a3, s32 a4, f32 a5, s32 a6, s32 a7, s32 a8, f32 a9, s32 a10);

s32 BgCheck_EntitySphVsWall2(void *colCtx, void *posResult, void *pos, s32 arg3, f32 radius, s32 arg5, s32 arg6, f32 arg7) {
    return BgCheck_CheckWallImpl(colCtx, 2, posResult, pos, arg3, radius, arg5, arg6, 0, arg7, 0);
}
