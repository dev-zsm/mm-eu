// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 BgCheck_SphVsStaticWall(StaticLookup* lookup, CollisionContext* colCtx, u16 xpFlags, f32* outX, f32* outZ,
                            Vec3f* pos, f32 radius, CollisionPoly** outPoly, Actor* actor) {
    Vec3f resultPos;
    f32 zTemp;
    f32 xTemp;
    f32 planeDist;
    f32 intersect;
    s32 result;
    CollisionPoly* curPoly;
    CollisionPoly* polyList;
    SSNode* curNode;
    f32 invNormalXZ;
    Vec3s* vtxA;
    Vec3s* vtxB;
    Vec3s* vtxC;
    s32 polyId;
    f32 normalXZ;
    f32 nx;
    f32 ny;
    f32 nz;
    Vec3s* vtxList;
    u16 pad;
    f32 temp_f16;
    f32 zMin;
    f32 zMax;
    f32 xMin;
    f32 xMax;

    result = false;
    if (lookup->wall.head == SS_NULL) {
        return result;
    }
    resultPos = *pos;

    polyList = colCtx->colHeader->polyList;
    vtxList = colCtx->colHeader->vtxList;
    curNode = &colCtx->polyNodes.tbl[lookup->wall.head];

    while (true) {
        polyId = curNode->polyId;
        curPoly = &polyList[polyId];
        vtxA = &vtxList[COLPOLY_VTX_INDEX(curPoly->flags_vIA)];
        vtxB = &vtxList[COLPOLY_VTX_INDEX(curPoly->flags_vIB)];
        vtxC = &vtxList[curPoly->vIC];

        if ((pos->y < vtxA->y) && (pos->y < vtxB->y) && (pos->y < vtxC->y)) {
            break;
        }

        nx = COLPOLY_GET_NORMAL(curPoly->normal.x);
        ny = COLPOLY_GET_NORMAL(curPoly->normal.y);
        nz = COLPOLY_GET_NORMAL(curPoly->normal.z);
        normalXZ = sqrtf(SQ(nx) + SQ(nz));
        planeDist = Math3D_DistPlaneToPos(nx, ny, nz, curPoly->dist, &resultPos);
        if (radius < fabsf(planeDist) || COLPOLY_VTX_CHECK_FLAGS_ANY(curPoly->flags_vIA, xpFlags) ||
            (COLPOLY_VTX_CHECK_FLAGS_ANY(curPoly->flags_vIB, COLPOLY_VIB_FLAG_4) &&
             (((actor != NULL) && (actor->category != ACTORCAT_PLAYER)) ||
              ((actor == NULL) && (xpFlags != COLPOLY_IGNORE_CAMERA))))) {
            if (curNode->next == SS_NULL) {
                break;
            } else {
                curNode = &colCtx->polyNodes.tbl[curNode->next];
                continue;
            }
        }

        invNormalXZ = 1.0f / normalXZ;
        temp_f16 = fabsf(nz) * invNormalXZ;
        if (temp_f16 < 0.4f) {
            if (curNode->next == SS_NULL) {
                break;
            } else {
                curNode = &colCtx->polyNodes.tbl[curNode->next];
                continue;
            }
        }

        
        zTemp = vtxA->z;
        zMax = zMin = zTemp;
        zTemp = vtxB->z;

        if (zTemp < zMin) {
            zMin = zTemp;
        } else if (zMax < zTemp) {
            zMax = zTemp;
        }
        zTemp = vtxC->z;
        if (zTemp < zMin) {
            zMin = zTemp;
        } else if (zTemp > zMax) {
            zMax = zTemp;
        }

        zMin -= radius;
        zMax += radius;

        if ((resultPos.z < zMin) || (resultPos.z > zMax)) {
            if (curNode->next == SS_NULL) {
                break;
            } else {
                curNode = &colCtx->polyNodes.tbl[curNode->next];
                continue;
            }
        }
        if (CollisionPoly_CheckZIntersectApprox(curPoly, vtxList, resultPos.x, pos->y, &intersect)) {
            f32 test = intersect - resultPos.z;

            if (fabsf(test) <= radius / temp_f16) {
                if (test * nz <= 4.0f) {
                    if (BgCheck_ComputeWallDisplacement(colCtx, curPoly, &resultPos.x, &resultPos.z, nx, ny, nz,
                                                        invNormalXZ, planeDist, radius, outPoly)) {
                        result = true;
                    }
                }
            }
        }
        if (curNode->next == SS_NULL) {
            break;
        } else {
            curNode = &colCtx->polyNodes.tbl[curNode->next];
        }
    }

    curNode = &colCtx->polyNodes.tbl[lookup->wall.head];

    while (true) {
        polyId = curNode->polyId;
        curPoly = &polyList[polyId];
        vtxA = &vtxList[COLPOLY_VTX_INDEX(curPoly->flags_vIA)];
        vtxB = &vtxList[COLPOLY_VTX_INDEX(curPoly->flags_vIB)];
        vtxC = &vtxList[curPoly->vIC];

        if ((pos->y < vtxA->y) && (pos->y < vtxB->y) && (pos->y < vtxC->y)) {
            break;
        }

        nx = COLPOLY_GET_NORMAL(curPoly->normal.x);
        ny = COLPOLY_GET_NORMAL(curPoly->normal.y);
        nz = COLPOLY_GET_NORMAL(curPoly->normal.z);
        normalXZ = sqrtf(SQ(nx) + SQ(nz));
        planeDist = Math3D_DistPlaneToPos(nx, ny, nz, curPoly->dist, &resultPos);
        if (radius < fabsf(planeDist) || COLPOLY_VTX_CHECK_FLAGS_ANY(curPoly->flags_vIA, xpFlags) ||
            (COLPOLY_VTX_CHECK_FLAGS_ANY(curPoly->flags_vIB, COLPOLY_VIB_FLAG_4) &&
             (((actor != NULL) && (actor->category != ACTORCAT_PLAYER)) ||
              ((actor == NULL) && (xpFlags != COLPOLY_IGNORE_CAMERA))))) {
            if (curNode->next == SS_NULL) {
                break;
            } else {
                curNode = &colCtx->polyNodes.tbl[curNode->next];
                continue;
            }
        }

        invNormalXZ = 1.0f / normalXZ;
        temp_f16 = fabsf(nx) * invNormalXZ;
        if (temp_f16 < 0.4f) {
            if (curNode->next == SS_NULL) {
                break;
            } else {
                curNode = &colCtx->polyNodes.tbl[curNode->next];
                continue;
            }
        }

        
        xTemp = vtxA->x;
        xMax = xMin = xTemp;
        xTemp = vtxB->x;

        if (xTemp < xMin) {
            xMin = xTemp;
        } else if (xMax < xTemp) {
            xMax = xTemp;
        }
        xTemp = vtxC->x;
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
                curNode = &colCtx->polyNodes.tbl[curNode->next];
                continue;
            }
        }
        if (CollisionPoly_CheckXIntersectApprox(curPoly, vtxList, pos->y, resultPos.z, &intersect)) {
            f32 test = intersect - resultPos.x;

            if (fabsf(test) <= radius / temp_f16) {
                if (test * nx <= 4.0f) {
                    if (BgCheck_ComputeWallDisplacement(colCtx, curPoly, &resultPos.x, &resultPos.z, nx, ny, nz,
                                                        invNormalXZ, planeDist, radius, outPoly)) {
                        result = true;
                    }
                }
            }
        }
        if (curNode->next == SS_NULL) {
            break;
        } else {
            curNode = &colCtx->polyNodes.tbl[curNode->next];
            continue;
        }
    }

    *outX = resultPos.x;
    *outZ = resultPos.z;
    return result;
}
