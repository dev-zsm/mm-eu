// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTrt_IdleAwake), score 2.00 (2 differ, size +2)
#include "generated/mm/z_en_trt.h"

void func_80001C10(EnTrt* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    this->flags &= ~ENTRT_FULLY_AWAKE;
    if ((player->transformation == PLAYER_FORM_HUMAN) || (player->transformation == PLAYER_FORM_FIERCE_DEITY)) {
        if (Player_GetMask(play) == PLAYER_MASK_SCENTS) {
            this->textId = 0x890;
        } else {
            this->textId = this->prevTextId;
        }
    } else {
        this->textId = 0x850;
    }
    if (Actor_TalkOfferAccepted(&this->actor, &play->state)) {
        if (this->cutsceneState == ENTRT_CUTSCENESTATE_STOPPED) {
            if (CutsceneManager_GetCurrentCsId() == CS_ID_GLOBAL_TALK) {
                CutsceneManager_Stop(CS_ID_GLOBAL_TALK);
            }
            this->csId = this->lookForwardCutscene;
            CutsceneManager_Queue(this->csId);
            this->cutsceneState = ENTRT_CUTSCENESTATE_WAITING;
        }
        player->stateFlags2 |= PLAYER_STATE2_20000000;
        if (player->transformation == PLAYER_FORM_HUMAN) {
            this->flags |= ENTRT_TALKED;
        }
        EnTrt_ChangeAnim(&this->skelAnime, sAnimationInfo, TRT_ANIM_SLEEPING);
        this->blinkFunc = EnTrt_EyesClosed;
        this->timer = 45;
        this->actionFunc = EnTrt_BeginInteraction;
    } else if ((player->actor.world.pos.x >= -50.0f) && (player->actor.world.pos.x <= -25.0f) &&
               (player->actor.world.pos.z >= -19.0f) && (player->actor.world.pos.z <= 30.0f)) {
        Actor_OfferTalk(&this->actor, play, 200.0f);
    }
    if (DECR(this->timer) == 0) {
        this->timer = Rand_S16Offset(150, 100);
        EnTrt_ChangeAnim(&this->skelAnime, sAnimationInfo, TRT_ANIM_SLEEPING);
        this->animIndex = TRT_ANIM_SLEEPING;
        this->sleepSoundTimer = 10;
        this->actor.textId = 0;
        this->actionFunc = EnTrt_IdleSleeping;
        this->blinkFunc = EnTrt_EyesClosed;
    }
}
