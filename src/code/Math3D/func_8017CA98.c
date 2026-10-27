// FLAGS: -O2 -g3 -mips2
#include "types.h"

f32 Math3D_DistPlaneToPos(f32 a, f32 b, f32 c, f32 d, void *pos);
float fabsf(float);
#pragma intrinsic (fabsf)

f32 Math3D_UDistPlaneToPos(f32 a, f32 b, f32 c, f32 d, void *pos) {
    return fabsf(Math3D_DistPlaneToPos(a, b, c, d, pos));
}
