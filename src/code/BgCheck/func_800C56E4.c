// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 BgCheck_SphVsFirstPolyImpl(CollisionContext* colCtx, u16 xpFlags, CollisionPoly** outPoly, s32* outBgId,
                               Vec3f* center, f32 radius, Actor* actor, u16 bciFlags) {
    StaticLookup* lookup;

    *outBgId = BGCHECK_SCENE;
    lookup = BgCheck_GetStaticLookup(colCtx, colCtx->lookupTbl, center);
    if (lookup == NULL) {
        return false;
    } else if (BgCheck_SphVsFirstStaticPoly(lookup, xpFlags, colCtx, center, radius, outPoly, bciFlags, actor) ||
               BgCheck_SphVsFirstDynaPoly(colCtx, xpFlags, outPoly, outBgId, center, radius, actor, bciFlags)) {
        return true;
    }
    return false;
}
