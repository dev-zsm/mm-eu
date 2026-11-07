// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_mir_ray.h"

void MirRay_ReflectedBeam(MirRay* this, PlayState* play, MirRayShieldReflection* reflection) {
    Player* player = GET_PLAYER(play);
    s32 i;
    f32 temp_f0;
    Vec3f vecB;
    Vec3f vecD;
    Vec3f sp118;
    Vec3f sp10C;
    Vec3f sp100;
    Vec3f intersection;
    f32 spE8[3];
    f32 normalVec[3];
    MtxF* shieldMtx = &player->shieldMf;

    spE8[0] = -(shieldMtx->xz * this->reflectRange) * this->reflectIntensity * 400.0f;
    spE8[1] = -(shieldMtx->yz * this->reflectRange) * this->reflectIntensity * 400.0f;
    spE8[2] = -(shieldMtx->zz * this->reflectRange) * this->reflectIntensity * 400.0f;

    vecB.x = shieldMtx->xw;
    vecB.y = shieldMtx->yw;
    vecB.z = shieldMtx->zw;

    vecD.x = spE8[0] + vecB.x;
    vecD.y = spE8[1] + vecB.y;
    vecD.z = spE8[2] + vecB.z;

    {
        Vec3f vecA;
        Vec3f vecC;

        vecA.x = vecB.x + (shieldMtx->xx * 300.0f);
        vecA.y = vecB.y + (shieldMtx->yx * 300.0f);
        vecA.z = vecB.z + (shieldMtx->zx * 300.0f);

        vecC.x = vecD.x + (shieldMtx->xx * 300.0f);
        vecC.y = vecD.y + (shieldMtx->yx * 300.0f);
        vecC.z = vecD.z + (shieldMtx->zx * 300.0f);

        Collider_SetQuadVertices(&this->collider2, &vecA, &vecB, &vecC, &vecD);

        for (i = 0; i < 6; i++) {
            if (reflection[i].reflectionPoly != NULL) {
                normalVec[0] = COLPOLY_GET_NORMAL(reflection[i].reflectionPoly->normal.x);
                normalVec[1] = COLPOLY_GET_NORMAL(reflection[i].reflectionPoly->normal.y);
                normalVec[2] = COLPOLY_GET_NORMAL(reflection[i].reflectionPoly->normal.z);

                if (Math3D_LineSegVsPlane(normalVec[0], normalVec[1], normalVec[2], reflection[i].reflectionPoly->dist,
                                          &vecB, &vecD, &sp118, 1)) {

                    reflection[i].pos.x = sp118.x;
                    reflection[i].pos.y = sp118.y;
                    reflection[i].pos.z = sp118.z;

                    temp_f0 = sqrtf(SQ(sp118.x - vecB.x) + SQ(sp118.y - vecB.y) + SQ(sp118.z - vecB.z));

                    if (temp_f0 < (this->reflectIntensity * 600.0f)) {
                        reflection[i].opacity = 200;
                    } else {
                        reflection[i].opacity = (s32)(800.0f - temp_f0);
                    }

                    reflection[i].opacity = (s32)(reflection[i].opacity * 1.275f);

                    sp10C.x = (shieldMtx->xx * 100.0f) + vecB.x;
                    sp10C.y = (shieldMtx->yx * 100.0f) + vecB.y;
                    sp10C.z = (shieldMtx->zx * 100.0f) + vecB.z;

                    sp100.x = (spE8[0] * 4.0f) + sp10C.x;
                    sp100.y = (spE8[1] * 4.0f) + sp10C.y;
                    sp100.z = (spE8[2] * 4.0f) + sp10C.z;

                    reflection[i].mtx.xx = reflection[i].mtx.yy = reflection[i].mtx.zz = reflection[i].mtx.ww = 1.0f;

                    reflection[i].mtx.yx = reflection[i].mtx.zx = reflection[i].mtx.wx = reflection[i].mtx.xy =
                        reflection[i].mtx.zy = reflection[i].mtx.wy = reflection[i].mtx.xz = reflection[i].mtx.yz =
                            reflection[i].mtx.wz = reflection[i].mtx.xw = reflection[i].mtx.yw = reflection[i].mtx.zw =
                                0.0f;

                    if (Math3D_LineSegVsPlane(normalVec[0], normalVec[1], normalVec[2],
                                              reflection[i].reflectionPoly->dist, &sp10C, &sp100, &intersection, 1)) {
                        reflection[i].mtx.xx = intersection.x - sp118.x;
                        reflection[i].mtx.yx = intersection.y - sp118.y;
                        reflection[i].mtx.zx = intersection.z - sp118.z;
                    }

                    sp10C.x = (shieldMtx->xy * 100.0f) + vecB.x;
                    sp10C.y = (shieldMtx->yy * 100.0f) + vecB.y;
                    sp10C.z = (shieldMtx->zy * 100.0f) + vecB.z;

                    sp100.x = (spE8[0] * 4.0f) + sp10C.x;
                    sp100.y = (spE8[1] * 4.0f) + sp10C.y;
                    sp100.z = (spE8[2] * 4.0f) + sp10C.z;

                    if (Math3D_LineSegVsPlane(normalVec[0], normalVec[1], normalVec[2],
                                              reflection[i].reflectionPoly->dist, &sp10C, &sp100, &intersection, 1)) {
                        reflection[i].mtx.xy = intersection.x - sp118.x;
                        reflection[i].mtx.yy = intersection.y - sp118.y;
                        reflection[i].mtx.zy = intersection.z - sp118.z;
                    }
                } else {
                    reflection[i].reflectionPoly = NULL;
                }
            }
        }
    }
}
