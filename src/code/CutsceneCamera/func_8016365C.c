// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

void func_8016365C(f32 t, f32 *dest) {
    f32 u = 1.0f - t;

    dest[0] = u * u * 0.5f;
    dest[1] = t * u + 0.5f;
    dest[2] = t * t * 0.5f;
}
