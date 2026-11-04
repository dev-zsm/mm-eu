// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_TriChkPointParaZIntersect(Vec3f* v0, Vec3f* v1, Vec3f* v2, f32 nx, f32 ny, f32 nz, f32 originDist, f32 x,
                                     f32 y, f32* zIntersect) {
    if (IS_ZERO(nz)) {
        return false;
    }

    if (Math3D_TriChkPointParaZImpl(v0, v1, v2, x, y, 300.0f, 1.0f, nz)) {
        *zIntersect = (((-nx * x) - (ny * y)) - originDist) / nz;
        return true;
    }

    return false;
}
