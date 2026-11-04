// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 BgCheck_SphVsFirstDynaPolyInBgActor(CollisionContext* colCtx, u16 xpFlags, CollisionPoly** outPoly, Vec3f* center,
                                        f32 radius, s32 bgId, u16 bciFlags, Actor* actor) {
    if (!(bciFlags & BGCHECK_IGNORE_CEILING)) {
        if (BgCheck_SphVsFirstDynaPolyList(colCtx, xpFlags, outPoly, center, radius,
                                           &colCtx->dyna.bgActors[bgId].dynaLookup.ceiling, actor, bgId)) {
            return true;
        }
    }
    if (!(bciFlags & BGCHECK_IGNORE_WALL)) {
        if (BgCheck_SphVsFirstDynaPolyList(colCtx, xpFlags, outPoly, center, radius,
                                           &colCtx->dyna.bgActors[bgId].dynaLookup.wall, actor, bgId)) {
            return true;
        }
    }
    if (!(bciFlags & BGCHECK_IGNORE_FLOOR)) {
        if (BgCheck_SphVsFirstDynaPolyList(colCtx, xpFlags, outPoly, center, radius,
                                           &colCtx->dyna.bgActors[bgId].dynaLookup.floor, actor, bgId)) {
            return true;
        }
    }
    return false;
}
