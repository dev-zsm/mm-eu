// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_bomb2.h"

void EffectSsBomb2_Update(PlayState* play, u32 index, EffectSs* this) {
    s32 divisor;

    this->rTexIndex = (23 - this->life) / 3;
    this->rScale += this->rScaleStep;

    if (this->rScaleStep == 30) {
        this->rDepth += 4;
    } else {
        this->rDepth += 2;
    }

    if ((this->life < 23) && (this->life > 13)) {
        divisor = this->life - 13;
        this->rPrimColorR = EffectSs_LerpInv(this->rPrimColorR, 255, divisor);
        this->rPrimColorG = EffectSs_LerpInv(this->rPrimColorG, 255, divisor);
        this->rPrimColorB = EffectSs_LerpInv(this->rPrimColorB, 150, divisor);
        this->rPrimColorA = EffectSs_LerpInv(this->rPrimColorA, 255, divisor);
        this->rEnvColorR = EffectSs_LerpInv(this->rEnvColorR, 150, divisor);
        this->rEnvColorG = EffectSs_LerpInv(this->rEnvColorG, 0, divisor);
        this->rEnvColorB = EffectSs_LerpInv(this->rEnvColorB, 0, divisor);
    } else if ((this->life < 14) && (this->life > -1)) {
        divisor = this->life + 1;
        this->rPrimColorR = EffectSs_LerpInv(this->rPrimColorR, 50, divisor);
        this->rPrimColorG = EffectSs_LerpInv(this->rPrimColorG, 50, divisor);
        this->rPrimColorB = EffectSs_LerpInv(this->rPrimColorB, 50, divisor);
        this->rPrimColorA = EffectSs_LerpInv(this->rPrimColorA, 150, divisor);
        this->rEnvColorR = EffectSs_LerpInv(this->rEnvColorR, 10, divisor);
        this->rEnvColorG = EffectSs_LerpInv(this->rEnvColorG, 10, divisor);
        this->rEnvColorB = EffectSs_LerpInv(this->rEnvColorB, 10, divisor);
    }
}
