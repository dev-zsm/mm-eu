// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bom_chu.h"

s32 EnBomChu_IsOnCollisionPoly(PlayState* play, Vec3f* posA, Vec3f* posB, Vec3f* posResult, CollisionPoly** poly,
                               s32* bgId) {
    if (BgCheck_EntityLineTest1(&play->colCtx, posA, posB, posResult, poly, true, true, true, true, bgId) &&
        !(SurfaceType_GetWallFlags(&play->colCtx, *poly, *bgId) & (WALL_FLAG_4 | WALL_FLAG_5))) {
        return true;
    }

    return false;
}
