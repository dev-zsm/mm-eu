#include "types.h"
typedef struct { s16 radius; s16 height; s16 yShift; s16 x; s16 y; s16 z; } Cyl;
typedef struct { f32 x; f32 y; f32 z; } V;
s32 Math3D_PointInCyl(Cyl *a0, V *a1) {
    f32 dx = a0->x - a1->x;
    f32 dz = a0->z - a1->z;
    f32 yb = (f32)a0->y + (f32)a0->yShift;
    f32 top = (f32)a0->height + yb;
    if (dx * dx + dz * dz < a0->radius * a0->radius) {
        if (yb < a1->y && a1->y < top) {
            return 1;
        }
    }
    return 0;
}
