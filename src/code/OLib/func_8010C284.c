// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;
typedef struct {
    f32 r;
    s16 pitch;
    s16 yaw;
} Sph;
f32 Math_CosS(s16 a);
f32 Math_SinS(s16 a);
void OLib_VecSphToVec3f(Vec3f *dst, Sph *s) {
    Vec3f v;
    f32 cp;
    f32 sp;
    f32 pad;
    f32 sy;
    f32 syw;
    sp = Math_CosS(s->pitch);
    sy = Math_CosS(s->yaw);
    cp = Math_SinS(s->pitch);
    syw = Math_SinS(s->yaw);
    v.x = (s->r * cp) * syw;
    v.y = s->r * sp;
    if (!dst) {
    }
    v.z = (s->r * cp) * sy;
    *dst = v;
}
