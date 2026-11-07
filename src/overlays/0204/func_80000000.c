// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_g_ripple.h"

u32 EffectSsGRipple_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsGRippleInitParams* initParams = PARAMS;
    WaterBox* waterBox = NULL;
    s32 pad;
    s32 bgId;

    Math_Vec3f_Copy(&this->velocity, &gZeroVec3f);
    Math_Vec3f_Copy(&this->accel, &gZeroVec3f);
    Math_Vec3f_Copy(&this->pos, &initParams->pos);
    this->gfx = gEffWaterRippleDL;
    this->life = initParams->life + 20;
    this->flags = 0;
    this->draw = EffectSsGRipple_Draw;
    this->update = EffectSsGRipple_Update;
    this->rRadius = initParams->radius;
    this->rRadiusMax = initParams->radiusMax;
    this->rLifespan = initParams->life;
    this->rPrimColorR = 255;
    this->rPrimColorG = 255;
    this->rPrimColorB = 255;
    this->rPrimColorA = 255;
    this->rEnvColorR = 255;
    this->rEnvColorG = 255;
    this->rEnvColorB = 255;
    this->rEnvColorA = 255;
    this->rWaterBoxNum = BgCheck_FindWaterBox(play, &play->colCtx, &initParams->pos, 3.0f, &waterBox, &bgId);
    this->rBgId = bgId;

    return 1;
}
