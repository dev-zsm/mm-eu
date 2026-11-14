// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTrt_BeginInteraction), score 2.00 (2 differ, size +2)
#include "generated/mm/z_en_trt.h"

void func_80001E58(EnTrt* this, PlayState* play) {
    s16 curFrame = this->skelAnime.curFrame / this->skelAnime.playSpeed;
    s16 endFrame = Animation_GetLastFrame(&gKotakeWakeUpAnim) / TRUNCF_BINANG(this->skelAnime.playSpeed);

    if (this->cutsceneState == ENTRT_CUTSCENESTATE_WAITING) {
        if (CutsceneManager_IsNext(this->csId)) {
            CutsceneManager_StartWithPlayerCsAndSetFlag(this->csId, &this->actor);
            this->cutsceneState = ENTRT_CUTSCENESTATE_PLAYING_SPECIAL;
        } else {
            CutsceneManager_Queue(this->csId);
        }
    } else if (this->cutsceneState == ENTRT_CUTSCENESTATE_PLAYING_SPECIAL) {
        if (this->animIndex != TRT_ANIM_HANDS_ON_COUNTER) {
            if (curFrame == endFrame) {
                EnTrt_ChangeAnim(&this->skelAnime, sAnimationInfo, TRT_ANIM_WAKE_UP);
                this->animIndex = TRT_ANIM_WAKE_UP;
                this->blinkFunc = EnTrt_OpenEyesThenSetToBlink;
                this->timer = 10;
                this->cutsceneState = ENTRT_CUTSCENESTATE_PLAYING;
                Actor_PlaySfx(&this->actor, NA_SE_EN_KOTAKE_SURPRISED2);
            }
        } else {
            this->blinkFunc = EnTrt_OpenEyesThenSetToBlink;
            this->timer = 10;
            this->cutsceneState = ENTRT_CUTSCENESTATE_PLAYING;
        }
    } else if (DECR(this->timer) == 0) {
        this->timer = Rand_S16Offset(40, 20);
        EnTrt_ChangeAnim(&this->skelAnime, sAnimationInfo, TRT_ANIM_HANDS_ON_COUNTER);
        Message_StartTextbox(play, this->textId, &this->actor);
        this->animIndex = TRT_ANIM_HANDS_ON_COUNTER;
        switch (this->textId) {
            case 0x834:
                if (!CHECK_WEEKEVENTREG(WEEKEVENTREG_SAVED_KOUME) &&
                    !CHECK_WEEKEVENTREG(WEEKEVENTREG_RECEIVED_RED_POTION_FOR_KOUME) &&
                    !CHECK_WEEKEVENTREG(WEEKEVENTREG_TALKED_KOUME_INJURED) &&
                    !CHECK_WEEKEVENTREG(WEEKEVENTREG_TALKED_KOUME_KIOSK_EMPTY)) {
                    Interface_SetAButtonDoAction(play, DO_ACTION_DECIDE);
                    this->stickLeftPrompt.isEnabled = false;
                    this->stickRightPrompt.isEnabled = true;
                    this->actionFunc = EnTrt_Hello;
                } else {
                    this->actionFunc = EnTrt_StartRedPotionConversation;
                }
                break;

            case 0x83E:
                Interface_SetAButtonDoAction(play, DO_ACTION_DECIDE);
                this->stickLeftPrompt.isEnabled = false;
                this->stickRightPrompt.isEnabled = true;
                this->actionFunc = EnTrt_FaceShopkeeper;
                break;

            case 0x850:
            case 0x890:
                this->actionFunc = EnTrt_SetupEndInteraction;
                break;

            case 0x88F:
                this->actionFunc = EnTrt_StartRedPotionConversation;
                break;

            default:
                break;
        }
    }
}
