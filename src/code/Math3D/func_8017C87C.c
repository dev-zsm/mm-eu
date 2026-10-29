// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

f32 Math_CosS(s16);
f32 Math_SinS(s16);
extern f32 D_801D79D8;
extern f32 D_801D79DC;
void func_8017C87C(f32 *a0, s16 a1, f32 *a2, f32 *a3, f32 *a4) {
    f32 new_var;
    f32 t;
    *a2 = Math_SinS(a1) * D_801D79D8;
    t = Math_CosS(a1) * D_801D79DC;
    *a3 = t;
    *a4 = -(((*a2) * a0[0]) + (a0[2] * (new_var = t)));
}
