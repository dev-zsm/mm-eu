// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern f32 __sinf(f32 a0);
extern f32 __cosf(f32 a0);

f32 Math_FTanF(f32 arg0) {
    f32 sp1C;

    sp1C = __sinf(arg0);
    return sp1C / __cosf(arg0);
}

