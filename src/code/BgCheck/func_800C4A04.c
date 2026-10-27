#include "types.h"

extern void BgCheck_CheckWallImpl(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, s32 arg6, s32 *arg7, s32 arg8, f32 arg9, s32 arg10);

void BgCheck_EntitySphVsWall1(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5, f32 arg6) {
    s32 outValue;

    BgCheck_CheckWallImpl(arg0, 2, arg1, arg2, arg3, arg4, arg5, &outValue, 0, arg6, 0);
}
