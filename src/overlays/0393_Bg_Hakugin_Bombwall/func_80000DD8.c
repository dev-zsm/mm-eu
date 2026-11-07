// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_bombwall.h"

void ref_func_80ABCD98(BgHakuginBombwall* this, PlayState* play) {
    s32 pad;

    if (CutsceneManager_IsNext(this->dyna.actor.csId)) {
        BgHakuginBombwallStruct* ptr = &ref_D_80ABCFC0[BGHAKUGIN_BOMBWALL_100(&this->dyna.actor)];

        CutsceneManager_StartWithPlayerCs(this->dyna.actor.csId, &this->dyna.actor);
        ptr->unk_24(this, play);
        this->dyna.actor.draw = NULL;
        this->unk_1AC = 20;
        Flags_SetSwitch(play, BGHAKUGIN_BOMBWALL_SWITCH_FLAG(&this->dyna.actor));
        DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
        this->actionFunc = ref_func_80ABCE60;
    } else {
        CutsceneManager_Queue(this->dyna.actor.csId);
    }
}
