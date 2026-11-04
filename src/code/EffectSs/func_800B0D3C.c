// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_effect_soft_sprite.h"

void EffectSs_DrawAll(PlayState* play) {
    Lights* lights = LightContext_NewLights(&play->lightCtx, play->state.gfxCtx);
    s32 i;

    Lights_BindAll(lights, play->lightCtx.listHead, NULL, play);
    Lights_Draw(lights, play->state.gfxCtx);

    for (i = 0; i < sEffectSsInfo.tableSize; i++) {
        if (sEffectSsInfo.table[i].life > -1) {
            if ((sEffectSsInfo.table[i].pos.x > BGCHECK_Y_MAX) || (sEffectSsInfo.table[i].pos.x < BGCHECK_Y_MIN) ||
                (sEffectSsInfo.table[i].pos.y > BGCHECK_Y_MAX) || (sEffectSsInfo.table[i].pos.y < BGCHECK_Y_MIN) ||
                (sEffectSsInfo.table[i].pos.z > BGCHECK_Y_MAX) || (sEffectSsInfo.table[i].pos.z < BGCHECK_Y_MIN)) {
                EffectSs_Delete(&sEffectSsInfo.table[i]);
            } else {
                EffectSs_Draw(play, i);
            }
        }
    }
}
