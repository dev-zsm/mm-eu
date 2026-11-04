// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_shield_particle.h"

s32 EffectShieldParticle_Update(void* thisx) {
    EffectShieldParticle* this = (EffectShieldParticle*)thisx;
    EffectShieldParticleElement* elem;

    if (this == NULL) {
        return 0;
    }

    for (elem = &this->elements[0]; elem < &this->elements[this->numElements]; elem++) {
        elem->endXChange -= this->deceleration;
        if (elem->endXChange < 0.0f) {
            elem->endXChange = 0.0f;
        }

        if (elem->startXChange > 0.0f) {
            elem->startXChange -= this->deceleration;
            if (elem->startXChange < 0.0f) {
                elem->startXChange = 0.0f;
            }
        }

        elem->endX += elem->endXChange;
        elem->startX += elem->startXChange;

        if ((elem->startXChange == 0.0f) && (this->lengthCutoff < (elem->endX - elem->startX))) {
            elem->startXChange = elem->initialSpeed;
        }
    }

    if (this->lightDecay == true) {
        this->lightInfo.params.point.radius /= 2;
    }

    this->timer++;

    if (this->duration < this->timer) {
        return 1;
    }

    return 0;
}
