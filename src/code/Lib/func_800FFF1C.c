// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
f32 Math_CosS(s16);
f32 Math_SinS(s16);
void func_800FFF1C(f32 *a, s16 arg1, f32 *b, f32 *c) {
    f32 sp1C;
    f32 cs;
    sp1C = Math_CosS(arg1);
    cs = Math_SinS(arg1);
    c[0] = (b[0] * sp1C + b[2] * cs) + a[0]; c[1] = b[1] + a[1]; c[2] = (b[2] * sp1C - b[0] * cs) + a[2];
}
