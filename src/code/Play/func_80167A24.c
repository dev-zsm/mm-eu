// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_play.h"

f32 Play_GetWaterSurface(PlayState* this, Vec3f* pos, s32* lightIndex) {
    Player* player = GET_PLAYER(this);
    f32 waterSurfaceY = player->actor.world.pos.y;
    WaterBox* waterBox;
    s32 bgId;

    if (!BgCheck_GetWaterSurface(this, &this->colCtx, pos->x, pos->z, &waterSurfaceY, &waterBox, &bgId)) {
        return BGCHECK_Y_MIN;
    }

    if (waterSurfaceY < pos->y) {
        return BGCHECK_Y_MIN;
    }

    *lightIndex = WaterBox_GetLightSettingIndex(&this->colCtx, waterBox);
    return waterSurfaceY;
}
