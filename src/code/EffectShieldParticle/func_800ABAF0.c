// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_shield_particle.h"

void EffectShieldParticle_Init(void* thisx, void* initParamsx) {
    EffectShieldParticle* this = (EffectShieldParticle*)thisx;
    EffectShieldParticleInit* initParams = (EffectShieldParticleInit*)initParamsx;
    EffectShieldParticleElement* elem;

    if ((this != NULL) && (initParams != NULL)) {
        this->numElements = initParams->numElements;
        if (this->numElements > ARRAY_COUNT(this->elements)) {
            return;
        }

        this->position = initParams->position;
        this->primColorStart = initParams->primColorStart;
        this->envColorStart = initParams->envColorStart;
        this->primColorMid = initParams->primColorMid;
        this->envColorMid = initParams->envColorMid;
        this->primColorEnd = initParams->primColorEnd;
        this->envColorEnd = initParams->envColorEnd;
        this->deceleration = initParams->deceleration;
        this->maxInitialSpeed = initParams->maxInitialSpeed;
        this->lengthCutoff = initParams->lengthCutoff;
        this->duration = initParams->duration;
        this->timer = 0;

        for (elem = &this->elements[0]; elem < &this->elements[this->numElements]; elem++) {
            elem->initialSpeed = (Rand_ZeroOne() * (this->maxInitialSpeed * 0.5f)) + (this->maxInitialSpeed * 0.5f);
            elem->endX = 0.0f;
            elem->startXChange = 0.0f;
            elem->startX = 0.0f;
            elem->endXChange = elem->initialSpeed;
            elem->yaw = Rand_ZeroOne() * 65534.0f;
            elem->pitch = Rand_ZeroOne() * 65534.0f;
        }

        this->lightDecay = initParams->lightDecay;
        if (this->lightDecay == true) {
            this->lightInfo.type = LIGHT_POINT_NOGLOW;
            this->lightInfo.params.point = initParams->lightPoint;
            this->lightNode =
                LightContext_InsertLight(Effect_GetPlayState(), &Effect_GetPlayState()->lightCtx, &this->lightInfo);
        } else {
            this->lightNode = NULL;
        }
    }
}
