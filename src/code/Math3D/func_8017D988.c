// FLAGS: -O2 -g3 -mips2
#include "types.h"

float fabsf(float);
#pragma intrinsic (fabsf)

typedef struct {
    f32 x, y, z;
} Vec3f;

s32 Math3D_TriChkPointParaXImpl(Vec3f *v0, Vec3f *v1, Vec3f *v2, Vec3f *point, f32 radius, f32 maxDist,
                                f32 scale, f32 normalX);
extern f32 D_801D7A08;

s32 Math3D_TriChkPointParaX(Vec3f *v0, Vec3f *v1, Vec3f *v2, f32 normalX, Vec3f *point, f32 radius) {
    if (fabsf(normalX) < D_801D7A08) {
        return 0;
    }
    if (Math3D_TriChkPointParaXImpl(v0, v1, v2, point, radius, 300.0f, 1.0f, normalX)) {
        return 1;
    }
    return 0;
}
