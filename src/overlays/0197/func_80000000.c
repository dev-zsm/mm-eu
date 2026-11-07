// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_dust.h"

u32 EffectSsDust_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsDustInitParams* initParams = PARAMS;

    Math_Vec3f_Copy(&this->pos, &initParams->pos);
    Math_Vec3f_Copy(&this->velocity, &initParams->velocity);
    Math_Vec3f_Copy(&this->accel, &initParams->accel);
    this->gfx = gEffDustDL;
    this->life = initParams->life;
    this->update = sUpdateFuncs[initParams->updateMode];
    this->draw = EffectSsDust_Draw;

    if (initParams->drawFlags & DUST_DRAWFLAG_RAND_COLOR_OFFSET) {
        s32 randColorOffset = Rand_ZeroOne() * 20.0f - 10.0f;

        this->rPrimColorR = initParams->primColor.r + randColorOffset;
        this->rPrimColorG = initParams->primColor.g + randColorOffset;
        this->rPrimColorB = initParams->primColor.b + randColorOffset;
        this->rEnvColorR = initParams->envColor.r + randColorOffset;
        this->rEnvColorG = initParams->envColor.g + randColorOffset;
        this->rEnvColorB = initParams->envColor.b + randColorOffset;
    } else {
        this->rPrimColorR = initParams->primColor.r;
        this->rPrimColorG = initParams->primColor.g;
        this->rPrimColorB = initParams->primColor.b;
        this->rEnvColorR = initParams->envColor.r;
        this->rEnvColorG = initParams->envColor.g;
        this->rEnvColorB = initParams->envColor.b;
    }

    this->rPrimColorA = initParams->primColor.a;
    this->rEnvColorA = initParams->envColor.a;
    this->rTexIndex = 0;
    this->rScale = initParams->scale;
    this->rScaleStep = initParams->scaleStep;
    this->rLifespan = initParams->life;
    this->rDrawFlags = initParams->drawFlags;

    return 1;
}
