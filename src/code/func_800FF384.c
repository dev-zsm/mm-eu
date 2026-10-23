#include "types.h"
void Math_Vec3f_ToVec3s(s16 *a0, f32 *a1) {
    f32 x = a1[0];
    f32 y = a1[1];
    f32 z = a1[2];
    a0[0] = x;
    a0[1] = y;
    a0[2] = z;
}
