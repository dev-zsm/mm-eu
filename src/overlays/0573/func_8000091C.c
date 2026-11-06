// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_bombwall.h"

void ref_func_80BD503C(BgIkanaBombwall* this, PlayState* play) {
    if (CutsceneManager_IsNext(this->dyna.actor.csId)) {
        CutsceneManager_StartWithPlayerCs(this->dyna.actor.csId, &this->dyna.actor);
        if (!BGIKANABOMBWALL_GET_100(&this->dyna.actor)) {
            ref_func_80BD4720(this, play);
        } else {
            ref_func_80BD4A14(this, play);
        }
        this->dyna.actor.draw = NULL;
#if MM_VERSION >= N64_US
        SoundSource_PlaySfxAtFixedWorldPos(play, &this->dyna.actor.world.pos, 60, NA_SE_EV_WALL_BROKEN);
#endif
        Flags_SetSwitch(play, BGIKANABOMBWALL_GET_SWITCH_FLAG(&this->dyna.actor));
        if (!BGIKANABOMBWALL_GET_100(&this->dyna.actor)) {
            DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
        }
        ref_func_80BD5118(this);
    } else {
        CutsceneManager_Queue(this->dyna.actor.csId);
    }
}
