#include "types.h"

extern f32 BgCheck_RaycastFloorImpl(void *play, void *colCtx, s32 xpFlags, void *arg3, void *arg4, void *arg5,
                                    void *arg6, s32 arg7, f32 arg8, s32 arg9);

f32 BgCheck_EntityRaycastFloor5_3(void *play, void *colCtx, void *arg2, void *arg3, void *arg4, void *arg5) {
    return BgCheck_RaycastFloorImpl(play, colCtx, 2, arg2, arg3, arg5, arg4, 60, 1.0f, 0);
}
