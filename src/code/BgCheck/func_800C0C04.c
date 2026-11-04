// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

f32 BgCheck_RaycastFloorStaticList(CollisionContext* colCtx, u16 xpFlags, SSList* ssList, CollisionPoly** outPoly,
                                   Vec3f* pos, f32 yIntersectMin, f32 checkDist, s32 flags, Actor* actor, s32 arg9) {
    SSNode* curNode;
    s32 polyId;
    f32 result;
    f32 yIntersect;
    CollisionPoly* colPoly;
    s32 pad;

    result = yIntersectMin;
    if (ssList->head == SS_NULL) {
        return result;
    }

    curNode = &colCtx->polyNodes.tbl[ssList->head];

    while (true) {
        polyId = curNode->polyId;
        colPoly = &colCtx->colHeader->polyList[polyId];

        if (((flags & 1) && (colPoly->normal.y < 0)) ||
            ((arg9 & 0x20) && ((colCtx->colHeader->surfaceTypeList[colPoly->type].data[0] >> 0x1E) & 1)) ||
            COLPOLY_VTX_CHECK_FLAGS_ANY(colPoly->flags_vIA, xpFlags) ||
            (COLPOLY_VTX_CHECK_FLAGS_ANY(colPoly->flags_vIB, COLPOLY_VIB_FLAG_4) &&
             (((actor != NULL) && (actor->category != ACTORCAT_PLAYER)) ||
              ((actor == NULL) && (xpFlags != COLPOLY_IGNORE_CAMERA))))) {
            if (curNode->next == SS_NULL) {
                break;
            }
            curNode = &colCtx->polyNodes.tbl[curNode->next];
            continue;
        }

        if ((pos->y < colCtx->colHeader->vtxList[COLPOLY_VTX_INDEX(colPoly->flags_vIA)].y) &&
            (pos->y < colCtx->colHeader->vtxList[COLPOLY_VTX_INDEX(colPoly->flags_vIB)].y) &&
            (pos->y < colCtx->colHeader->vtxList[colPoly->vIC].y)) {
            break;
        }

        if (CollisionPoly_CheckYIntersect(colPoly, colCtx->colHeader->vtxList, pos->x, pos->z, &yIntersect,
                                          checkDist)) {
            
            if ((yIntersect < pos->y) && (result < yIntersect)) {
                result = yIntersect;
                *outPoly = colPoly;
            }
        }

        if (curNode->next == SS_NULL) {
            break;
        }
        curNode = &colCtx->polyNodes.tbl[curNode->next];
    }
    return result;
}
