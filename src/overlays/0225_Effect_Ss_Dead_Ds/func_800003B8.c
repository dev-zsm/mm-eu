// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_dead_ds.h"

void EffectSsDeadDs_Update(PlayState* play, u32 index, EffectSs* this) {
    if (this->life < this->rHalfOfLife) {

        this->rScale += this->rScaleStep;
        if (this->rScale < 0) {
            this->rScale = 0;
        }

        this->rAlpha -= this->rAlphaStep;
        if (this->rAlpha < 0) {
            this->rAlpha = 0;
        }
    }
}
