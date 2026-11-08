// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_dust.h"

void EffectSsDust_UpdateFire(PlayState* play, u32 index, EffectSs* this) {
    this->accel.x = (Rand_ZeroOne() * 0.4f) - 0.2f;
    this->accel.z = (Rand_ZeroOne() * 0.4f) - 0.2f;

    switch (this->rTexIndex) {
        case 0:
            this->rPrimColorR = 255;
            this->rPrimColorG = 150;
            this->rPrimColorB = 0;
            this->rEnvColorR = 150;
            this->rEnvColorG = 50;
            this->rEnvColorB = 0;
            break;

        case 1:
            this->rPrimColorR = 200;
            this->rPrimColorG = 50;
            this->rPrimColorB = 0;
            this->rEnvColorR = 100;
            this->rEnvColorG = 0;
            this->rEnvColorB = 0;
            break;

        case 2:
            this->rPrimColorR = 50;
            this->rPrimColorG = 0;
            this->rPrimColorB = 0;
            this->rEnvColorR = 0;
            this->rEnvColorG = 0;
            this->rEnvColorB = 0;
            break;

        case 3:
            this->rPrimColorR = 50;
            this->rEnvColorR = this->rPrimColorG = this->rEnvColorG = this->rPrimColorB = this->rEnvColorB = 0;
            break;
    }

    if (this->rTexIndex < (ARRAY_COUNT(sDustTextures) - 1)) {
        this->rTexIndex++;
    }

    this->rScale += this->rScaleStep;
}
