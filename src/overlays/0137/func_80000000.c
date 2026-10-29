// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

f32 func_80000000(f32 *a, f32 *b) {
    f32 dx = a[0] - b[0];
    f32 dz = a[2] - b[2];

    return dx * dx + dz * dz;
}
