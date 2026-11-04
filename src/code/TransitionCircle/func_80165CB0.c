// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fbdemo_circle.h"

void* TransitionCircle_Init(void* thisx) {
    TransitionCircle* this = (TransitionCircle*)thisx;

    bzero(this, sizeof(TransitionCircle));
    this->maskType = 1;
    this->texture = gCircleTex;
    this->masks = 6;
    this->maskt = 6;
    this->unk_1E = 4;
    this->unk_1F = 0;

    return this;
}
