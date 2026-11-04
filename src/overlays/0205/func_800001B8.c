// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_g_splash.h"

void EffectSsGSplash_Draw(PlayState* play, u32 index, EffectSs* this) {
    s16 texIndex;

    switch (this->rType) {
        case EFFSSGSPLASH_TYPE_0:
            texIndex = this->rgTexIndex / 100;
            if (texIndex > 7) {
                texIndex = 7;
            }
            EffectSs_DrawGEffect(play, this, sWaterSplashTextures[texIndex]);
            break;

        case EFFSSGSPLASH_TYPE_1:
            texIndex = this->rgTexIndex / 100;
            if (texIndex > 7) {
                texIndex = 7;
            }
            EffectSs_DrawGEffect(play, this, sWaterSplashTextures[texIndex]);
            break;

        case EFFSSGSPLASH_TYPE_2:
            texIndex = this->rgTexIndex / 100;
            if (texIndex > 7) {
                texIndex = 7;
            }
            EffectSs_DrawGEffect(play, this, sWaterSplashTextures[texIndex]);
            break;
    }
}
