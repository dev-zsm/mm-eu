// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fbdemo_wipe5.h"

void TransitionWipe5_Update(void* thisx, s32 updateRate) {
    TransitionWipe5* this = (TransitionWipe5*)thisx;

    if (this->unk_10 == 0) {
        this->isDone = true;
    } else {
        this->unk_0C += (this->unk_08 * 3.0f) / updateRate;
        if (this->unk_0C >= 1.0f) {
            this->unk_0C = 1.0f;
            this->isDone = true;
        }
    }
}
