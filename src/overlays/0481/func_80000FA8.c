// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
f32 func_80000FA8(f32 *a0, f32 *a1, f32 *a2) {
    f32 a0x = a0[0];
    f32 a0z = a0[2];
    f32 a = a2[0] - a1[0];
    f32 b = a2[2] - a1[2];
    return a0z * a - a0x * b;
}
