// FLAGS: -O2 -g3 -mips2
#include "types.h"

void Math3D_FindPointOnPlaneIntersect(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 *arg7, f32 *arg8) {
    *arg7 = ((arg1 * arg6) - (arg3 * arg5)) / arg4;
    *arg8 = ((arg2 * arg5) - (arg0 * arg6)) / arg4;
}
