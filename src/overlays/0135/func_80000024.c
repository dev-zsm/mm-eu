// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

f32 func_80000024(f32 *a, f32 *b) {
    f32 x = a[0] - b[0];
    f32 z = a[2] - b[2];
    return x * x + z * z;
}
