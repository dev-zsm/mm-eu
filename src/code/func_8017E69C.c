#include "types.h"

typedef struct {
    s16 pad0[3];
    s16 radius;
} Sphere;

extern f32 func_8017B9F0(Sphere *sph);

s32 Math3D_PointInSph(Sphere *sph) {
    if (func_8017B9F0(sph) < (f32)sph->radius) {
        return 1;
    }
    return 0;
}
