// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 BgCheck_CheckDynaCeilingList(CollisionContext* colCtx, u16 xpFlags, DynaCollisionContext* dyna, SSList* ssList,
                                 f32* outY, Vec3f* pos, f32 checkHeight, CollisionPoly** outPoly, Actor* actor,
                                 s32 bgId) {
    s16 polyId;
    SSNode* curNode;
    CollisionPoly* poly;
    Vec3f testPos;
    f32 ceilingY;
    f32 sign;
    f32 nx;
    f32 ny;
    f32 nz;
    s32 result = false;
    f32 intersectDist;
    u16 padding;

    if (ssList->head == SS_NULL) {
        return false;
    }
    curNode = &dyna->polyNodes.tbl[ssList->head];
    testPos = *pos;

    while (true) {
        polyId = curNode->polyId;
        poly = &dyna->polyList[polyId];
        if (COLPOLY_VTX_CHECK_FLAGS_ANY(poly->flags_vIA, xpFlags) ||
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
        CollisionPoly_GetNormalF(poly, &nx, &ny, &nz);
        if (checkHeight < Math3D_UDistPlaneToPos(nx, ny, nz, poly->dist, &testPos)) {
            if (curNode->next == SS_NULL) {
                break;
            } else {
                curNode = &dyna->polyNodes.tbl[curNode->next];
                continue;
            }
        }
        if (CollisionPoly_CheckYIntersectApprox2(poly, dyna->vtxList, testPos.x, testPos.z, &ceilingY)) {
            intersectDist = ceilingY - testPos.y;
            if ((testPos.y < ceilingY) && (intersectDist < checkHeight) && (intersectDist * ny <= 0.0f)) {
                sign = (0.0f <= ny) ? 1.0f : -1.0f;
                testPos.y = (sign * checkHeight) + ceilingY;
                result = true;
                *outPoly = poly;
            }
        }
        if (curNode->next == SS_NULL) {
            break;
        } else {
            curNode = &dyna->polyNodes.tbl[curNode->next];
            continue;
        }
    }
    *outY = testPos.y;
    return result;
}
