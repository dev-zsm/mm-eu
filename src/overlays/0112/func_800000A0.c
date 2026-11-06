// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_f40_flift.h"

void ref_func_808D75F0(BgF40Flift* this, PlayState* play) {
    if (((this->dyna.actor.params == 1) && DynaPolyActor_IsPlayerOnTop(&this->dyna)) ||
        ((this->dyna.actor.params == -1) && !DynaPolyActor_IsPlayerOnTop(&this->dyna))) {
        this->timer = 96;
        this->actionFunc = ref_func_808D7714;
    } else {
        if (this->timer == 0) {
            this->timer = 48;
        }
        this->timer--;
        if (this->dyna.actor.params == 1) {
            this->dyna.actor.world.pos.y = (Math_SinF(this->timer * (M_PIf / 24)) * 5.0f) + this->dyna.actor.home.pos.y;
        } else {
            this->dyna.actor.world.pos.y =
                (Math_SinF(this->timer * (M_PIf / 24)) * 5.0f) + (926.8f + this->dyna.actor.home.pos.y);
        }
    }
}
