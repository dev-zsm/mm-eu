// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fbdemo_wipe4.h"

void TransitionWipe4_Update(void* thisx, s32 updateRate) {
    TransitionWipe4* this = (TransitionWipe4*)thisx;

    this->progress += (this->baseSpeed * 3.0f) / updateRate;
    if (this->progress >= 1.0f) {
        this->progress = 1.0f;
        this->isDone = true;
    }
}
