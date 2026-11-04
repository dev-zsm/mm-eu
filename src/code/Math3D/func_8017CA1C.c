// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

f32 Math3D_PlaneF(f32 nx, f32 ny, f32 nz, f32 originDist, Vec3f* pointOnPlane) {
    return (nx * pointOnPlane->x) + (ny * pointOnPlane->y) + (nz * pointOnPlane->z) + originDist;
}
