// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_dead_dd.h"

void EffectSsDeadDd_Update(PlayState* play, u32 index, EffectSs* this) {
    this->rScale += this->rScaleStep;

    if (this->rScale < 0) {
        this->rScale = 0;
    }

    if (this->rAlphaMode != 0) {
        this->rAlpha += this->rAlphaStep;
        if (this->rAlpha > 255) {
            this->rAlpha = 255;
        }
    } else {
        if (this->rAlpha < this->rAlphaStep) {
            this->rAlpha = 0;
        } else {
            this->rAlpha -= this->rAlphaStep;
        }
    }
}
