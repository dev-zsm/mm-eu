// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_spout_fire.h"

void ref_func_80A60D10(BgSpoutFire* this, PlayState* play) {
    if (ref_func_80A60C24(this, play)) {
        Math_StepToF(&this->actor.scale.y, 0.1f, 2.5f * 0.01f);
    } else if (Math_StepToF(&this->actor.scale.y, 0.01f, 0.01f)) {
        this->actor.draw = NULL;
        this->actionFunc = ref_func_80A60C94;
    } else {
        this->timer = 0;
    }
}
