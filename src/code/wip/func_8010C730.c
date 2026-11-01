#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;
typedef struct { s16 x, y, z; } Vec3s;

extern f32 D_801D5B88;
extern f32 D_801D5B8C;
extern void OLib_Vec3fDiffRad(Vec3f *out, Vec3f *a, Vec3f *b);

Vec3s OLib_Vec3fDiffBinAng(Vec3f *a, Vec3f *b) {
    Vec3s ret;
    Vec3f diff;

    OLib_Vec3fDiffRad(&diff, a, b);
    ret.x = diff.x * D_801D5B88 * D_801D5B8C + 0.5f;
    ret.y = diff.y * D_801D5B88 * D_801D5B8C + 0.5f;
    ret.z = 0;
    return ret;
}
