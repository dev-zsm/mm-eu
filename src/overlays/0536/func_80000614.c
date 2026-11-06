// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_mir_ray3.h"

void ref_func_80B9E8D4(MirRay3* this, PlayState* play, MirRay3Struct* ptr) {
    Player* player = GET_PLAYER(play);
    s32 i;
    MtxF* shieldMf = &player->shieldMf;
    Vec3f sp140;
    Vec3f sp134;
    Vec3f sp128;
    Vec3f sp11C;
    Vec3f sp110;
    Vec3f sp104;
    f32 spF8[3];
    f32 spEC[3];
    f32 temp_f0;
    f32 temp_f26;
    f32 temp_f2;
    Vec3f spD4;
    Vec3f spC8;

    spF8[0] = -(shieldMf->mf[2][0] * this->unk_260) * this->unk_214 * 400.0f;
    spF8[1] = -(shieldMf->mf[2][1] * this->unk_260) * this->unk_214 * 400.0f;
    spF8[2] = -(shieldMf->mf[2][2] * this->unk_260) * this->unk_214 * 400.0f;

    sp140.x = shieldMf->mf[3][0];
    sp140.y = shieldMf->mf[3][1];
    sp140.z = shieldMf->mf[3][2];

    sp134.x = spF8[0] + sp140.x;
    sp134.y = spF8[1] + sp140.y;
    sp134.z = spF8[2] + sp140.z;

    temp_f26 = this->unk_214 * 400.0f;

    for (i = 0; i < ARRAY_COUNT(this->unk_218); i++) {
        if (ptr[i].unk_4C != NULL) {
            spEC[0] = COLPOLY_GET_NORMAL(ptr[i].unk_4C->normal.x);
            spEC[1] = COLPOLY_GET_NORMAL(ptr[i].unk_4C->normal.y);
            spEC[2] = COLPOLY_GET_NORMAL(ptr[i].unk_4C->normal.z);

            if (Math3D_LineSegVsPlane(spEC[0], spEC[1], spEC[2], ptr[i].unk_4C->dist, &sp140, &sp134, &sp128, true)) {
                ptr[i].unk_00.x = sp128.x;
                ptr[i].unk_00.y = sp128.y;
                ptr[i].unk_00.z = sp128.z;

                temp_f0 = sqrtf(SQ(sp128.x - sp140.x) + SQ(sp128.y - sp140.y) + SQ(sp128.z - sp140.z));

                if (temp_f0 < (temp_f26 * 0.9f)) {
                    ptr[i].unk_50 = 0xFF;
                } else if (temp_f26 < temp_f0) {
                    ptr[i].unk_50 = 0;
                } else {
                    ptr[i].unk_50 = (s32)((10.0f - ((10.0f / temp_f26) * temp_f0)) * 255.0f);
                }

                sp11C.x = (shieldMf->mf[0][0] * 100.0f) + sp140.x;
                sp11C.y = (shieldMf->mf[0][1] * 100.0f) + sp140.y;
                sp11C.z = (shieldMf->mf[0][2] * 100.0f) + sp140.z;

                sp110.x = (spF8[0] * 4.0f) + sp11C.x;
                sp110.y = (spF8[1] * 4.0f) + sp11C.y;
                sp110.z = (spF8[2] * 4.0f) + sp11C.z;

                ptr[i].unk_0C.mf[0][0] = ptr[i].unk_0C.mf[1][1] = ptr[i].unk_0C.mf[2][2] = ptr[i].unk_0C.mf[3][3] =
                    1.0f;

                ptr[i].unk_0C.mf[0][1] = ptr[i].unk_0C.mf[0][2] = ptr[i].unk_0C.mf[0][3] = ptr[i].unk_0C.mf[1][0] =
                    ptr[i].unk_0C.mf[1][2] = ptr[i].unk_0C.mf[1][3] = ptr[i].unk_0C.mf[2][0] = ptr[i].unk_0C.mf[2][1] =
                        ptr[i].unk_0C.mf[2][3] = ptr[i].unk_0C.mf[3][0] = ptr[i].unk_0C.mf[3][1] =
                            ptr[i].unk_0C.mf[3][2] = 0.0f;

                if (Math3D_LineSegVsPlane(spEC[0], spEC[1], spEC[2], ptr[i].unk_4C->dist, &sp11C, &sp110, &sp104,
                                          true)) {
                    ptr[i].unk_0C.mf[0][0] = sp104.x - sp128.x;
                    ptr[i].unk_0C.mf[0][1] = sp104.y - sp128.y;
                    ptr[i].unk_0C.mf[0][2] = sp104.z - sp128.z;
                }

                sp11C.x = (shieldMf->mf[1][0] * 100.0f) + sp140.x;
                sp11C.y = (shieldMf->mf[1][1] * 100.0f) + sp140.y;
                sp11C.z = (shieldMf->mf[1][2] * 100.0f) + sp140.z;

                sp110.x = (spF8[0] * 4.0f) + sp11C.x;
                sp110.y = (spF8[1] * 4.0f) + sp11C.y;
                sp110.z = (spF8[2] * 4.0f) + sp11C.z;

                if (Math3D_LineSegVsPlane(spEC[0], spEC[1], spEC[2], ptr[i].unk_4C->dist, &sp11C, &sp110, &sp104,
                                          true)) {
                    ptr[i].unk_0C.mf[1][0] = sp104.x - sp128.x;
                    ptr[i].unk_0C.mf[1][1] = sp104.y - sp128.y;
                    ptr[i].unk_0C.mf[1][2] = sp104.z - sp128.z;
                }
            } else {
                ptr[i].unk_4C = NULL;
            }
        }
    }

    temp_f2 = this->unk_214 * 400.0f;

    spF8[0] = -(this->unk_260 * shieldMf->mf[2][0]);
    spF8[1] = -(this->unk_260 * shieldMf->mf[2][1]);
    spF8[2] = -(this->unk_260 * shieldMf->mf[2][2]);

    sp134.x = (spF8[0] * temp_f2) + sp140.x;
    sp134.y = (spF8[1] * temp_f2) + sp140.y;
    sp134.z = (spF8[2] * temp_f2) + sp140.z;

    {
        CollisionPoly* spC4;

        if (!BgCheck_AnyLineTest1(&play->colCtx, &sp140, &sp134, &sp128, &spC4, true)) {
            Math_Vec3f_Copy(&sp128, &sp134);
        }

        sp128.x += spF8[0] * 5.0f;
        sp128.y += spF8[1] * 5.0f;
        sp128.z += spF8[2] * 5.0f;

        spD4.x = (shieldMf->mf[0][0] * 300.0f) + sp140.x;
        spD4.y = (shieldMf->mf[0][1] * 300.0f) + sp140.y;
        spD4.z = (shieldMf->mf[0][2] * 300.0f) + sp140.z;

        spC8.x = (shieldMf->mf[0][0] * 300.0f) + sp128.x;
        spC8.y = (shieldMf->mf[0][1] * 300.0f) + sp128.y;
        spC8.z = (shieldMf->mf[0][2] * 300.0f) + sp128.z;

        Collider_SetQuadVertices(&this->colliderQuad, &spD4, &sp140, &spC8, &sp128);
    }
}
