// FLAGS: -O2 -g0 -mips2
#include "libm.h"

f32 fmodf(f32 x, f32 y) {
    if (y == 0.0f) {
        return 0.0f;
    }
    return x - ((f32)(s32)(x / y) * y);
}
