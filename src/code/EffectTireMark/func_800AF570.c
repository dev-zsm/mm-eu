// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_tire_mark.h"

s32 EffectTireMark_Update(void* thisx) {
    EffectTireMark* this = (EffectTireMark*)thisx;
    s32 i;
    s32 j;

    if (this->numElements == 0) {
        return 0;
    }

    for (i = 0; i < this->numElements; i++) {
        this->elements[i].life--;
    }

    if (this->elements[0].life <= 0) {
        for (j = 0; j < ARRAY_COUNT(this->elements) - 1; j++) {
            this->elements[j] = this->elements[j + 1];
        }

        EffectTireMark_InitElement(&this->elements[j]);

        this->numElements--;
        if (this->numElements < 0) {
            this->numElements = 0;
        }
        return 0;
    }

    return 0;
}
