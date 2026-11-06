// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_spidertent.h"

bool ref_func_80B2FC98(TriNorm* triNorm, Vec3f* arg1) {
    Vec3f sp84;
    Vec3f sp78;
    Vec3f* vtx;
    Vec3f* vtx2;
    Vec3f sp4C[3];
    s32 i;

    if (triNorm->plane.normal.x > 0.5f) {
        vtx = &triNorm->vtx[0];
        vtx2 = &triNorm->vtx[2];

        for (i = 0; i < ARRAY_COUNT(sp4C); i++, vtx = &triNorm->vtx[i]) {
            sp84.x = 0.0f;
            sp84.y = vtx->y - arg1->y;
            sp84.z = vtx->z - arg1->z;

            sp78.x = 0.0f;
            sp78.y = vtx2->y - arg1->y;
            sp78.z = vtx2->z - arg1->z;

            Math3D_Vec3f_Cross(&sp84, &sp78, &sp4C[i]);

            vtx2 = vtx;
        }

        return ((sp4C[0].x >= 0.0f) && (sp4C[1].x >= 0.0f) && (sp4C[2].x >= 0.0f)) ||
               ((sp4C[0].x < 0.0f) && (sp4C[1].x < 0.0f) && (sp4C[2].x < 0.0f));
    } else if (triNorm->plane.normal.y > 0.5f) {
        vtx = &triNorm->vtx[0];
        vtx2 = &triNorm->vtx[2];

        for (i = 0; i < ARRAY_COUNT(sp4C); i++, vtx = &triNorm->vtx[i]) {
            sp84.x = vtx->x - arg1->x;
            sp84.y = 0.0f;
            sp84.z = vtx->z - arg1->z;

            sp78.x = vtx2->x - arg1->x;
            sp78.y = 0.0f;
            sp78.z = vtx2->z - arg1->z;

            Math3D_Vec3f_Cross(&sp84, &sp78, &sp4C[i]);

            vtx2 = vtx;
        }

        return ((sp4C[0].y >= 0.0f) && (sp4C[1].y >= 0.0f) && (sp4C[2].y >= 0.0f)) ||
               ((sp4C[0].y < 0.0f) && (sp4C[1].y < 0.0f) && (sp4C[2].y < 0.0f));
    } else {
        vtx = &triNorm->vtx[0];
        vtx2 = &triNorm->vtx[2];

        for (i = 0; i < ARRAY_COUNT(sp4C); i++, vtx = &triNorm->vtx[i]) {
            sp84.x = vtx->x - arg1->x;
            sp84.y = vtx->y - arg1->y;
            sp84.z = 0.0f;

            sp78.x = vtx2->x - arg1->x;
            sp78.y = vtx2->y - arg1->y;
            sp78.z = 0.0f;

            Math3D_Vec3f_Cross(&sp84, &sp78, &sp4C[i]);

            vtx2 = vtx;
        }

        return ((sp4C[0].z >= 0.0f) && (sp4C[1].z >= 0.0f) && (sp4C[2].z >= 0.0f)) ||
               ((sp4C[0].z < 0.0f) && (sp4C[1].z < 0.0f) && (sp4C[2].z < 0.0f));
    }
}
