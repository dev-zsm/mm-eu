// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fbdemo_triforce.h"

void func_800000E4(void* thisx, s32 updateRate) {
    TransitionTriforce* this = (TransitionTriforce*)thisx;
    s32 i;

    for (i = updateRate; i > 0; i--) {
        if (this->state == STATE_SPIRAL_IN_SLOW) {
            this->transPos = CLAMP_MIN(this->transPos * (1.0f - this->step), 0.03f);
        } else if (this->state == STATE_SPIRAL_IN_FAST) {
            this->transPos = CLAMP_MIN(this->transPos - this->step, 0.03f);
        } else if (this->state == STATE_SPIRAL_OUT_SLOW) {
            this->transPos = CLAMP_MAX(this->transPos / (1.0f - this->step), 1.0f);
        } else if (this->state == STATE_SPIRAL_OUT_FAST) {
            this->transPos = CLAMP_MAX(this->transPos + this->step, 1.0f);
        }
    }
}
