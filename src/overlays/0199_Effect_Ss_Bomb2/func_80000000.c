// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_bomb2.h"

u32 EffectSsBomb2_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsBomb2InitParams* initParams = PARAMS;

    Math_Vec3f_Copy(&this->pos, &initParams->pos);
    Math_Vec3f_Copy(&this->velocity, &initParams->velocity);
    Math_Vec3f_Copy(&this->accel, &initParams->accel);
    this->gfx = gEffBombExplosion1DL;
    this->life = 24;
    this->update = EffectSsBomb2_Update;
    this->draw = sDrawFuncs[initParams->drawMode];
    this->rScale = initParams->scale;
    this->rScaleStep = initParams->scaleStep;
    this->rPrimColorR = 255;
    this->rPrimColorG = 255;
    this->rPrimColorB = 255;
    this->rPrimColorA = 255;
    this->rEnvColorR = 0;
    this->rEnvColorG = 0;
    this->rEnvColorB = 200;

    return 1;
}
