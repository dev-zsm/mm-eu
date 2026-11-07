// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kzsaku.h"

void ObjKzsaku_Rise(ObjKzsaku* this, PlayState* play) {
    if (this->dyna.actor.csId != CS_ID_NONE) {
        if (CutsceneManager_IsNext(this->dyna.actor.csId)) {
            CutsceneManager_StartWithPlayerCs(this->dyna.actor.csId, &this->dyna.actor);
        } else {
            CutsceneManager_Queue(this->dyna.actor.csId);
        }
    }
    if (this->raisedAmount < 450.0f) {
        Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_METALDOOR_SLIDE - SFX_FLAG);
        this->raisedAmount += 15.0f;
    } else {
        ref_func_80C08C84(this);
    }
    this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y + this->raisedAmount;
}
