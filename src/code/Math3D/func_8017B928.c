#include "types.h"
#include "generated/code_funcs.h"
float sqrtf(float);
#pragma intrinsic (sqrtf)
f32 Math3D_Dist2D(f32 a0, f32 a1, f32 a2, f32 a3) {
    f32 r = Math3D_Dist2DSq(a0, a1, a2, a3);
    return sqrtf(r);
}
