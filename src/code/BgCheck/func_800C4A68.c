#include "types.h"
#include "code_funcs.h"


s32 BgCheck_EntitySphVsWall2(void *colCtx, void *posResult, void *pos, s32 arg3, f32 radius, s32 arg5, s32 arg6, f32 arg7) {
    return BgCheck_CheckWallImpl(colCtx, 2, posResult, pos, arg3, radius, arg5, arg6, 0, arg7, 0);
}
