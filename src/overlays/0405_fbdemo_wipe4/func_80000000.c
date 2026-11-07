// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fbdemo_wipe4.h"

void TransitionWipe4_Start(void* thisx) {
    TransitionWipe4* this = (TransitionWipe4*)thisx;

    this->isDone = false;

    switch (this->speedType) {
        default:
            this->baseSpeed = 0.2f;
            break;

        case 0:
            this->baseSpeed = 0.1f;
            break;

        case 1:
            this->baseSpeed = 0.05f;
            break;
    }

    switch (this->colorType) {
        default:
            this->primColor.rgba = RGBA8(160, 160, 160, 255);
            break;

        case 0:
            this->primColor.rgba = RGBA8(0, 0, 0, 255);
            break;

        case 1:
            this->primColor.rgba = RGBA8(160, 160, 160, 255);
            break;
    }
}
