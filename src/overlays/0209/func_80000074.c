// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_hahen.h"

u32 EffectSsHahen_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsHahenInitParams* initParams = PARAMS;

    this->pos = initParams->pos;
    this->velocity = initParams->velocity;
    this->accel = initParams->accel;
    this->life = 200;

    if (initParams->dList != NULL) {
        this->gfx = initParams->dList;
        this->rObjectId = initParams->objectId;
        EffectSsHahen_CheckForObject(this, play);
    } else {
        this->gfx = gEffFragments1DL;
        this->rObjectId = HAHEN_OBJECT_DEFAULT;
    }

    this->draw = EffectSsHahen_Draw;
    this->update = EffectSsHahen_Update;
    this->rFlags = initParams->flags;
    this->rScale = initParams->scale;
    this->rPitch = Rand_ZeroOne() * 314.0f;
    this->rYaw = Rand_ZeroOne() * 314.0f;
    this->rMinLife = 200 - initParams->life;

    return 1;
}
