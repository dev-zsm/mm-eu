// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fbdemo_wipe5.h"

void TransitionWipe5_Start(void* thisx) {
    TransitionWipe5* this = (TransitionWipe5*)thisx;

    this->isDone = false;
    switch (this->unk_12) {
        case 0:
            this->unk_08 = 0.02f;
            break;

        case 1:
            this->unk_08 = 0.05f;
            break;

        default:
            this->unk_08 = 0.2f;
            break;
    }

    switch (this->unk_11) {
        case 0:
            this->primColor.rgba = RGBA8(0, 0, 0, 255);
            break;

        case 1:
            this->primColor.rgba = RGBA8(160, 160, 160, 255);
            break;

        default:
            this->primColor.rgba = RGBA8(160, 160, 160, 255);
            break;
    }
}
