// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_last_bwall.h"

void BgLastBwall_InitCollider(ColliderTrisInit* init, Vec3f* pos, Vec3s* rot, ColliderTris* collider,
                              BgLastBwallInitColliderStruct* arg4) {
    s32 i;
    s32 j;
    Vec3f sp6C[3];
    Vec3f sp60;
    Vec3f sp54;

    Matrix_RotateYS(rot->y, MTXMODE_NEW);
    Matrix_RotateXS(rot->x, MTXMODE_APPLY);
    Matrix_RotateZS(rot->z, MTXMODE_APPLY);
    for (i = 0; i < init->count; i++) {
        for (j = 0; j < 3; j++) {
            Math_Vec3s_ToVec3f(&sp60, &arg4->posOffsets[arg4->indices[j]]);
            Matrix_MultVec3f(&sp60, &sp54);
            Math_Vec3f_Sum(&sp54, pos, &sp6C[j]);
        }

        arg4->indices += 3;
        Collider_SetTrisVertices(collider, i, &sp6C[0], &sp6C[1], &sp6C[2]);
    }
}
