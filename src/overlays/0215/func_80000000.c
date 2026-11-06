// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_k_fire.h"

u32 EffectSsKFire_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsKFireInitParams* initParams = PARAMS;

    this->pos = initParams->pos;
    this->velocity = initParams->velocity;
    this->accel = initParams->accel;
    this->life = 100;
    this->rScaleMax = initParams->scaleMax;
    this->rAlpha = 255;
    this->rScroll = Rand_ZeroFloat(5.0f) - 25;
    this->rType = initParams->type;
    this->draw = EffectSsKFire_Draw;
    this->update = EffectSsKFire_Update;

    return 1;
}
