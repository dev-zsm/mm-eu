// FLAGS: -O2 -g3 -mips2
#include "types.h"

f32 Math_Atan2S_XY(f32, f32);

void Math_Vec3f_Yaw(f32 *arg0, f32 *arg1) {
    f32 dx;

    dx = arg1[0] - arg0[0];
    Math_Atan2S_XY(arg1[2] - arg0[2], dx);
}
