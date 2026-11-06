// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_kamejima_wave.h"

void ref_func_80BCEBC0(EffKamejimaWave* this, PlayState* play) {
    this->actor.scale.y += this->scaleOffset;
    this->scaleOffset -= 0.003f;
    this->actor.shape.rot.x += 0x64;
    if (this->scaleOffset < 0.0f) {
        this->actor.scale.x += 0.003f;
    }
    if (this->scaleOffset < -0.01f) {
        this->scaleOffset = -0.01f;
    }
    if (this->actor.scale.y < 0.0f) {
        this->actor.scale.y = 0.0f;
        this->actor.scale.x = 0.2f;
        this->actionFunc = ref_func_80BCEC6C;
        this->actor.draw = NULL;
    }
}
