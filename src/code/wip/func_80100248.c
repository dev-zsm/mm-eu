#include "types.h"
typedef struct { f32 x, y, z; } Vec3f;
extern void Math_Vec3f_Diff(Vec3f *, Vec3f *, Vec3f *);
extern f32 Math3D_Vec3fMagnitude(Vec3f *);
extern void Math_Vec3f_Copy(Vec3f *, Vec3f *);

f32 func_80100248(Vec3f *a, Vec3f *b, f32 dist) {
    Vec3f diff;
    f32 len;
    f32 scale;
    f32 ret;

    Math_Vec3f_Diff(b, a, &diff);
    len = Math3D_Vec3fMagnitude(&diff);
    if (dist < len) {
        scale = dist / len;
        ret = len - dist;
        a->x += scale * diff.x;
        a->y += scale * diff.y;
        a->z += scale * diff.z;
    } else {
        Math_Vec3f_Copy(a, b);
        ret = 0.0f;
    }
    return ret;
}
