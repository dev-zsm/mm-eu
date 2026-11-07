// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_hitmark.h"

u32 EffectSsHitmark_Init(PlayState* play, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsHitmarkInitParams* initParams = PARAMS;
    s32 colorIndex;

    this->pos = initParams->pos;
    this->gfx = gEffHitmarkDL;

    if (initParams->type == EFFECT_HITMARK_DUST) {
        this->life = 16;
    } else {
        this->life = 8;
    }

    this->draw = EffectSsHitmark_Draw;
    this->update = EffectSsHitmark_Update;

    colorIndex = initParams->type * 4;
    this->rTexIndex = 0;
    this->rType = initParams->type;
    this->rPrimColorR = sColors[colorIndex].r;
    this->rPrimColorG = sColors[colorIndex].g;
    this->rPrimColorB = sColors[colorIndex].b;
    this->rEnvColorR = sColors[colorIndex + 1].r;
    this->rEnvColorG = sColors[colorIndex + 1].g;
    this->rEnvColorB = sColors[colorIndex + 1].b;
    this->rScale = initParams->scale;

    return 1;
}
