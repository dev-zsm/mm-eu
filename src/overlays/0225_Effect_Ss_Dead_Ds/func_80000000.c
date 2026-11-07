// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_dead_ds.h"

u32 EffectSsDeadDs_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsDeadDsInitParams* initParams = PARAMS;

    this->pos = initParams->pos;
    this->velocity = initParams->velocity;
    this->accel = initParams->accel;
    this->life = initParams->life;
    this->rScaleStep = initParams->scaleStep;
    this->rHalfOfLife = initParams->life / 2;
    this->rAlphaStep = initParams->alpha / this->rHalfOfLife;
    this->draw = EffectSsDeadDs_Draw;
    this->update = EffectSsDeadDs_Update;
    this->rScale = initParams->scale;
    this->rAlpha = initParams->alpha;
    this->rTimer = 0;

    return 1;
}
