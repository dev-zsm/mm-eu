// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_nozoki.h"

void ref_func_80BA3344(ObjNozoki* this, PlayState* play) {
    if ((play->curSpawn == 3) && !CHECK_WEEKEVENTREG(WEEKEVENTREG_64_40)) {
        if (Actor_TextboxIsClosing(&this->dyna.actor, play)) {
            SET_WEEKEVENTREG(WEEKEVENTREG_64_40);
            this->dyna.actor.flags &= ~ACTOR_FLAG_TALK_OFFER_AUTO_ACCEPTED;
            ObjNozoki_SetupAction(this, ref_func_80BA3230);
        }
    } else if ((this->dyna.actor.textId == 0) || Actor_TextboxIsClosing(&this->dyna.actor, play)) {
        play->nextEntrance = ENTRANCE(CURIOSITY_SHOP, 2);
        play->transitionTrigger = TRANS_TRIGGER_START;
    }
}
