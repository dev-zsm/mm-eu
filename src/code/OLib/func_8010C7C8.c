#include "types.h"
typedef struct { f32 x, y, z; } V3;
typedef struct { f32 r; s16 pitch; s16 yaw; } Sph;
typedef struct { u8 pad0[0xE]; s16 unkE; } R;
extern void OLib_Vec3fDiffToVecGeo(Sph *, R *, V3 *, s16);
extern void OLib_VecGeoToVec3f(V3 *, Sph *);
void OLib_Vec3fDiff(R *a, V3 *b, V3 *dest, s16 mode) {
    Sph sp30;
    V3 *src = b; // match-only: local copy flips saved-register order
    switch (mode) {
        default:
            *dest = *src;
            break;
        case 1:
            OLib_Vec3fDiffToVecGeo(&sp30, a, b, mode);
            sp30.yaw -= a->unkE;
            OLib_VecGeoToVec3f(dest, &sp30);
            break;
        case 2:
            dest->x = b->x - ((V3 *)a)->x;
            dest->y = b->y - ((V3 *)a)->y;
            dest->z = b->z - ((V3 *)a)->z;
            break;
    }
}
