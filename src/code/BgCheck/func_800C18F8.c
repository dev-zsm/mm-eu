// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 BgCheck_CheckStaticCeiling(StaticLookup* lookup, u16 xpFlags, CollisionContext* colCtx, f32* outY, Vec3f* pos,
                               f32 checkHeight, CollisionPoly** outPoly, Actor* actor) {
    s32 result = false;
    CollisionPoly* curPoly;
    CollisionPoly* polyList;
    s32 curPolyId;
    f32 ceilingY;
    SSNode* curNode;
    Vec3s* vtxList;

    if (lookup->ceiling.head == SS_NULL) {
        return result;
    }
    polyList = colCtx->colHeader->polyList;
    vtxList = colCtx->colHeader->vtxList;
    curNode = &colCtx->polyNodes.tbl[lookup->ceiling.head];

    *outY = pos->y;

    while (true) {
        f32 intersectDist;
        f32 ny;

        curPolyId = curNode->polyId;
        curPoly = &polyList[curPolyId];
        if (COLPOLY_VTX_CHECK_FLAGS_ANY(colCtx->colHeader->polyList[curPolyId].flags_vIA, xpFlags) ||
            (COLPOLY_VTX_CHECK_FLAGS_ANY(colCtx->colHeader->polyList[curPolyId].flags_vIB, COLPOLY_VIB_FLAG_4) &&
             (((actor != NULL) && (actor->category != ACTORCAT_PLAYER)) ||
              ((actor == NULL) && (xpFlags != COLPOLY_IGNORE_CAMERA))))) {
            if (curNode->next == SS_NULL) {
                break;
            } else {
                curNode = &colCtx->polyNodes.tbl[curNode->next];
                continue;
            }
        }

        if (CollisionPoly_CheckYIntersectApprox2(curPoly, vtxList, pos->x, pos->z, &ceilingY)) {
            intersectDist = ceilingY - *outY;
            ny = COLPOLY_GET_NORMAL(curPoly->normal.y);

            if ((intersectDist > 0) && (intersectDist < checkHeight) && (intersectDist * ny <= 0)) {
                *outY = ceilingY - checkHeight;
                *outPoly = curPoly;
                result = true;
            }
        }
        if (curNode->next == SS_NULL) {
            break;
        } else {
            curNode = &colCtx->polyNodes.tbl[curNode->next];
            continue;
        }
    }
    return result;
}
