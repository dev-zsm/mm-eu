// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

void Math3D_DefPlane(Vec3f* va, Vec3f* vb, Vec3f* vc, f32* nx, f32* ny, f32* nz, f32* originDist) {
    static Vec3f sNormal;
    f32 normMagnitude;
    f32 normMagInv;

    Math3D_SurfaceNorm(va, vb, vc, &sNormal);
    normMagnitude = sqrtf(SQ(sNormal.x) + SQ(sNormal.y) + SQ(sNormal.z));
    if (!IS_ZERO(normMagnitude)) {
        normMagInv = 1.0f / normMagnitude;
        *nx = sNormal.x * normMagInv;
        *ny = sNormal.y * normMagInv;
        *nz = sNormal.z * normMagInv;
        *originDist = -((*nx * va->x) + (*ny * va->y) + (*nz * va->z));
    } else {
        *originDist = 0.0f;
        *nz = 0.0f;
        *ny = 0.0f;
        *nx = 0.0f;
    }
}
