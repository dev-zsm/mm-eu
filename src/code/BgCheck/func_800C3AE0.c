// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

f32 BgCheck_RaycastFloorImpl(PlayState* play, CollisionContext* colCtx, u16 xpFlags, CollisionPoly** outPoly,
                             s32* outBgId, Vec3f* pos, Actor* actor, u32 arg7, f32 checkDist, s32 arg9) {
    f32 yIntersectDyna;
    f32 yIntersect;
    StaticLookup* lookupTbl;
    Vec3f checkPos;
    StaticLookup* lookup;
    DynaRaycast dynaRaycast;

    *outBgId = BGCHECK_SCENE;
    *outPoly = NULL;
    lookupTbl = colCtx->lookupTbl;
    yIntersect = BGCHECK_Y_MIN;
    checkPos = *pos;

    while (true) {
        if (checkPos.y < colCtx->minBounds.y) {
            break;
        }
        lookup = BgCheck_GetStaticLookup(colCtx, lookupTbl, &checkPos);
        if (lookup == NULL) {
            checkPos.y -= colCtx->subdivLength.y;
            continue;
        }
        yIntersect =
            BgCheck_RaycastFloorStatic(lookup, colCtx, xpFlags, outPoly, pos, arg7, checkDist, BGCHECK_Y_MIN, actor);
        if (yIntersect > BGCHECK_Y_MIN) {
            break;
        }
        checkPos.y -= colCtx->subdivLength.y;
    }
    if (!(arg9 & 1)) {
        dynaRaycast.play = play;
        dynaRaycast.colCtx = colCtx;
        dynaRaycast.xpFlags = xpFlags;
        dynaRaycast.resultPoly = outPoly;
        dynaRaycast.yIntersect = yIntersect;
        dynaRaycast.pos = pos;
        dynaRaycast.bgId = outBgId;
        dynaRaycast.unk1C = 50;
        dynaRaycast.actor = actor;
        dynaRaycast.unk_24 = arg7;
        dynaRaycast.checkDist = checkDist;

        yIntersectDyna = BgCheck_RaycastFloorDyna(&dynaRaycast);
        if (yIntersect < yIntersectDyna) {
            yIntersect = yIntersectDyna;
        }
    }

    if ((yIntersect != BGCHECK_Y_MIN) && SurfaceType_IsSoft(colCtx, *outPoly, *outBgId)) {
        yIntersect -= 1.0f;
    }
    return yIntersect;
}
