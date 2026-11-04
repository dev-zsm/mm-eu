// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

s32 CollisionCheck_LineOC_Sphere(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* col, Vec3f* a,
                                 Vec3f* b) {
    ColliderSphere* sph = (ColliderSphere*)col;

    if (!(sph->elem.ocElemFlags & OCELEM_ON)) {
        return false;
    }

    ref_D_801EDFC8.a = *a;
    ref_D_801EDFC8.b = *b;
    if (Math3D_LineVsSph(&sph->dim.worldSphere, &ref_D_801EDFC8)) {
        return true;
    }

    return false;
}
