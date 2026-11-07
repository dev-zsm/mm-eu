// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_g_splash.h"

u32 EffectSsGSplash_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsGSplashInitParams* initParams = PARAMS;

    Math_Vec3f_Copy(&this->velocity, &gZeroVec3f);
    Math_Vec3f_Copy(&this->accel, &gZeroVec3f);
    Math_Vec3f_Copy(&this->pos, &initParams->pos);
    this->draw = EffectSsGSplash_Draw;
    this->update = EffectSsGSplash_Update;

    if (initParams->scale == 0) {
        initParams->scale = 600;
    }

    this->gfx = gEffWaterSplashDL;
    this->life = 8;
    this->rgScale = initParams->scale;
    this->rgTexIndex = 0;
    this->rgTexIndexStep = 100;

    if (initParams->customColor) {
        this->rgPrimColorR = initParams->primColor.r;
        this->rgPrimColorG = initParams->primColor.g;
        this->rgPrimColorB = initParams->primColor.b;
        this->rgPrimColorA = initParams->primColor.a;
        this->rgEnvColorR = initParams->envColor.r;
        this->rgEnvColorG = initParams->envColor.g;
        this->rgEnvColorB = initParams->envColor.b;
        this->rgEnvColorA = initParams->envColor.a;
        this->rType = initParams->type;
    } else {
        switch (initParams->type) {
            case EFFSSGSPLASH_TYPE_0:
                this->rgPrimColorR = 255;
                this->rgPrimColorG = 255;
                this->rgPrimColorB = 255;
                this->rgPrimColorA = 200;
                this->rgEnvColorR = 255;
                this->rgEnvColorG = 255;
                this->rgEnvColorB = 255;
                this->rgEnvColorA = 200;
                this->rType = EFFSSGSPLASH_TYPE_0;
                break;

            case EFFSSGSPLASH_TYPE_1:
                this->rgPrimColorR = 255;
                this->rgPrimColorG = 255;
                this->rgPrimColorB = 255;
                this->rgPrimColorA = 255;
                this->rgEnvColorR = 255;
                this->rgEnvColorG = 255;
                this->rgEnvColorB = 255;
                this->rgEnvColorA = 255;
                this->rType = EFFSSGSPLASH_TYPE_1;
                break;

            case EFFSSGSPLASH_TYPE_2:
                this->rgPrimColorR = 255;
                this->rgPrimColorG = 255;
                this->rgPrimColorB = 255;
                this->rgPrimColorA = 200;
                this->rgEnvColorR = 255;
                this->rgEnvColorG = 255;
                this->rgEnvColorB = 255;
                this->rgEnvColorA = 200;
                this->rType = EFFSSGSPLASH_TYPE_2;
                break;
        }
    }
    return 1;
}
