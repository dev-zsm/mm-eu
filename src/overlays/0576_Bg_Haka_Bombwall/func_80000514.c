// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_haka_bombwall.h"

void BgHakaBombwall_PlayCutscene(BgHakaBombwall* this, PlayState* play) {
    if (CutsceneManager_IsNext(this->dyna.actor.csId)) {
        CutsceneManager_StartWithPlayerCs(this->dyna.actor.csId, &this->dyna.actor);
        ref_func_80BD5E6C(this, play);
        this->dyna.actor.draw = NULL;
        Flags_SetSwitch(play, BGHAKABOMBWALL_GET_SWITCH_FLAG(&this->dyna.actor));
#if MM_VERSION >= N64_US
        SoundSource_PlaySfxAtFixedWorldPos(play, &this->dyna.actor.world.pos, 60, NA_SE_EV_WALL_BROKEN);
#endif
        DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
        BgHakaBombwall_SetupEndCutscene(this);
    } else {
        CutsceneManager_Queue(this->dyna.actor.csId);
    }
}
