#include "types.h"
#include "code_funcs.h"


void BgCheck_EntityRaycastFloor2(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp34;

    BgCheck_RaycastFloorImpl(arg0, arg1, 2, arg2, &sp34, arg3, 0, 0x1C, 1.0f, 0);
}
