// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 BgCheck_CheckLineAgainstSSList(StaticLineTest* arg0) {
    CollisionPoly* polyList;
    s32 result;
    Vec3f polyIntersect;
    SSNode* curNode;
    u8* checkedPoly;
    f32 minY;
    f32 distSq;
    BgLineVsPolyTest test;
    s16 polyId;

    result = false;
    if (arg0->ssList->head == SS_NULL) {
        return result;
    }
    curNode = &arg0->colCtx->polyNodes.tbl[arg0->ssList->head];
    polyList = arg0->colCtx->colHeader->polyList;
    test.vtxList = arg0->colCtx->colHeader->vtxList;
    test.posA = arg0->posA;
    test.posB = arg0->posB;
    test.planeIntersect = &polyIntersect; 
    test.checkOneFace = (arg0->bccFlags & BGCHECK_CHECK_ONE_FACE) != 0;
    test.checkDist = arg0->checkDist;

    while (true) {
        polyId = curNode->polyId;
        test.poly = &polyList[polyId];
        checkedPoly = &arg0->colCtx->polyNodes.polyCheckTbl[polyId];

        if ((*checkedPoly == true) ||
            ((arg0->xpFlags2 != 0) && !COLPOLY_VTX_CHECK_FLAGS_ANY(test.poly->flags_vIA, arg0->xpFlags2)) ||
            COLPOLY_VTX_CHECK_FLAGS_ANY(test.poly->flags_vIA, arg0->xpFlags1) ||
            (COLPOLY_VTX_CHECK_FLAGS_ANY(test.poly->flags_vIB, COLPOLY_VIB_FLAG_4) &&
             (((arg0->actor != NULL) && (arg0->actor->category != ACTORCAT_PLAYER)) ||
              ((arg0->actor == NULL) && (arg0->xpFlags1 != COLPOLY_IGNORE_CAMERA))))) {
            if (curNode->next == SS_NULL) {
                break;
            } else {
                curNode = &arg0->colCtx->polyNodes.tbl[curNode->next];
                continue;
            }
        }
        *checkedPoly = true;
        minY = CollisionPoly_GetMinY(test.poly, test.vtxList);
        if (((test.posA->y < minY)) && (test.posB->y < minY)) {
            break;
        }
        if (CollisionPoly_LineVsPoly(&test)) {
            distSq = Math3D_Vec3fDistSq(test.posA, test.planeIntersect);
            if (distSq < arg0->outDistSq) {
                arg0->outDistSq = distSq;
                *arg0->outPos = *test.planeIntersect;
                *arg0->posB = *test.planeIntersect;
                *arg0->outPoly = test.poly;
                result = true;
            }
        }
        if (curNode->next == SS_NULL) {
            break;
        }
        curNode = &arg0->colCtx->polyNodes.tbl[curNode->next];
    }
    return result;
}
