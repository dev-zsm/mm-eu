// FLAGS: -O2 -g3 -mips2
#include "types.h"

float fabsf(float);
#pragma intrinsic (fabsf)

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    Vec3f normal;
    f32 originDist;
} Plane;

s32 Math3D_TriChkPointParaYImpl(Vec3f *v0, Vec3f *v1, Vec3f *v2, Vec3f *point, f32 radius, f32 unk, f32 ySpan,
                                f32 normalY);
extern f32 D_801D79FC;

s32 Math3D_TriChkPointParaYDist(Vec3f *v0, Vec3f *v1, Vec3f *v2, Plane *plane, Vec3f *point, f32 radius,
                                f32 ySpan) {
    if (fabsf(plane->normal.y) < D_801D79FC) {
        return 0;
    }
    if (Math3D_TriChkPointParaYImpl(v0, v1, v2, point, radius, 0.0f, ySpan, plane->normal.y)) {
        return 1;
    }
    return 0;
}
