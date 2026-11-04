// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_TriChkPointParaYIntersectDist(Vec3f* v0, Vec3f* v1, Vec3f* v2, f32 nx, f32 ny, f32 nz, f32 originDist, f32 z,
                                         f32 x, f32* yIntersect, f32 chkDist) {
    if (IS_ZERO(ny)) {
        return false;
    }

    if (Math3D_TriChkPointParaYImpl(v0, v1, v2, z, x, 300.0f, chkDist, ny)) {
        *yIntersect = (((-nx * x) - (nz * z)) - originDist) / ny;
        return true;
    }

    return false;
}
