// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 BgCheck_SphVsFirstStaticPoly(StaticLookup* lookup, u16 xpFlags, CollisionContext* colCtx, Vec3f* center, f32 radius,
                                 CollisionPoly** outPoly, u16 bciFlags, Actor* actor) {
    if ((lookup->floor.head != SS_NULL) && !(bciFlags & BGCHECK_IGNORE_FLOOR) &&
        BgCheck_SphVsFirstStaticPolyList(&colCtx->polyNodes.tbl[lookup->floor.head], xpFlags, colCtx, center, radius,
                                         outPoly, actor)) {
        return true;
    }

    if ((lookup->wall.head != SS_NULL) && !(bciFlags & BGCHECK_IGNORE_WALL) &&
        BgCheck_SphVsFirstStaticPolyList(&colCtx->polyNodes.tbl[lookup->wall.head], xpFlags, colCtx, center, radius,
                                         outPoly, actor)) {
        return true;
    }

    if ((lookup->ceiling.head != SS_NULL) && !(bciFlags & BGCHECK_IGNORE_CEILING) &&
        BgCheck_SphVsFirstStaticPolyList(&colCtx->polyNodes.tbl[lookup->ceiling.head], xpFlags, colCtx, center, radius,
                                         outPoly, actor)) {
        return true;
    }

    return false;
}
