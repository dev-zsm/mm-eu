// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_g_fire.h"

void EffectSsGFire_Draw(PlayState* play, u32 index, EffectSs* this) {
    TexturePtr fireFootprintTextures[] = {
        gEffFireFootprint1Tex, gEffFireFootprint2Tex, gEffFireFootprint3Tex, gEffFireFootprint4Tex,
        gEffFireFootprint5Tex, gEffFireFootprint6Tex, gEffFireFootprint7Tex, gEffFireFootprint8Tex,
    };
    s16 texIndex = (this->rgTexIndex / 100) % 7;

    EffectSs_DrawGEffect(play, this, fireFootprintTextures[texIndex]);
}
