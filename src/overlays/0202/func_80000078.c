// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_d_fire.h"

u32 EffectSsDFire_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsDFireInitParams* initParams = PARAMS;

    if (EffectSsDFire_CheckForObject(this, play)) {
        Math_Vec3f_Copy(&this->pos, &initParams->pos);
        Math_Vec3f_Copy(&this->velocity, &initParams->velocity);
        Math_Vec3f_Copy(&this->accel, &initParams->accel);
        this->gfx = gDodongoFireDL;
        this->life = initParams->life;
        this->rScale = initParams->scale;
        this->rScaleStep = initParams->scaleStep;
        this->draw = EffectSsDFire_Draw;
        this->update = EffectSsDFire_Update;
        this->rTexIndex = (play->state.frames & 3) ^ 3; 
        this->rAlpha = initParams->alpha;
        this->rFadeDelay = this->life - initParams->fadeDelay;
        this->rAlphaStep = initParams->alphaStep;

        return 1;
    }

    return 0;
}
