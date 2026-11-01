#include "types.h"
#include "code_funcs.h"


s32 BgCheck_EntitySphVsWall4(void *colCtx, void *posResult, void *pos, s32 arg3, f32 radius, s32 arg5, s32 arg6, s32 arg7, f32 arg8) {
    return BgCheck_CheckWallImpl(colCtx, 2, posResult, pos, arg3, radius, arg5, arg6, arg7, arg8, 1);
}
