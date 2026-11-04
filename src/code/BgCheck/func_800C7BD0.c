// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 BgCheck_SphVsDynaWallInBgActor(CollisionContext* colCtx, u16 xpFlags, DynaCollisionContext* dyna, SSList* ssList,
                                   f32* outX, f32* outZ, CollisionPoly** outPoly, s32* outBgId, Vec3f* pos, f32 radius,
                                   s32 bgId, Actor* actor) {
    f32 temp;
    f32 intersect;
    s32 result = false;
    CollisionPoly* poly;
    SSNode* curNode;
    f32 nx;
    f32 ny;
    f32 nz;
    Vec3f resultPos;
    s16 polyId;
    f32 zTemp;
    f32 xTemp;
    f32 normalXZ;
    f32 invNormalXZ;
    f32 planeDist;
    f32 temp_f18;
    f32 zMin;
    f32 zMax;
    f32 xMin;
    f32 xMax;

    if (ssList->head == SS_NULL) {
        return result;
    }

    resultPos = *pos;
    curNode = &dyna->polyNodes.tbl[ssList->head];

    while (true) {
        polyId = curNode->polyId;
        poly = &dyna->polyList[polyId];
        CollisionPoly_GetNormalF(poly, &nx, &ny, &nz);
        normalXZ = sqrtf(SQ(nx) + SQ(nz));

        planeDist = Math3D_DistPlaneToPos(nx, ny, nz, poly->dist, &resultPos);
        if (radius < fabsf(planeDist) || COLPOLY_VTX_CHECK_FLAGS_ANY(poly->flags_vIA, xpFlags) ||
            (COLPOLY_VTX_CHECK_FLAGS_ANY(poly->flags_vIB, COLPOLY_VIB_FLAG_4) &&
             (((actor != NULL) && (actor->category != ACTORCAT_PLAYER)) ||
              ((actor == NULL) && (xpFlags != COLPOLY_IGNORE_CAMERA))))) {
            if (curNode->next == SS_NULL) {
                break;
            } else {
                curNode = &dyna->polyNodes.tbl[curNode->next];
                continue;
            }
        }
        invNormalXZ = 1.0f / normalXZ;
        temp_f18 = fabsf(nz) * invNormalXZ;
        if (temp_f18 < 0.4f) {
            if (curNode->next == SS_NULL) {
                break;
            } else {
                curNode = &dyna->polyNodes.tbl[curNode->next];
                continue;
            }
        }

        
        zTemp = dyna->vtxList[COLPOLY_VTX_INDEX(poly->flags_vIA)].z;
        zMax = zMin = zTemp;

        zTemp = dyna->vtxList[COLPOLY_VTX_INDEX(poly->flags_vIB)].z;
        if (zTemp < zMin) {
            zMin = zTemp;
        } else if (zTemp > zMax) {
            zMax = zTemp;
        }

        zTemp = dyna->vtxList[poly->vIC].z;
        if (zTemp < zMin) {
            zMin = zTemp;
        } else if (zMax < zTemp) {
            zMax = zTemp;
        }

        zMin -= radius;
        zMax += radius;
        if ((resultPos.z < zMin) || (zMax < resultPos.z)) {
            if (curNode->next == SS_NULL) {
                break;
            } else {
                curNode = &dyna->polyNodes.tbl[curNode->next];
                continue;
            }
        }
        if (CollisionPoly_CheckZIntersectApprox(poly, dyna->vtxList, resultPos.x, pos->y, &intersect)) {
            s32 pad;

            if (fabsf(intersect - resultPos.z) <= radius / temp_f18) {
                if ((intersect - resultPos.z) * nz <= 4.0f) {
                    if (BgCheck_ComputeWallDisplacement(colCtx, poly, &resultPos.x, &resultPos.z, nx, ny, nz,
                                                        invNormalXZ, planeDist, radius, outPoly)) {
                        *outBgId = bgId;
                    }
                    result = true;
                }
            }
        }
        if (curNode->next == SS_NULL) {
            break;
        }
        curNode = &dyna->polyNodes.tbl[curNode->next];
    }

    curNode = &dyna->polyNodes.tbl[ssList->head];
    while (true) {
        polyId = curNode->polyId;
        poly = &dyna->polyList[polyId];
        CollisionPoly_GetNormalF(poly, &nx, &ny, &nz);
        normalXZ = sqrtf(SQ(nx) + SQ(nz));

        planeDist = Math3D_DistPlaneToPos(nx, ny, nz, poly->dist, &resultPos);
        if (radius < fabsf(planeDist) || COLPOLY_VTX_CHECK_FLAGS_ANY(poly->flags_vIA, xpFlags) ||
            (COLPOLY_VTX_CHECK_FLAGS_ANY(poly->flags_vIB, COLPOLY_VIB_FLAG_4) &&
             (((actor != NULL) && (actor->category != ACTORCAT_PLAYER)) ||
              ((actor == NULL) && (xpFlags != COLPOLY_IGNORE_CAMERA))))) {
            if (curNode->next == SS_NULL) {
                break;
            } else {
                curNode = &dyna->polyNodes.tbl[curNode->next];
                continue;
            }
        }

        invNormalXZ = 1.0f / normalXZ;
        temp_f18 = fabsf(nx) * invNormalXZ;
        if (temp_f18 < 0.4f) {
            if (curNode->next == SS_NULL) {
                break;
            } else {
                curNode = &dyna->polyNodes.tbl[curNode->next];
                continue;
            }
        }

        
        xTemp = dyna->vtxList[COLPOLY_VTX_INDEX(poly->flags_vIA)].x;
        xMax = xMin = xTemp;
        xTemp = dyna->vtxList[COLPOLY_VTX_INDEX(poly->flags_vIB)].x;

        if (xTemp < xMin) {
            xMin = xTemp;
        } else if (xMax < xTemp) {
            xMax = xTemp;
        }
        xTemp = dyna->vtxList[poly->vIC].x;
        if (xTemp < xMin) {
            xMin = xTemp;
        } else if (xMax < xTemp) {
            xMax = xTemp;
        }

        xMin -= radius;
        xMax += radius;
        if ((resultPos.x < xMin) || (xMax < resultPos.x)) {
            if (curNode->next == SS_NULL) {
                break;
            } else {
                curNode = &dyna->polyNodes.tbl[curNode->next];
                continue;
            }
        }

        if (CollisionPoly_CheckXIntersectApprox(poly, dyna->vtxList, pos->y, resultPos.z, &intersect)) {
            f32 xIntersectDist = intersect - resultPos.x;

            if (fabsf(xIntersectDist) <= radius / temp_f18) {
                if (xIntersectDist * nx <= 4.0f) {
                    if (BgCheck_ComputeWallDisplacement(colCtx, poly, &resultPos.x, &resultPos.z, nx, ny, nz,
                                                        invNormalXZ, planeDist, radius, outPoly)) {
                        *outBgId = bgId;
                    }
                    result = true;
                }
            }
        }
        if (curNode->next == SS_NULL) {
            break;
        }
        curNode = &dyna->polyNodes.tbl[curNode->next];
    }
    *outX = resultPos.x;
    *outZ = resultPos.z;
    return result;
}
