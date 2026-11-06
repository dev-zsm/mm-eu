// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_keikoku_saku.h"

void ref_func_80A538E0(BgKeikokuSaku* this, PlayState* play) {
    Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_METALGATE_OPEN - SFX_FLAG);
    this->dyna.actor.world.pos.z -= 2.0f + BREG(8);
    if (this->dyna.actor.world.pos.z < (BREG(9) + 2660.0f)) {
        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_BRIDGE_OPEN_STOP);
        this->timer = 30;
        this->actionFunc = ref_func_80A53994;
    }
}
