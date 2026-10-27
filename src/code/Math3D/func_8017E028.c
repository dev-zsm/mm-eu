#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

extern s32 Math3D_TriChkPointParaZImpl(Vec3f *, Vec3f *, Vec3f *, f32, f32, f32, f32, f32);
float fabsf(float);
#pragma intrinsic (fabsf)

s32 Math3D_TriChkPointParaZ(Vec3f *v0, Vec3f *v1, Vec3f *v2, f32 nz, f32 x, f32 y) {
    if (fabsf(nz) < 0.008f) {
        return 0;
    }
    if (Math3D_TriChkPointParaZImpl(v0, v1, v2, x, y, 300.0f, 1.0f, nz)) {
        return 1;
    } else {
        return 0;
    }
}
