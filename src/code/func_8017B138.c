// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern void Math3D_CosOut(s32 a0, s32 a1, f32 *p);
f32 Math3D_Cos(s32 a0, s32 a1) {
    f32 r;
    Math3D_CosOut(a0, a1, &r);
    return r;
}
