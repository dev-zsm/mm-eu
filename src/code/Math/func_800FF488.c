// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

void Math_Vec3f_Scale(Vec3f *v, f32 scale) {
    v->x *= scale;
    v->y *= scale;
    v->z *= scale;
}
