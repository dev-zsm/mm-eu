// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fbdemo_wipe3.h"

void TransitionWipe3_Update(void* thisx, s32 updateRate) {
    TransitionWipe3* this = (TransitionWipe3*)thisx;

    if (this->dir != TRANS_WIPE3_DIR_IN) {
        if ((this->scrollY == 0) && (this->texIndex == 2)) {
            Audio_PlaySfx_2(NA_SE_OC_SECRET_WARP_IN);
        }
        this->scrollY += (this->wipeSpeed * 3) / updateRate;
        if (this->scrollY >= 500) {
            this->scrollY = 500;
            this->isDone = true;
        }
    } else {
        this->scrollY -= (this->wipeSpeed * 3) / updateRate;
        if (this->scrollY <= 0) {
            this->scrollY = 0;
            this->isDone = true;
        }
    }
}
