// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_spidertent.h"

s32 ref_func_80B2FB94(Vec3f* arg0, f32 arg1, TriNorm* triNorm, Vec3f* arg3, f32* arg4) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f16;
    Vec3f sp48;
    Vec3f sp3C;
    f32 temp_f2;
    f32 temp_f2_2;

    temp_f0 = triNorm->plane.normal.x * arg1;
    temp_f2 = triNorm->plane.normal.y * arg1;
    temp_f16 = triNorm->plane.normal.z * arg1;

    sp48.x = arg0->x + temp_f0;
    sp48.y = arg0->y + temp_f2;
    sp48.z = arg0->z + temp_f16;

    sp3C.x = arg0->x - temp_f0;
    sp3C.y = arg0->y - temp_f2;
    sp3C.z = arg0->z - temp_f16;

    if (Math3D_LineSegVsPlane(triNorm->plane.normal.x, triNorm->plane.normal.y, triNorm->plane.normal.z,
                              triNorm->plane.originDist, &sp48, &sp3C, arg3, 0)) {
        temp_f0_2 = Math3D_Vec3fDistSq(arg0, arg3);
        temp_f2_2 = SQ(arg1) - temp_f0_2;
        if (SQ(arg1) < temp_f0_2) {
            return false;
        }
        *arg4 = sqrtf(temp_f2_2);
        return true;
    }
    return false;
}
