// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 BgCheck_SphVsFirstStaticPolyList(SSNode* node, u16 xpFlags, CollisionContext* colCtx, Vec3f* center, f32 radius,
                                     CollisionPoly** outPoly, Actor* actor) {
    Vec3s* vtxList;
    CollisionPoly* polyList;
    CollisionPoly* curPoly;
    u16 nextId;
    s16 curPolyId;

    polyList = colCtx->colHeader->polyList;
    vtxList = colCtx->colHeader->vtxList;

    while (true) {
        curPolyId = node->polyId;
        curPoly = &polyList[curPolyId];
        if (COLPOLY_VTX_CHECK_FLAGS_ANY(colCtx->colHeader->polyList[curPolyId].flags_vIA, xpFlags) ||
            (COLPOLY_VTX_CHECK_FLAGS_ANY(colCtx->colHeader->polyList[curPolyId].flags_vIB, COLPOLY_VIB_FLAG_4) &&
             (((actor != NULL) && (actor->category != ACTORCAT_PLAYER)) ||
              ((actor == NULL) && (xpFlags != COLPOLY_IGNORE_CAMERA))))) {
            if (node->next != SS_NULL) {
                node = &colCtx->polyNodes.tbl[node->next];
                continue;
            }
            break;
        }

        if ((center->y + radius < vtxList[COLPOLY_VTX_INDEX(curPoly->flags_vIA)].y) &&
            (center->y + radius < vtxList[COLPOLY_VTX_INDEX(curPoly->flags_vIB)].y) &&
            (center->y + radius < vtxList[curPoly->vIC].y)) {
            break;
        }

        if (CollisionPoly_SphVsPoly(curPoly, vtxList, center, radius)) {
            *outPoly = curPoly;
            return true;
        }
        if (node->next != SS_NULL) {
            node = &colCtx->polyNodes.tbl[node->next];
            { s32 pad; }

            continue;
        }
        break;
    }
    return false;
}
