// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_tire_mark.h"

void EffectTireMark_Init(void* thisx, void* initParamsx) {
    EffectTireMark* this = (EffectTireMark*)thisx;
    EffectTireMarkInit* initParams = (EffectTireMarkInit*)initParamsx;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(this->elements); i++) {
        EffectTireMark_InitElement(&this->elements[i]);
    }

    this->unk600 = initParams->unk0;
    this->numElements = 0;

    if (initParams->elemDuration > 62) {
        this->elemDuration = 62;
    } else {
        this->elemDuration = initParams->elemDuration;
    }

    this->color = initParams->color;
}
