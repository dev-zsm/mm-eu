// FLAGS: -O2 -g3 -mips2
#include "types.h"
void Math_Vec3f_Sum(f32 *a, f32 *b, f32 *c) {
    c[0] = b[0] + a[0];
    c[1] = b[1] + a[1];
    c[2] = b[2] + a[2];
}
