// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_spark.h"

void EffectSpark_Init(void* thisx, void* initParamsx) {
    EffectSpark* this = (EffectSpark*)thisx;
    EffectSparkInit* initParams = (EffectSparkInit*)initParamsx;

    f32 velocityNorm;
    s32 i;

    if ((this != NULL) && (initParams != NULL)) {
        if ((initParams->uDiv == 0) || (initParams->vDiv == 0)) {
            return;
        }

        this->position = initParams->position;
        this->speed = initParams->speed;
        this->gravity = initParams->gravity;
        this->uDiv = initParams->uDiv;
        this->vDiv = initParams->vDiv;
        this->colorStart[0].r = initParams->colorStart[0].r;
        this->colorStart[0].g = initParams->colorStart[0].g;
        this->colorStart[0].b = initParams->colorStart[0].b;
        this->colorStart[0].a = initParams->colorStart[0].a;
        this->colorStart[1].r = initParams->colorStart[1].r;
        this->colorStart[1].g = initParams->colorStart[1].g;
        this->colorStart[1].b = initParams->colorStart[1].b;
        this->colorStart[1].a = initParams->colorStart[1].a;
        this->colorStart[2].r = initParams->colorStart[2].r;
        this->colorStart[2].g = initParams->colorStart[2].g;
        this->colorStart[2].b = initParams->colorStart[2].b;
        this->colorStart[2].a = initParams->colorStart[2].a;
        this->colorStart[3].r = initParams->colorStart[3].r;
        this->colorStart[3].g = initParams->colorStart[3].g;
        this->colorStart[3].b = initParams->colorStart[3].b;
        this->colorStart[3].a = initParams->colorStart[3].a;
        this->colorEnd[0].r = initParams->colorEnd[0].r;
        this->colorEnd[0].g = initParams->colorEnd[0].g;
        this->colorEnd[0].b = initParams->colorEnd[0].b;
        this->colorEnd[0].a = initParams->colorEnd[0].a;
        this->colorEnd[1].r = initParams->colorEnd[1].r;
        this->colorEnd[1].g = initParams->colorEnd[1].g;
        this->colorEnd[1].b = initParams->colorEnd[1].b;
        this->colorEnd[1].a = initParams->colorEnd[1].a;
        this->colorEnd[2].r = initParams->colorEnd[2].r;
        this->colorEnd[2].g = initParams->colorEnd[2].g;
        this->colorEnd[2].b = initParams->colorEnd[2].b;
        this->colorEnd[2].a = initParams->colorEnd[2].a;
        this->colorEnd[3].r = initParams->colorEnd[3].r;
        this->colorEnd[3].g = initParams->colorEnd[3].g;
        this->colorEnd[3].b = initParams->colorEnd[3].b;
        this->colorEnd[3].a = initParams->colorEnd[3].a;
        this->duration = initParams->duration;

        this->numElements = (this->uDiv * this->vDiv) + 2;
        if (this->numElements > ARRAY_COUNT(this->elements)) {
            return;
        }

        for (i = 0; i < this->numElements; i++) {
            EffectSparkElement* elem = &this->elements[i];

            elem->position.x = this->position.x;
            elem->position.y = this->position.y;
            elem->position.z = this->position.z;
            elem->velocity.x = Rand_ZeroOne() - 0.5f;
            elem->velocity.y = Rand_ZeroOne() - 0.5f;
            elem->velocity.z = Rand_ZeroOne() - 0.5f;

            velocityNorm = sqrtf(SQXYZ(elem->velocity));

            if (!(fabsf(velocityNorm) < 0.008f)) {
                elem->velocity.x *= this->speed * (1.0f / velocityNorm);
                elem->velocity.y *= this->speed * (1.0f / velocityNorm);
                elem->velocity.z *= this->speed * (1.0f / velocityNorm);
            } else {
                elem->velocity.x = elem->velocity.z = 0.0f;
                elem->velocity.y = this->speed;
            }

            elem->unkVelocity.x = 30000.0f - Rand_ZeroOne() * 15000.0f;
            elem->unkVelocity.y = 30000.0f - Rand_ZeroOne() * 15000.0f;
            elem->unkVelocity.z = 30000.0f - Rand_ZeroOne() * 15000.0f;
            elem->unkPosition.x = Rand_ZeroOne() * 65534.0f;
            elem->unkPosition.y = Rand_ZeroOne() * 65534.0f;
            elem->unkPosition.z = Rand_ZeroOne() * 65534.0f;
        }

        this->timer = 0;
    }
}
