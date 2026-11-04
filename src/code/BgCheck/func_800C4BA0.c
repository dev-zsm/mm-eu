// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 BgCheck_CheckCeilingImpl(CollisionContext* colCtx, u16 xpFlags, f32* outY, Vec3f* pos, f32 checkHeight,
                             CollisionPoly** outPoly, s32* outBgId, Actor* actor) {
    StaticLookup* lookupTbl;
    StaticLookup* lookup;
    s32 result;
    Vec3f posTemp;
    f32 tempY;

    *outBgId = BGCHECK_SCENE;
    *outY = pos->y;
    lookupTbl = colCtx->lookupTbl;
    if (!BgCheck_PosInStaticBoundingBox(colCtx, pos)) {
        return false;
    }

    lookup = BgCheck_GetNearestStaticLookup(colCtx, lookupTbl, pos);
    result = BgCheck_CheckStaticCeiling(lookup, xpFlags, colCtx, outY, pos, checkHeight, outPoly, actor);

    posTemp = *pos;
    posTemp.y = *outY;
    tempY = *outY;

    if (BgCheck_CheckDynaCeiling(colCtx, xpFlags, &tempY, &posTemp, checkHeight, outPoly, outBgId, actor)) {
        *outY = tempY;
        result = true;
    }
    return result;
}
