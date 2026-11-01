// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern f32 Math3D_Dist1DSq();
float sqrtf(float);
#pragma intrinsic (sqrtf)

f32 Math3D_Dist1D(void) {
    return sqrtf(Math3D_Dist1DSq());
}
