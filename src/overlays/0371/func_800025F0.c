// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_trt.h"

void func_800025F0(EnTrt* this, PlayState* play) {
    u8 talkState = Message_GetState(&play->msgCtx);
    Player* player = GET_PLAYER(play);

    if (Actor_TalkOfferAccepted(&this->actor, &play->state)) {
        Message_StartTextbox(play, this->textId, &this->actor);
    } else {
        if ((player->actor.world.pos.x >= -50.0f) && (player->actor.world.pos.x <= 50.0f) &&
        (player->actor.world.pos.z >= -19.0f) && (player->actor.world.pos.z <= 30.0f)) {
            Actor_OfferTalk(&this->actor, play, 200.0f);
        }
    }
    if ((talkState == TEXT_STATE_DONE) && Message_ShouldAdvance(play)) {
        if (CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_WOODFALL_TEMPLE)) {
            play->nextEntrance = ENTRANCE(SOUTHERN_SWAMP_CLEARED, 5);
        } else {
            play->nextEntrance = ENTRANCE(SOUTHERN_SWAMP_POISONED, 5);
        }
        play->transitionType = TRANS_TYPE_64;
        gSaveContext.nextTransitionType = TRANS_TYPE_64;
        play->transitionTrigger = TRANS_TRIGGER_START;
    }
}
