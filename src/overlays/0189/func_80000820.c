// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kakasi.h"

void func_80000820(EnKakasi* this, PlayState* play) {
    u32 day = gSaveContext.save.day;
    s16 screenPosX;
    s16 screenPosY;


    this->picto.actor.textId = 0x1644;
    if (Actor_OcarinaInteractionAccepted(&this->picto.actor, &play->state)) {
        this->skelAnime.playSpeed = 1.0f;
        EnKakasi_SetupSongTeach(this, play);
        return;
    }
    if (Actor_TalkOfferAccepted(&this->picto.actor, &play->state)) {
        this->skelAnime.playSpeed = 1.0f;
        EnKakasi_SetupDialogue(this);
        return;
    }
    if (play->actorCtx.flags & ACTORCTX_FLAG_PICTO_BOX_ON) {
        Actor_GetScreenPos(play, &this->picto.actor, &screenPosX, &screenPosY);
        if ((this->picto.actor.projectedPos.z > -20.0f) && (screenPosX > 0) && (screenPosX < SCREEN_WIDTH) &&
        (screenPosY > 0) && (screenPosY < SCREEN_HEIGHT) && (this->animIndex != ENKAKASI_ANIM_SIDEWAYS_SHAKING)) {

            EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_SIDEWAYS_SHAKING);
            this->skelAnime.playSpeed = 2.0f;
        }
    } else if (Player_GetMask(play) == PLAYER_MASK_KAMARO) {
        if (this->animIndex != ENKAKASI_ANIM_SIDEWAYS_SHAKING) {
            EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_SIDEWAYS_SHAKING);
            this->skelAnime.playSpeed = 2.0f;
        }
    } else if ((day == 3) && gSaveContext.save.isNight) {
        this->skelAnime.playSpeed = 1.0f;
        if (this->animIndex != ENKAKASI_ANIM_SIDEWAYS_SHAKING) {
            EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_SIDEWAYS_SHAKING);
        }
    } else if (this->animIndex != ENKAKASI_ANIM_IDLE) {
        EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_IDLE);
    }
    if (this->picto.actor.xzDistToPlayer < 120.0f) {
        Actor_OfferTalk(&this->picto.actor, play, 100.0f);
        Actor_OfferOcarinaInteraction(&this->picto.actor, play, 100.0f, 80.0f);
    }
}
