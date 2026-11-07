// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_nozoki.h"

void ref_func_80BA3230(ObjNozoki* this, PlayState* play) {
    if (CHECK_WEEKEVENTREG(WEEKEVENTREG_CAN_USE_CURIOSITY_SHOP_PEEPHOLE)) {
        Actor* npc = play->actorCtx.actorLists[ACTORCAT_NPC].first;
        Actor* test3 = SubS_FindActor(play, npc, ACTORCAT_NPC, ACTOR_EN_TEST3);

        if ((test3 != NULL) && (test3->draw != NULL)) {
            if ((play->curSpawn == 3) && !CHECK_WEEKEVENTREG(WEEKEVENTREG_64_40)) {
                this->dyna.actor.flags |=
                    (ACTOR_FLAG_ATTENTION_ENABLED | ACTOR_FLAG_FRIENDLY | ACTOR_FLAG_TALK_OFFER_AUTO_ACCEPTED);
                this->dyna.actor.textId = 0x297A;
            } else {
                this->dyna.actor.flags |= (ACTOR_FLAG_ATTENTION_ENABLED | ACTOR_FLAG_FRIENDLY);
                if (CHECK_WEEKEVENTREG(WEEKEVENTREG_64_40)) {
                    this->dyna.actor.textId = 0;
                } else {
                    this->dyna.actor.textId = 0x2979;
                }
            }

            if (Actor_TalkOfferAccepted(&this->dyna.actor, &play->state)) {
                ObjNozoki_SetupAction(this, ref_func_80BA3344);
            } else {
                Actor_OfferTalk(&this->dyna.actor, play, 50.0f);
            }
        }
    }
}
