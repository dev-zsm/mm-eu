// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_hitmark.h"

void EffectSsHitmark_Update(PlayState* play, u32 index, EffectSs* this) {
    s32 colorIndex;

    if (this->rType == EFFECT_HITMARK_DUST) {
        this->rTexIndex = (15 - this->life) / 2;
    } else {
        this->rTexIndex = 7 - this->life;
    }

    if (this->rTexIndex != 0) {
        colorIndex = this->rType * 4 + 2;
        this->rPrimColorR = EffectSs_LerpInv(this->rPrimColorR, sColors[colorIndex].r, this->life + 1);
        this->rPrimColorG = EffectSs_LerpInv(this->rPrimColorG, sColors[colorIndex].g, this->life + 1);
        this->rPrimColorB = EffectSs_LerpInv(this->rPrimColorB, sColors[colorIndex].b, this->life + 1);
        this->rEnvColorR = EffectSs_LerpInv(this->rEnvColorR, sColors[colorIndex + 1].r, this->life + 1);
        this->rEnvColorG = EffectSs_LerpInv(this->rEnvColorG, sColors[colorIndex + 1].g, this->life + 1);
        this->rEnvColorB = EffectSs_LerpInv(this->rEnvColorB, sColors[colorIndex + 1].b, this->life + 1);
    }
}
