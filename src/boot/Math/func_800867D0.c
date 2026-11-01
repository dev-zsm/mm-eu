// FLAGS: -O2 -g0 -mips2
#include "sdk/libm.h"

f32 Math_FTanF(f32 x) {
    f32 sinx;

    sinx = __sinf(x);
    return sinx / __cosf(x);
}
