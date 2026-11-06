// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_iknin_susceil.h"

void ref_func_80C0AD64(BgIkninSusceil* this, PlayState* play) {
    this->dyna.actor.velocity.y += 0.46f;
    this->dyna.actor.velocity.y *= 0.98f;
    if (Math_SmoothStepToF(&this->dyna.actor.world.pos.y, this->dyna.actor.home.pos.y + 365.0f, 0.5f,
                           this->dyna.actor.velocity.y, 1.0f) < 0.1f) {
        BgIkninSusceil_RequestQuakeAndRumble(this, play, 1, 14, 3);
        CutsceneManager_Stop(this->dyna.actor.csId);
        ref_func_80C0AB14(this);
    } else {
        Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_ICE_PILLAR_RISING - SFX_FLAG);
    }
}
