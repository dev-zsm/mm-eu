#include "types.h"

extern s32 BgCheck_RaycastFloorImpl(s32 a0, s32 a1, s32 a2, s32 a3, s32 *result, s32 arg5, s32 arg6, s32 arg7, f32 arg8, s32 arg9);

s32 BgCheck_EntityRaycastFloor2_1(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 result;

    return BgCheck_RaycastFloorImpl(a0, a1, 2, a2, &result, a3, 0, 0x1C, 1.0f, 1);
}
