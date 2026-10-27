#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;
typedef struct {
    s32 r;
    s16 pitch;
    s16 yaw;
} VecSph;
extern void OLib_Vec3fToVecSph(VecSph *dest, Vec3f *vec);
void OLib_Vec3fToVecGeo(VecSph *dest, Vec3f *vec) {
    VecSph sph;
    OLib_Vec3fToVecSph(&sph, vec);
    sph.pitch = 0x4000 - sph.pitch;
    if (dest) {
    }
    *dest = sph;
}
