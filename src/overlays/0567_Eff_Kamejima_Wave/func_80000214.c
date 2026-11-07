// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_kamejima_wave.h"

void ref_func_80BCED34(EffKamejimaWave* this, PlayState* play) {
    this->actor.scale.y += this->scaleOffset;
    this->scaleOffset -= 0.002f;
    this->actor.shape.rot.x += 0x8C;
    if (this->scaleOffset < 0.0f) {
        this->actor.scale.x += 0.002f;
    }
    if (this->scaleOffset < 0.0f) {
        this->scaleOffset = 0;
    }
    if (sVtxAlpha >= 4) {
        sVtxAlpha -= 4;
    } else {
        this->actor.scale.y = 0.0f;
        this->actionFunc = ref_func_80BCEDE0;
        this->actor.draw = NULL;
    }
}
