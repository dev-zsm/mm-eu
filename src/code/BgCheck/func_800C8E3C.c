// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 BgCheck_SphVsFirstDynaPolyList(CollisionContext* colCtx, u16 xpFlags, CollisionPoly** outPoly, Vec3f* center,
                                   f32 radius, SSList* ssList, Actor* actor, s32 bgId) {
    CollisionPoly* curPoly;
    DynaCollisionContext* dyna;
    SSNode* curNode;
    s32 curPolyId;

    if (ssList->head == SS_NULL) {
        return false;
    }
    dyna = &colCtx->dyna;
    curNode = &dyna->polyNodes.tbl[ssList->head];
    while (true) {
        curPolyId = curNode->polyId;
        curPoly = &dyna->polyList[curPolyId];
        if (COLPOLY_VTX_CHECK_FLAGS_ANY(curPoly->flags_vIA, xpFlags) ||
            (COLPOLY_VTX_CHECK_FLAGS_ANY(curPoly->flags_vIB, COLPOLY_VIB_FLAG_4) &&
             (((actor != NULL) && (actor->category != ACTORCAT_PLAYER)) ||
              ((actor == NULL) && (xpFlags != COLPOLY_IGNORE_CAMERA))))) {
            if (curNode->next == SS_NULL) {
                break;
            } else {
                curNode = &dyna->polyNodes.tbl[curNode->next];
                continue;
            }
        }
        if (CollisionPoly_SphVsPoly(curPoly, dyna->vtxList, center, radius)) {
            *outPoly = curPoly;
            return true;
        }
        if (curNode->next == SS_NULL) {
            break;
        } else {
            curNode = &dyna->polyNodes.tbl[curNode->next];
            continue;
        }
    }
    return false;
}
