// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (TransitionTriforce_IsDone), score 2.00 (2 differ, size +2)
#include "generated/mm/z_fbdemo_triforce.h"

s32 func_8000052C(void* thisx) {
    TransitionTriforce* this = (TransitionTriforce*)thisx;

    if ((this->state == STATE_SPIRAL_IN_SLOW) || (this->state == STATE_SPIRAL_IN_FAST)) {
        return this->transPos <= 0.03f;
    } else if ((this->state == STATE_SPIRAL_OUT_SLOW) || (this->state == STATE_SPIRAL_OUT_FAST)) {
        return (this->transPos >= 1.0f);
    } else {
        return false;
    }
}
