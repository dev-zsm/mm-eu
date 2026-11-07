// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_dead_db.h"

void EffectSsDeadDb_Update(PlayState* play, u32 index, EffectSs* this) {
    this->rTexIndex = (f32)((this->rTotalLife - this->life) * 9) / this->rTotalLife;
    this->rScale += this->rScaleStep;

    this->rPrimColorR -= 10;
    if (this->rPrimColorR < 0) {
        this->rPrimColorR = 0;
    }

    this->rPrimColorG -= 10;
    if (this->rPrimColorG < 0) {
        this->rPrimColorG = 0;
    }

    this->rPrimColorB -= 10;
    if (this->rPrimColorB < 0) {
        this->rPrimColorB = 0;
    }

    this->rEnvColorR -= 10;
    if (this->rEnvColorR < 0) {
        this->rEnvColorR = 0;
    }

    this->rEnvColorG -= 10;
    if (this->rEnvColorG < 0) {
        this->rEnvColorG = 0;
    }

    this->rEnvColorB -= 10;
    if (this->rEnvColorB < 0) {
        this->rEnvColorB = 0;
    }
}
