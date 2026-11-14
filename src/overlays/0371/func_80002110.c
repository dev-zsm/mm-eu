// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_trt.h"

void func_80002110(EnTrt* this, PlayState* play) {
    if (this->cutsceneState == ENTRT_CUTSCENESTATE_WAITING) {
        if (CutsceneManager_IsNext(this->csId)) {
            CutsceneManager_StartWithPlayerCsAndSetFlag(this->csId, &this->actor);
            this->cutsceneState = ENTRT_CUTSCENESTATE_PLAYING_SPECIAL;
        } else {
            CutsceneManager_Queue(this->csId);
        }
    } else if (this->cutsceneState == ENTRT_CUTSCENESTATE_PLAYING_SPECIAL) {
        if (DECR(this->timer) == 0) {
            EnTrt_ChangeAnim(&this->skelAnime, sAnimationInfo, TRT_ANIM_SURPRISED);
            this->animIndex = TRT_ANIM_SURPRISED;
            this->blinkFunc = EnTrt_OpenEyes2;
            Actor_PlaySfx(&this->actor, NA_SE_EN_KOTAKE_SURPRISED);
            this->timer = 30;
            this->cutsceneState = ENTRT_CUTSCENESTATE_PLAYING;
        }
    } else if (DECR(this->timer) == 0) {
        this->timer = Rand_S16Offset(40, 20);
        EnTrt_ChangeAnim(&this->skelAnime, sAnimationInfo, TRT_ANIM_HANDS_ON_COUNTER);
        Message_StartTextbox(play, this->textId, &this->actor);
        this->animIndex = TRT_ANIM_HANDS_ON_COUNTER;
        this->actionFunc = EnTrt_TryToGiveRedPotionAfterSurprised;
    }
}
