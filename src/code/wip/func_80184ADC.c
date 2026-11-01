#include "types.h"
float fabsf(float);
#pragma intrinsic (fabsf)

void Keyframe_MorphInterpolateRotation(f32 weight, s16 *out, s16 a, s16 b) {
    f32 sa = a;
    f32 sb = b;
    f32 ua = (u32)(u16)a;
    f32 ub = (u32)(u16)b;
    f32 diffS = sb - sa;
    f32 diffU = ub - ua;
    f32 absS = fabsf(diffS);

    if (absS < fabsf(diffU)) {
        *out = diffS * weight + sa;
    } else {
        *out = diffU * weight + ua;
    }
}
