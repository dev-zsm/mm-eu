// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dkjail_ivy.h"

void BgDkjailIvy_BeginCutscene(BgDkjailIvy* this, PlayState* play) {
    if (CutsceneManager_IsNext(this->dyna.actor.csId)) {
        CutsceneManager_StartWithPlayerCs(this->dyna.actor.csId, &this->dyna.actor);
        this->fadeOutTimer = 50;
        DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
        Flags_SetSwitch(play, BG_DKJAIL_GET_SWITCH_FLAG(&this->dyna.actor));
        BgDkjailIvy_IvyCutEffects(this, play);
        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_GRASS_WALL_BROKEN);
        BgDkjailIvy_SetupFadeOut(this);
    } else {
        CutsceneManager_Queue(this->dyna.actor.csId);
    }
}
