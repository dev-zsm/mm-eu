// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
// -Wab,-r4300_mul: the original has a nop after each mul.s (r4300 workaround).
#include "types.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 radius;
} Sphere16;

s32 Math3D_XYInSphere(Sphere16 *sphere, f32 x, f32 y) {
    f32 dx = sphere->x - x;
    f32 dy = sphere->y - y;

    if ((dx * dx) + (dy * dy) <= (f32)(sphere->radius * sphere->radius)) {
        return 1;
    }
    return 0;
}
