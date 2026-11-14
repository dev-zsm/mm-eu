// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTrt_IdleSleeping), score 1.00 (1 differ, size +1)
#include "generated/mm/z_en_trt.h"

void func_80001924(EnTrt* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (CHECK_WEEKEVENTREG(WEEKEVENTREG_FAILED_RECEIVED_RED_POTION_FOR_KOUME_SHOP) &&
        !CHECK_WEEKEVENTREG(WEEKEVENTREG_RECEIVED_RED_POTION_FOR_KOUME)) {
        this->textId = 0x88F;
    } else if (!(this->flags & ENTRT_TALKED)) {
        this->textId = 0x834;
    } else {
        this->textId = 0x83E;
    }
    if (!CHECK_WEEKEVENTREG(WEEKEVENTREG_GAVE_KOTAKE_MUSHROOM)) {
        this->talkOptionTextId = 0x845;
    } else if (this->flags & ENTRT_GIVEN_MUSHROOM) {
        this->talkOptionTextId = 0x882;
    } else {
        this->talkOptionTextId = 0x885;
    }
    this->prevTextId = this->textId;

    if ((player->transformation == PLAYER_FORM_GORON) || (player->transformation == PLAYER_FORM_ZORA) ||
        (player->transformation == PLAYER_FORM_DEKU)) {
        this->textId = 0x850;
    }
    if (Player_GetMask(play) == PLAYER_MASK_SCENTS) {
        this->textId = 0x890;
    }
    if (Actor_TalkOfferAccepted(&this->actor, &play->state)) {
        if (player->transformation == PLAYER_FORM_HUMAN) {
            this->flags |= ENTRT_TALKED;
        }
        if (this->cutsceneState == ENTRT_CUTSCENESTATE_STOPPED) {
            if (CutsceneManager_GetCurrentCsId() == CS_ID_GLOBAL_TALK) {
                CutsceneManager_Stop(CS_ID_GLOBAL_TALK);
            }
            this->csId = this->lookForwardCutscene;
            CutsceneManager_Queue(this->csId);
            this->cutsceneState = ENTRT_CUTSCENESTATE_WAITING;
        }
        player->stateFlags2 |= PLAYER_STATE2_20000000;
        this->timer = 45;
        this->actionFunc = EnTrt_BeginInteraction;
    } else if (((player->actor.world.pos.x >= -50.0f) && (player->actor.world.pos.x <= -25.0f)) &&
               ((player->actor.world.pos.z >= -19.0f) && (player->actor.world.pos.z <= 30.0f))) {
        Actor_OfferTalk(&this->actor, play, 200.0f);
    }
    if (DECR(this->timer) == 0) {
        this->timer = 40;
        EnTrt_ChangeAnim(&this->skelAnime, sAnimationInfo, TRT_ANIM_HALF_AWAKE);
        this->animIndex = TRT_ANIM_HALF_AWAKE;
        this->actionFunc = EnTrt_IdleAwake;
        this->blinkFunc = EnTrt_OpenThenCloseEyes;
    }
    if (DECR(this->sleepSoundTimer) == 0) {
        Actor_PlaySfx_Flagged(&this->actor, NA_SE_EN_KOTAKE_SLEEP - SFX_FLAG);
    }
}
