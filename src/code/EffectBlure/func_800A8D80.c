// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_blure.h"

s32 EffectBlure_Update(void* thisx) {
    EffectBlure* this = (EffectBlure*)thisx;
    s32 i;

    if (this == NULL) {
        return 0;
    }

    if (this->numElements == 0) {
        return 0;
    }

    while (true) {
        if (this->elements[0].state == 0) {
            for (i = 0; i < ARRAY_COUNT(this->elements) - 1; i++) {
                this->elements[i] = this->elements[i + 1];
            }

            this->elements[i].state = 2;
            this->elements[i].p1.x = 0;
            this->elements[i].p1.y = 0;
            this->elements[i].p1.z = 0;
            this->elements[i].p2.x = 0;
            this->elements[i].p2.y = 0;
            this->elements[i].p2.z = 0;
            this->elements[i].flags = 0;
            this->elements[i].timer = 0;

            this->numElements--;
            if (this->numElements <= 0) {
                this->numElements = 0;
                return 0;
            }
        } else {
            break;
        }
    }

    if (this->elements[0].state == 2) {
        return 0;
    }

    for (i = 0; i < this->numElements; i++) {
        this->elements[i].timer++;
    }

    if (this->elemDuration < this->elements[0].timer) {
        for (i = 0; i < ARRAY_COUNT(this->elements) - 1; i++) {
            this->elements[i] = this->elements[i + 1];
            if (this->elements[i].timer >= this->elemDuration) {
                this->elements[i].timer = this->elemDuration;
            }
        }

        this->elements[i].state = 2;
        this->elements[i].p1.x = 0;
        this->elements[i].p1.y = 0;
        this->elements[i].p1.z = 0;
        this->elements[i].p2.x = 0;
        this->elements[i].p2.y = 0;
        this->elements[i].p2.z = 0;
        this->elements[i].flags = 0;
        this->elements[i].timer = 0;

        this->numElements--;
        if (this->numElements <= 0) {
            this->numElements = 0;
            return 0;
        }
        return 0;
    }

    for (i = 0; i < this->numElements; i++) {
        if (this->elements[i].timer >= this->elemDuration) {
            this->elements[i].timer = this->elemDuration;
        }
    }

    this->addAngle += this->addAngleChange;
    return 0;
}
