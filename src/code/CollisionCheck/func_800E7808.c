// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

s32 CollisionCheck_LineOC_JntSph(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* col, Vec3f* a,
                                 Vec3f* b) {
    ColliderJntSph* jntSph = (ColliderJntSph*)col;
    s32 i;

    for (i = 0; i < jntSph->count; i++) {
        ColliderJntSphElement* jntSphElem = &jntSph->elements[i];

        if (!(jntSphElem->base.ocElemFlags & OCELEM_ON)) {
            continue;
        }

        ref_D_801EDEB0.a = *a;
        ref_D_801EDEB0.b = *b;
        if (Math3D_LineVsSph(&jntSphElem->dim.worldSphere, &ref_D_801EDEB0)) {
            return true;
        }
    }
    return false;
}
