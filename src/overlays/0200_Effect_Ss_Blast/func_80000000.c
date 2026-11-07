// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_blast.h"

u32 EffectSsBlast_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsBlastInitParams* initParams = PARAMS;

    this->pos = initParams->pos;
    this->pos.y += 5.0f;
    this->velocity = initParams->velocity;
    this->accel = initParams->accel;
    this->gfx = gEffShockwaveDL;
    this->life = initParams->life;
    this->draw = EffectSsBlast_Draw;
    this->update = EffectSsBlast_Update;
    this->rPrimColorR = initParams->primColor.r;
    this->rPrimColorG = initParams->primColor.g;
    this->rPrimColorB = initParams->primColor.b;
    this->rPrimColorA = initParams->primColor.a;
    this->rEnvColorR = initParams->envColor.r;
    this->rEnvColorG = initParams->envColor.g;
    this->rEnvColorB = initParams->envColor.b;
    this->rEnvColorA = initParams->envColor.a;
    this->rAlphaStep = initParams->primColor.a / initParams->life;
    this->rScale = initParams->scale;
    this->rScaleStep = initParams->scaleStep;
    this->rScaleStepDecay = initParams->scaleStepDecay;

    return 1;
}
