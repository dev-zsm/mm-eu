// FLAGS: -O2 -g3 -mips2
#include "types.h"

void Math_Vec3f_Lerp(f32 *arg0, f32 *arg1, f32 arg2, f32 *arg3) {
    arg3[0] = arg0[0] + (arg1[0] - arg0[0]) * arg2;
    arg3[1] = arg0[1] + (arg1[1] - arg0[1]) * arg2;
    arg3[2] = arg0[2] + (arg1[2] - arg0[2]) * arg2;
}
