// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
// -Wab,-r4300_mul: the ROM was built with the R4300 mul.s workaround (nop after mul.s)
#include "types.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 radius;
} Sphere16;

s32 Math3D_XZInSphere(Sphere16 *sphere, f32 x, f32 z) {
    f32 dx = sphere->x - x;
    f32 dz = sphere->z - z;

    if (dx * dx + dz * dz <= sphere->radius * sphere->radius) {
        return 1;
    }
    return 0;
}
