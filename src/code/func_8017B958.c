// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
f32 Math3D_Vec3fMagnitudeSq(f32 *v) {
    f32 x = v[0];
    f32 y = v[1];
    f32 z = v[2];
    return x * x + y * y + z * z;
}
