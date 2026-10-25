#include "types.h"

s32 BgCheck_RaycastFloorImpl(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4, s32 arg5, s32 arg6, s32 arg7, f32 arg8, s32 arg9);

void BgCheck_EntityRaycastFloor2(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp34;

    BgCheck_RaycastFloorImpl(arg0, arg1, 2, arg2, &sp34, arg3, 0, 0x1C, 1.0f, 0);
}
