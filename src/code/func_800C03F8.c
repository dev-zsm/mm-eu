// FLAGS: -O2 -g3 -mips2
#include "types.h"

void CollisionPoly_CheckYIntersectApprox1(s32, s32, f32, f32, s32, f32);

void CollisionPoly_CheckYIntersectApprox2(s32 arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    CollisionPoly_CheckYIntersectApprox1(arg0, arg1, arg2, arg3, arg4, 1.0f);
}
