// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

f32 BgCheck_RaycastFloorDynaList(DynaRaycast* dynaRaycast, u32 listType) {
    CollisionPoly* polyList;
    SSNode* curNode;
    f32 result;
    f32 yIntersect;
    s16 id;

    result = dynaRaycast->yIntersect;
    if (dynaRaycast->ssList->head == SS_NULL) {
        return result;
    }
    polyList = dynaRaycast->dyna->polyList;
    curNode = &dynaRaycast->dyna->polyNodes.tbl[dynaRaycast->ssList->head];

    while (true) {
        id = curNode->polyId;
        if (COLPOLY_VTX_CHECK_FLAGS_ANY(polyList[id].flags_vIA, dynaRaycast->xpFlags) ||
            (COLPOLY_VTX_CHECK_FLAGS_ANY(polyList[id].flags_vIB, COLPOLY_VIB_FLAG_4) &&
             (((dynaRaycast->actor != NULL) && (dynaRaycast->actor->category != ACTORCAT_PLAYER)) ||
              ((dynaRaycast->actor == NULL) && (dynaRaycast->xpFlags != COLPOLY_IGNORE_CAMERA)))) ||
            ((dynaRaycast->unk_24 & 0x20) &&
             SurfaceType_IsSoft(dynaRaycast->colCtx, &polyList[id], dynaRaycast->unk1C))) {
            if (curNode->next == SS_NULL) {
                break;
            } else {
                curNode = &dynaRaycast->dyna->polyNodes.tbl[curNode->next];
                continue;
            }
        }
        if ((listType & (DYNA_RAYCAST_WALLS | DYNA_RAYCAST_CEILINGS)) && (dynaRaycast->unk_24 & 0x10) &&
            (COLPOLY_GET_NORMAL(polyList[id].normal.y) < 0.0f)) {
            if (curNode->next == SS_NULL) {
                break;
            } else {
                curNode = &dynaRaycast->dyna->polyNodes.tbl[curNode->next];
                continue;
            }
        }
        if (CollisionPoly_CheckYIntersectApprox1(&polyList[id], dynaRaycast->dyna->vtxList, dynaRaycast->pos->x,
                                                 dynaRaycast->pos->z, &yIntersect, dynaRaycast->checkDist) &&
            (yIntersect < dynaRaycast->pos->y) && (result < yIntersect)) {
            result = yIntersect;
            *dynaRaycast->resultPoly = &dynaRaycast->dyna->polyList[id];
        }
        if (curNode->next == SS_NULL) {
            break;
        } else {
            curNode = &dynaRaycast->dyna->polyNodes.tbl[curNode->next];
            continue;
        }
    }
    return result;
}
