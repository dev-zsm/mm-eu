#include "types.h"
float sqrtf(float);
#pragma intrinsic (sqrtf)
extern f32 Math3D_Vec3fMagnitudeSq();
f32 Math3D_Vec3fMagnitude(void) {
    return sqrtf(Math3D_Vec3fMagnitudeSq());
}
