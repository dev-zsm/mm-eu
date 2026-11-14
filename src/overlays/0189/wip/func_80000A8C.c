// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnKakasi_RegularDialogue), score 3.00 (3 differ, size +2)
#include "generated/mm/z_en_kakasi.h"

void func_80000A8C(EnKakasi* this, PlayState* play) {
    u32 day = gSaveContext.save.day;
    f32 curFrame = this->skelAnime.curFrame;

    Math_SmoothStepToS(&this->picto.actor.shape.rot.y, this->picto.actor.yawTowardsPlayer, 5, 0x7D0, 0);
    
    if ((this->picto.actor.textId != 0x1644) && (curFrame >= this->animEndFrame) &&
        (this->animIndex == ENKAKASI_ANIM_SLOWROLL)) {

        EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_SPIN_REACH_OFFER);
        this->unkCounter1A4 = 0;
    }

    
    if ((this->picto.actor.textId == 0x1651) || (this->picto.actor.textId == 0x1659)) {
        if ((curFrame >= this->animEndFrame) && (this->animIndex != ENKAKASI_ANIM_SPIN_REACH_OFFER)) {
            this->unkCounter1A4++;
            if (this->unkCounter1A4 >= 2) {
                this->unkCounter1A4 = 0;
                EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_SPIN_REACH_OFFER);
            }
        }
    }

    if ((this->unkState1A8 == 2) && (this->unkState196 == 2)) {
        Player_SetCsActionWithHaltedActors(play, &this->picto.actor, PLAYER_CSACTION_73);
        this->unkState1A8 = 0;
    }

    if ((this->talkState == Message_GetState(&play->msgCtx)) && Message_ShouldAdvance(play)) {
        Message_CloseTextbox(play);
        if (this->talkState == TEXT_STATE_EVENT) {
            
            if ((this->unkState196 == 2) && (this->picto.actor.textId == 0x1647)) {
                Player_SetCsActionWithHaltedActors(play, &this->picto.actor, PLAYER_CSACTION_END);
            }

            
            if (this->picto.actor.textId == 0x1653) {
                u32 saveContextDay2 = gSaveContext.save.day;

                if (this->animIndex != ENKAKASI_ANIM_SIDEWAYS_SHAKING) {
                    EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_SIDEWAYS_SHAKING);
                }

                if ((saveContextDay2 == 3) && gSaveContext.save.isNight) {
                    
                    this->picto.actor.textId = 0x164F;
                } else if (gSaveContext.save.isNight) {
                    
                    this->picto.actor.textId = 0x164E;
                } else {
                    
                    this->picto.actor.textId = 0x1645;
                }

                Message_ContinueTextbox(play, this->picto.actor.textId);
                return;

            } else if ((this->picto.actor.textId == 0x165D) || (this->picto.actor.textId == 0x165F) ||
                       (this->picto.actor.textId == 0x1660) || (this->picto.actor.textId == 0x1652)) {
                Player_SetCsActionWithHaltedActors(play, &this->picto.actor, PLAYER_CSACTION_4);
                if (CutsceneManager_GetCurrentCsId() == CS_ID_GLOBAL_TALK) {
                    CutsceneManager_Stop(CS_ID_GLOBAL_TALK);
                    CutsceneManager_Queue(this->csIdList[0]);
                    this->actionFunc = EnKakasi_DancingRemark;
                } else {
                    if (!CutsceneManager_IsNext(this->csIdList[0])) {
                        CutsceneManager_Queue(this->csIdList[0]);
                        this->actionFunc = EnKakasi_DancingRemark;
                    } else {
                        CutsceneManager_StartWithPlayerCs(this->csIdList[0], &this->picto.actor);
                        this->subCamId = CutsceneManager_GetCurrentSubCamId(this->picto.actor.csId);
                        this->actionFunc = EnKakasi_DancingRemark;
                    }
                }
                return;

            } else if ((this->picto.actor.textId == 0x1645) || (this->picto.actor.textId == 0x164E)) {
                this->picto.actor.textId = 0x1650; 
                if (this->animIndex != ENKAKASI_ANIM_SIDEWAYS_SHAKING) {
                    EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_SIDEWAYS_SHAKING);
                }
                this->talkState = TEXT_STATE_CHOICE;

            } else if (this->picto.actor.textId == 0x1644) {
                if (this->animIndex != ENKAKASI_ANIM_SIDEWAYS_SHAKING) {
                    EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_SIDEWAYS_SHAKING);
                }
                if (gSaveContext.save.isNight) {
                    this->picto.actor.textId = 0x164E;
                } else {
                    this->picto.actor.textId = 0x1645;
                }

            } else if (this->picto.actor.textId == 0x164F) {
                if (this->animIndex != ENKAKASI_ANIM_SIDEWAYS_SHAKING) {
                    EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_SIDEWAYS_SHAKING);
                }
                this->picto.actor.textId = 0x165A;
            } else if (this->picto.actor.textId == 0x1651) {
                if (this->animIndex != ENKAKASI_ANIM_SIDEWAYS_SHAKING) {
                    EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_SIDEWAYS_SHAKING);
                }
                this->picto.actor.textId = 0x1654;
            } else if (this->picto.actor.textId == 0x1654) {
                this->picto.actor.textId = 0x1655;
            } else if (this->picto.actor.textId == 0x1655) {
                this->picto.actor.textId = 0x1656;
                this->talkState = TEXT_STATE_CHOICE;
            } else if (this->picto.actor.textId == 0x1658) {
                this->picto.actor.textId = 0x1659;
            } else if (this->picto.actor.textId == 0x165A) {
                this->picto.actor.textId = 0x165B;
            } else if (this->picto.actor.textId == 0x165B) {
                this->picto.actor.textId = 0x165C;
                this->talkState = TEXT_STATE_CHOICE;

            } else if (this->picto.actor.textId == 0x165E) {
                this->picto.actor.textId = 0x165F;
            } else {
                EnKakasi_SetupIdleStanding(this);
                return;
            }
        } else {
            this->talkState = TEXT_STATE_EVENT;

            if (play->msgCtx.choiceIndex == 1) {
                Audio_PlaySfx_MessageDecide();
                if (this->picto.actor.textId == 0x1656) {
                    this->picto.actor.textId = 0x1658;
                } else if (this->picto.actor.textId == 0x165C) {
                    this->picto.actor.textId = 0x165E;
                } else if ((day == 3) && gSaveContext.save.isNight) {
                    this->picto.actor.textId = 0x164F;
                } else {
                    this->picto.actor.textId = 0x1652;
                }
                EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_HOPPING_REGULAR);
            } else {
                Audio_PlaySfx_MessageCancel();
                if (this->picto.actor.textId == 0x1656) { 
                    this->picto.actor.textId = 0x1657;
                } else if (this->picto.actor.textId == 0x165C) { 
                    this->picto.actor.textId = 0x165D;
                } else {
                    this->picto.actor.textId = 0x1651;
                }
                this->unkCounter1A4 = 0;
                if (this->animIndex != ENKAKASI_ANIM_ARMS_CROSSED_ROCKING) {
                    EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_ARMS_CROSSED_ROCKING);
                }
            }
        }
        Message_ContinueTextbox(play, this->picto.actor.textId);
    }
}
