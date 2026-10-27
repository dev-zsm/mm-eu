#include "types.h"
typedef struct { f32 x; f32 y; f32 z; } Vec3f;
extern void Math_Vec3f_Diff();
extern f32 Math3D_Vec3fMagnitudeSq();
f32 Math3D_Vec3fDistSq(void *a0, void *a1) {
    Vec3f d;
    Math_Vec3f_Diff(a0, a1, &d);
    return Math3D_Vec3fMagnitudeSq(&d);
}
