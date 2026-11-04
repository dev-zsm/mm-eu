// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 BgCheck_CheckLineAgainstBgActorSSList(DynaLineTest* dynaLineTest) {
    f32 distSq;
    s32 result;
    SSNode* curNode;
    Vec3f polyIntersect;
    s16 polyId;
    BgLineVsPolyTest test;

    result = false;
    if (dynaLineTest->ssList->head == SS_NULL) {
        return result;
    }
    curNode = &dynaLineTest->dyna->polyNodes.tbl[dynaLineTest->ssList->head];

    test.vtxList = dynaLineTest->dyna->vtxList;
    test.posA = dynaLineTest->posA;
    test.posB = dynaLineTest->posB;
    test.planeIntersect = &polyIntersect;
    test.checkOneFace = dynaLineTest->checkOneFace;
    test.checkDist = dynaLineTest->checkDist;

    while (true) {
        polyId = curNode->polyId;
        test.poly = &dynaLineTest->dyna->polyList[polyId];
        if (COLPOLY_VTX_CHECK_FLAGS_ANY(test.poly->flags_vIA, dynaLineTest->xpFlags) ||
            (COLPOLY_VTX_CHECK_FLAGS_ANY(test.poly->flags_vIB, COLPOLY_VIB_FLAG_4) &&
             (((dynaLineTest->actor != NULL) && (dynaLineTest->actor->category != ACTORCAT_PLAYER)) ||
              ((dynaLineTest->actor == NULL) && (dynaLineTest->xpFlags != COLPOLY_IGNORE_CAMERA))))) {
            if (curNode->next == SS_NULL) {
                break;
            } else {
                curNode = &dynaLineTest->dyna->polyNodes.tbl[curNode->next];
            }
        } else {
            if (CollisionPoly_LineVsPoly(&test)) {
                distSq = Math3D_Vec3fDistSq(dynaLineTest->posA, test.planeIntersect);
                if (distSq < *dynaLineTest->distSq) {
                    *dynaLineTest->distSq = distSq;
                    *dynaLineTest->posResult = *test.planeIntersect;
                    *dynaLineTest->posB = *test.planeIntersect;
                    *dynaLineTest->resultPoly = test.poly;
                    result = true;
                }
            }
            if (curNode->next == SS_NULL) {
                break;
            } else {
                curNode = &dynaLineTest->dyna->polyNodes.tbl[curNode->next];
            }
        }
    }
    return result;
}
