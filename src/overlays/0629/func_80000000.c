// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_astr_bombwall.h"

void BgAstrBombwall_InitCollider(ColliderTrisInit* init, Vec3f* pos, Vec3s* rot, ColliderTris* collider) {
    s32 i;
    s32 j;
    Vec3f sp54[3];

    Matrix_RotateYS(rot->y, MTXMODE_NEW);
    Matrix_RotateXS(rot->x, MTXMODE_APPLY);
    Matrix_RotateZS(rot->z, MTXMODE_APPLY);

    for (i = 0; i < init->count; i++) {
        for (j = 0; j < 3; j++) {
            Matrix_MultVec3f(init->elements[i].dim.vtx + j, &sp54[j]);
            Math_Vec3f_Sum(&sp54[j], pos, &sp54[j]);
        }
        Collider_SetTrisVertices(collider, i, &sp54[0], &sp54[1], &sp54[2]);
    }
}
