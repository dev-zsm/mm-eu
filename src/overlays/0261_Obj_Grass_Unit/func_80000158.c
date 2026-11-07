// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_grass_unit.h"

s32 ObjGrassUnit_IsUnderwater(PlayState* play, Vec3f* pos) {
    WaterBox* waterBox;
    f32 waterSurface;
    s32 bgId;

    if (BgCheck_GetWaterSurface(play, &play->colCtx, pos->x, pos->z, &waterSurface, &waterBox, &bgId) &&
        (pos->y < waterSurface)) {
        return true;
    }
    return false;
}
