// FLAGS: -O2 -g3 -mips2
#include "types.h"

float sqrtf(float);
#pragma intrinsic (sqrtf)
float fabsf(float);
#pragma intrinsic (fabsf)

f32 Math3D_PlaneF(f32, f32, f32, f32, s32);
extern f32 D_801D79E4;

f32 Math3D_DistPlaneToPos(f32 nx, f32 ny, f32 nz, f32 originDist, struct Vec3f *p) {
    f32 len = sqrtf((nx * nx) + (ny * ny) + (nz * nz));

    if (fabsf(len) < D_801D79E4) {
        return 0.0f;
    }
    return Math3D_PlaneF(nx, ny, nz, originDist, p) / len;
}
