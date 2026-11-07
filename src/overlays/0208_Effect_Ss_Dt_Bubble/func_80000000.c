// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_dt_bubble.h"

u32 EffectSsDtBubble_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsDtBubbleInitParams* initParams = PARAMS;

    {
        TexturePtr tex = (Rand_ZeroOne() < 0.5f) ? gEffBubble1Tex : gEffBubble2Tex;

        this->gfx = (void*)OS_K0_TO_PHYSICAL(SEGMENTED_TO_K0(tex));
    }

    Math_Vec3f_Copy(&this->pos, &initParams->pos);
    Math_Vec3f_Copy(&this->velocity, &initParams->velocity);
    Math_Vec3f_Copy(&this->accel, &initParams->accel);
    this->life = initParams->life;

    if (!initParams->customColor) {
        this->rPrimColorR = sPrimColors[initParams->colorProfile].r;
        this->rPrimColorG = sPrimColors[initParams->colorProfile].g;
        this->rPrimColorB = sPrimColors[initParams->colorProfile].b;
        this->rPrimColorA = sPrimColors[initParams->colorProfile].a;
        this->rEnvColorR = sEnvColors[initParams->colorProfile].r;
        this->rEnvColorG = sEnvColors[initParams->colorProfile].g;
        this->rEnvColorB = sEnvColors[initParams->colorProfile].b;
        this->rEnvColorA = sEnvColors[initParams->colorProfile].a;
    } else {
        this->rPrimColorR = initParams->primColor.r;
        this->rPrimColorG = initParams->primColor.g;
        this->rPrimColorB = initParams->primColor.b;
        this->rPrimColorA = initParams->primColor.a;
        this->rEnvColorR = initParams->envColor.r;
        this->rEnvColorG = initParams->envColor.g;
        this->rEnvColorB = initParams->envColor.b;
        this->rEnvColorA = initParams->envColor.a;
    }

    this->rRandXZ = initParams->randXZ;
    this->rScale = initParams->scale;
    this->rLifespan = initParams->life;
    this->draw = EffectSsDtBubble_Draw;
    this->update = EffectSsDtBubble_Update;

    return 1;
}
