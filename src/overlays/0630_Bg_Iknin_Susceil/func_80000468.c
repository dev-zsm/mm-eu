// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_iknin_susceil.h"

void ref_func_80C0ABA8(BgIkninSusceil* this, PlayState* play) {
    this->dyna.actor.velocity.y += -0.7f;
    this->dyna.actor.velocity.y *= 0.93f;
    this->dyna.actor.world.pos.y += this->dyna.actor.velocity.y;
    if (this->dyna.actor.world.pos.y <= this->dyna.actor.home.pos.y) {
        BgIkninSusceil_RequestQuakeAndRumble(this, play, 4, 14, 1);
        Flags_UnsetSwitch(play, SUSCEIL_GET_SWITCH_FLAG(&this->dyna.actor));
        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_BIGWALL_BOUND);
        ref_func_80C0AC74(this);
    } else {
        Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_ICE_PILLAR_FALL - SFX_FLAG);
    }
}
