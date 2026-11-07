// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_f40_flift.h"

void ref_func_808D7714(BgF40Flift* this, PlayState* play) {
    if (this->timer != 0) {
        this->timer--;
        this->dyna.actor.world.pos.y =
            (((Math_CosF(this->timer * (M_PIf / 96)) * this->dyna.actor.params) + 1.0f) * 463.4f) +
            this->dyna.actor.home.pos.y;
    } else {
        this->dyna.actor.params = -this->dyna.actor.params;
        this->actionFunc = ref_func_808D75F0;
    }
}
