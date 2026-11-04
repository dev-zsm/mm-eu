// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fbdemo_wipe1.h"

void TransitionWipe1_Update(void* thisx, s32 updateRate) {
    TransitionWipe1* this = (TransitionWipe1*)thisx;

    if (this->direction != TRANS_WIPE1_DIR_IN) {
        this->texY += (((void)0, gSaveContext.transWipeSpeed) * 3) / updateRate;
        if (this->texY >= (s32)(153.0f * (1 << 2))) {
            this->texY = (s32)(153.0f * (1 << 2));
            this->isDone = true;
        }
    } else {
        this->texY -= (((void)0, gSaveContext.transWipeSpeed) * 3) / updateRate;
        if (this->texY <= (s32)(83.25f * (1 << 2))) {
            this->texY = (s32)(83.25f * (1 << 2));
            this->isDone = true;
        }
    }
}
