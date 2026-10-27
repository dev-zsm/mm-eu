#include "types.h"
typedef struct { f32 x, y, z; } Vec3f;
typedef struct { f32 r; s16 pitch; s16 yaw; } VecGeo;
typedef struct { f32 x, y, z; s16 pad; s16 unkE; } Ref;
extern void OLib_Vec3fToVecGeo(VecGeo *geo, Vec3f *vec);
extern void OLib_AddVecGeoToVec3f(Vec3f *dest, Vec3f *a, VecGeo *geo);
void OLib_Vec3fAdd(Ref *a, Vec3f *b, Vec3f *dest, s16 mode) {
    VecGeo geo; s32 pad;
    switch (mode) {
        default:
            *dest = *b;
            break;
        case 1:
            OLib_Vec3fToVecGeo(&geo, b);
            geo.yaw += a->unkE;
            OLib_AddVecGeoToVec3f(dest, (Vec3f *)a, &geo);
            break;
        case 2:
            dest->x = a->x + b->x;
            dest->y = a->y + b->y;
            dest->z = a->z + b->z;
            break;
    }
}
