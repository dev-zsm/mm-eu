// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 BgCheck_CheckLineAgainstBgActor(CollisionContext* colCtx, u16 xpFlags, Vec3f* posA, Vec3f* posB, Vec3f* posResult,
                                    CollisionPoly** outPoly, f32* distSq, s32 bgId, f32 checkDist, s32 bccFlags,
                                    Actor* actor) {
    s32 result = false;
    DynaLineTest dynaLineTest;

    dynaLineTest.colCtx = colCtx;
    dynaLineTest.xpFlags = xpFlags;
    dynaLineTest.dyna = &colCtx->dyna;
    dynaLineTest.posA = posA;
    dynaLineTest.posB = posB;
    dynaLineTest.posResult = posResult;
    dynaLineTest.resultPoly = outPoly;
    dynaLineTest.checkOneFace = (bccFlags & BGCHECK_CHECK_ONE_FACE) != 0;
    dynaLineTest.distSq = distSq;
    dynaLineTest.checkDist = checkDist;
    dynaLineTest.actor = actor;
    dynaLineTest.bgId = bgId;

    dynaLineTest.ssList = &colCtx->dyna.bgActors[bgId].dynaLookup.wall;
    if (bccFlags & BGCHECK_CHECK_WALL) {
        if (BgCheck_CheckLineAgainstBgActorSSList(&dynaLineTest)) {
            result = true;
        }
    }
    dynaLineTest.ssList = &colCtx->dyna.bgActors[bgId].dynaLookup.floor;
    if (bccFlags & BGCHECK_CHECK_FLOOR) {
        if (BgCheck_CheckLineAgainstBgActorSSList(&dynaLineTest)) {
            result = true;
        }
    }
    dynaLineTest.ssList = &colCtx->dyna.bgActors[bgId].dynaLookup.ceiling;
    if (bccFlags & BGCHECK_CHECK_CEILING) {
        if (BgCheck_CheckLineAgainstBgActorSSList(&dynaLineTest)) {
            result = true;
        }
    }
    return result;
}
