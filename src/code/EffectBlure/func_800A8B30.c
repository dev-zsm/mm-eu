// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_blure.h"

void EffectBlure_Init1(void* thisx, void* initParamsx) {
    EffectBlure* this = (EffectBlure*)thisx;
    EffectBlureInit1* initParams = (EffectBlureInit1*)initParamsx;

    if ((this != NULL) && (initParams != NULL)) {
        s32 i;

        EffectBlure_InitElements(this);

        for (i = 0; i < EFFECT_BLURE_COLOR_COUNT; i++) {
            this->p1StartColor[i] = initParams->p1StartColor[i];
            this->p2StartColor[i] = initParams->p2StartColor[i];
            this->p1EndColor[i] = initParams->p1EndColor[i];
            this->p2EndColor[i] = initParams->p2EndColor[i];
        }

        this->elemDuration = initParams->elemDuration;
        this->unkFlag = initParams->unkFlag;
        this->calcMode = initParams->calcMode;
        this->flags = 0;
        this->addAngleChange = 0;
        this->addAngle = 0;
        this->drawMode = EFF_BLURE_DRAW_MODE_SIMPLE;
        this->altPrimColor.r = 0;
        this->altPrimColor.g = 0;
        this->altPrimColor.b = 0;
        this->altPrimColor.a = 0;
        this->altEnvColor.r = 0;
        this->altEnvColor.g = 0;
        this->altEnvColor.b = 0;
        this->altEnvColor.a = 0;
        this->mode4Param = 1.0f;
    }
}
