// FLAGS: -O2 -g3 -mips2
#include "types.h"

float sqrtf(float);
#pragma intrinsic (sqrtf)
float fabsf(float);
#pragma intrinsic (fabsf)

f32 Math3D_PlaneF(f32, f32, f32, f32, s32);
extern f32 D_801D79E4;

f32 Math3D_DistPlaneToPos(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    f32 len = sqrtf((arg0 * arg0) + (arg1 * arg1) + (arg2 * arg2));

    if (fabsf(len) < D_801D79E4) {
        return 0.0f;
    }
    return Math3D_PlaneF(arg0, arg1, arg2, arg3, arg4) / len;
}
