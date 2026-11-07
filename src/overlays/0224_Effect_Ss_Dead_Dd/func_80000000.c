// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_dead_dd.h"

u32 EffectSsDeadDd_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsDeadDdInitParams* initParams = PARAMS;

    if (initParams->type == DEADDD_TYPE_0) {
        this->pos = initParams->pos;
        this->velocity = initParams->velocity;
        this->accel = initParams->accel;
        this->life = initParams->life;
        this->rScaleStep = initParams->scaleStep;
        this->rAlphaMode = initParams->alphaStep;

        if (initParams->alphaStep != 0) {
            this->rAlphaStep = initParams->alphaStep;
        } else {
            this->rAlphaStep = initParams->primColor.a / initParams->life;
        }

        this->draw = EffectSsDeadDd_Draw;
        this->update = EffectSsDeadDd_Update;
        this->rScale = initParams->scale;
        this->rPrimColorR = initParams->primColor.r;
        this->rPrimColorG = initParams->primColor.g;
        this->rPrimColorB = initParams->primColor.b;
        this->rAlpha = initParams->primColor.a;
        this->rEnvColorR = initParams->envColor.r;
        this->rEnvColorG = initParams->envColor.g;
        this->rEnvColorB = initParams->envColor.b;

    } else if (initParams->type == DEADDD_TYPE_1) {
        s32 i;

        this->life = initParams->life;
        this->rScaleStep = initParams->scaleStep;
        this->rAlphaMode = 0;
        this->rAlphaStep = 155 / initParams->life;
        this->rScale = initParams->scale;
        this->rPrimColorR = 255;
        this->rPrimColorG = 255;
        this->rPrimColorB = 155;
        this->rAlpha = 155;
        this->rEnvColorR = 250;
        this->rEnvColorG = 180;
        this->rEnvColorB = 0;
        this->draw = EffectSsDeadDd_Draw;
        this->update = EffectSsDeadDd_Update;

        for (i = initParams->randIter; i > 0; i--) {
            this->pos.x = ((Rand_ZeroOne() - 0.5f) * initParams->randPosScale) + initParams->pos.x;
            this->pos.y = ((Rand_ZeroOne() - 0.5f) * initParams->randPosScale) + initParams->pos.y;
            this->pos.z = ((Rand_ZeroOne() - 0.5f) * initParams->randPosScale) + initParams->pos.z;
            this->accel.x = this->velocity.x = (Rand_ZeroOne() - 0.5f) * 2.0f;
            this->accel.y = this->velocity.y = (Rand_ZeroOne() - 0.5f) * 2.0f;
            this->accel.z = this->velocity.z = (Rand_ZeroOne() - 0.5f) * 2.0f;
        }
    } else {
        return 0;
    }

    return 1;
}
