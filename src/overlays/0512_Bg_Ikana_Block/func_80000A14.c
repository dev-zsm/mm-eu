// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_block.h"

void BgIkanaBlock_Update(Actor* thisx, PlayState* play) {
    BgIkanaBlock* this = (BgIkanaBlock*)thisx;

    if ((this->dyna.actor.shape.rot.x != this->unk_174.x) || (this->dyna.actor.shape.rot.y != this->unk_174.y) ||
        (this->dyna.actor.shape.rot.z != this->unk_174.z)) {
        this->unk_174 = this->dyna.actor.shape.rot;
        ref_func_80B7ED54(this);
    }

    this->actionFunc(this, play);

    Actor_SetFocus(&this->dyna.actor, 30.0f);

    if (this->unk_17E != 0) {
        if (this->unk_17F > 0) {
            this->unk_17F--;
            CutsceneManager_Stop(this->dyna.actor.csId);
            this->unk_17E = 0;
        } else if (CutsceneManager_IsNext(this->dyna.actor.csId)) {
            CutsceneManager_StartWithPlayerCs(this->dyna.actor.csId, &this->dyna.actor);
            this->unk_17F = 30;
        } else {
            CutsceneManager_Queue(this->dyna.actor.csId);
        }
    }
}
