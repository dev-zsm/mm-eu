// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_kin2_bombwall.h"

void BgKin2Bombwall_PlayCutscene(BgKin2Bombwall* this, PlayState* play) {
    if (CutsceneManager_IsNext(this->dyna.actor.csId)) {
        CutsceneManager_StartWithPlayerCs(this->dyna.actor.csId, &this->dyna.actor);
        Flags_SetSwitch(play, BG_KIN2_BOMBWALL_GET_SWITCH_FLAG(&this->dyna.actor));
#if MM_VERSION >= N64_US
        SoundSource_PlaySfxAtFixedWorldPos(play, &this->dyna.actor.world.pos, 60, NA_SE_EV_WALL_BROKEN);
#endif
        DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
        this->dyna.actor.draw = NULL;
        BgKin2Bombwall_SpawnEffects(this, play);
        BgKin2Bombwall_SetupEndCutscene(this);

    } else {
        CutsceneManager_Queue(this->dyna.actor.csId);
    }
}
