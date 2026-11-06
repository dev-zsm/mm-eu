// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_haka_curtain.h"

void ref_func_80B6DD9C(BgHakaCurtain* this, PlayState* play) {
    if (this->dyna.actor.world.pos.y < this->dyna.actor.home.pos.y + 150.0f - 30.0f) {
        Math_StepToF(&this->dyna.actor.velocity.y, 1.6f, 0.12f);
    } else {
        Math_StepToF(&this->dyna.actor.velocity.y, 0.8f, 0.05f);
    }
    this->dyna.actor.world.pos.y += this->dyna.actor.velocity.y;
    if (this->dyna.actor.home.pos.y + 150.0f < this->dyna.actor.world.pos.y) {
        ref_func_80B6DE80(this);
        return;
    }
    Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_CURTAIN_DOWN - SFX_FLAG);
}
