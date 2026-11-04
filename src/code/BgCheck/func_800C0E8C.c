// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

f32 BgCheck_RaycastFloorStatic(StaticLookup* lookup, CollisionContext* colCtx, u16 xpFlags, CollisionPoly** poly,
                               Vec3f* pos, u32 arg5, f32 checkDist, f32 yIntersectMin, Actor* actor) {
    s32 flag; 
    f32 yIntersect = yIntersectMin;

    if (arg5 & 4) {
        yIntersect = BgCheck_RaycastFloorStaticList(colCtx, xpFlags, &lookup->floor, poly, pos, yIntersect, checkDist,
                                                    0, actor, arg5);
    }

    if ((arg5 & 2) || (arg5 & 8)) {
        flag = 0;
        if (arg5 & 0x10) {
            flag = 1;
        }
        yIntersect = BgCheck_RaycastFloorStaticList(colCtx, xpFlags, &lookup->wall, poly, pos, yIntersect, checkDist,
                                                    flag, actor, arg5);
    }

    if (arg5 & 1) {
        flag = 0;
        if (arg5 & 0x10) {
            flag = 1;
        }
        yIntersect = BgCheck_RaycastFloorStaticList(colCtx, xpFlags, &lookup->ceiling, poly, pos, yIntersect, checkDist,
                                                    flag, actor, arg5);
    }

    return yIntersect;
}
