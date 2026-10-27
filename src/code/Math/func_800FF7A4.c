#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;

f32 Math_Vec3f_DistXZAndStore(Vec3f *, Vec3f *, f32 *, f32 *);

f32 Math_Vec3f_StepToXZ(Vec3f *dest, Vec3f *start, f32 speed) {
    f32 dx;
    f32 dz;
    f32 dist;
    f32 step;

    dist = Math_Vec3f_DistXZAndStore(start, dest, &dx, &dz);
    step = dist - speed;
    if (dist < speed) {
        step = 0.0f;
    }
    if (step == 0.0f) {
        dist = 0.0f;
    } else {
        dist = step / dist;
    }
    dest->x = start->x + dx * dist;
    dest->z = start->z + dz * dist;
    return step;
}
