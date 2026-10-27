#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

extern f32 D_801D79F4;
s32 Math3D_TriChkPointParaYImpl(Vec3f *v0, Vec3f *v1, Vec3f *v2, f32 z, f32 x, f32 a, f32 b, f32 ny);
float fabsf(float);
#pragma intrinsic (fabsf)

s32 Math3D_TriChkPointParaY(Vec3f *v0, Vec3f *v1, Vec3f *v2, f32 ny, f32 z, f32 x) {
    if (fabsf(ny) < D_801D79F4) {
        return 0;
    }
    if (Math3D_TriChkPointParaYImpl(v0, v1, v2, z, x, 300.0f, 1.0f, ny)) {
        return 1;
    }
    return 0;
}
