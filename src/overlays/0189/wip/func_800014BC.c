// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnKakasi_PostSongLearnDialogue), score 4.00 (4 differ, size +3)
#include "generated/mm/z_en_kakasi.h"

void func_800014BC(EnKakasi* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    f32 curFrame = this->skelAnime.curFrame;
    Vec3f vec3fCopy;

    Math_SmoothStepToS(&this->picto.actor.shape.rot.y, this->picto.actor.home.rot.y, 1, 0xBB8, 0);
    Math_SmoothStepToS(&player->actor.shape.rot.y, this->picto.actor.yawTowardsPlayer + 0x8000, 5, 0x3E8, 0);

    if (this->unk190 == 0) {
        Message_CloseTextbox(play);
        Player_SetCsActionWithHaltedActors(play, &this->picto.actor, PLAYER_CSACTION_86);
        this->picto.actor.textId = 0x1648;
        Message_StartTextbox(play, (this->picto.actor.textId), &this->picto.actor);
        this->unkState1A8 = 0;
        this->unk190 = 1;
    }

    if ((this->picto.actor.textId == 0x1648) && (this->animIndex == ENKAKASI_ANIM_HOPPING_REGULAR) &&
        (curFrame >= this->animEndFrame)) {
        this->unkCounter1A4++;
        if (this->unkCounter1A4 >= 2) {
            EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_ARMS_CROSSED_ROCKING);
        }
    }

    if ((this->picto.actor.textId == 0x164B) && (this->animIndex == ENKAKASI_ANIM_ARMS_CROSSED_ROCKING) &&
        (curFrame >= this->animEndFrame)) {
        this->unkCounter1A4++;
        if (this->unkCounter1A4 >= 2) {
            EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_SPIN_REACH_OFFER);
        }
    }

    if (this->unkState1A8 == 0) {
        if (CutsceneManager_GetCurrentCsId() == CS_ID_GLOBAL_TALK) {
            CutsceneManager_Stop(CS_ID_GLOBAL_TALK);
            CutsceneManager_Queue(this->csIdList[0]);
            return;
        }
        if (!CutsceneManager_IsNext(this->csIdList[0])) {
            CutsceneManager_Queue(this->csIdList[0]);
            return;
        }
        Math_Vec3f_Copy(&this->unk22C, &this->picto.actor.home.pos);
        CutsceneManager_StartWithPlayerCs(this->csIdList[0], &this->picto.actor);
        this->subCamId = CutsceneManager_GetCurrentSubCamId(this->picto.actor.csId);
        Player_SetCsActionWithHaltedActors(play, &this->picto.actor, PLAYER_CSACTION_86);
        this->unkState1A8 = 1;
    }

    if (this->subCamId != SUB_CAM_ID_DONE) {
        this->unk22C.y = this->picto.actor.home.pos.y + 50.0f;
        EnKakasi_CheckPlayerPosition(this, play);
        this->subCamEyeNext.x = ref_D_80971FA0[this->unk190].x;
        this->subCamEyeNext.y = ref_D_80971FA0[this->unk190].y;
        this->subCamEyeNext.z = ref_D_80971FA0[this->unk190].z;
        Math_Vec3f_Copy(&vec3fCopy, &this->subCamEyeNext);
        OLib_Vec3fAdd(&this->picto.actor.home, &vec3fCopy, &this->subCamEyeNext, OLIB_ADD_OFFSET);
        this->subCamAtNext.x = ref_D_80971FE8[this->unk190].x + this->unk22C.x;
        this->subCamAtNext.y = ref_D_80971FE8[this->unk190].y + this->unk22C.y;
        this->subCamAtNext.z = ref_D_80971FE8[this->unk190].z + this->unk22C.z;
        Math_Vec3f_Copy(&this->subCamEye, &this->subCamEyeNext);
        Math_Vec3f_Copy(&this->subCamAt, &this->subCamAtNext);
    }

    ref_func_8096FAAC(this, play);

    if ((this->unkState1A8 != 0) && (Message_GetState(&play->msgCtx) == this->talkState) &&
        Message_ShouldAdvance(play)) {

        Message_CloseTextbox(play);

        if (this->talkState == TEXT_STATE_EVENT) {
            this->unk190++;
            if (this->unk190 > 5) {
                this->unk190 = 5;
            }

            if (this->picto.actor.textId == 0x1648) {
                Player_SetCsActionWithHaltedActors(play, &this->picto.actor, PLAYER_CSACTION_WAIT);
                this->picto.actor.textId = 0x1649;
                if (this->animIndex != ENKAKASI_ANIM_ARMS_CROSSED_ROCKING) {
                    EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_ARMS_CROSSED_ROCKING);
                }

            } else if (this->picto.actor.textId == 0x1649) {
                this->picto.actor.textId = 0x1660;
                this->talkState = TEXT_STATE_CHOICE;

            } else if (this->picto.actor.textId == 0x164A) {
                this->picto.actor.textId = 0x164B;

            } else if (this->picto.actor.textId == 0x164B) {
                this->picto.actor.textId = 0x164C;
                EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_TWIRL);

            } else {
                if ((this->picto.actor.textId == 0x164C) || (this->picto.actor.textId == 0x1661)) {
                    EnKakasi_SetupDigAway(this);
                    return;
                }
            }

        } else {
            this->talkState = TEXT_STATE_EVENT;
            if (play->msgCtx.choiceIndex == 1) {
                Audio_PlaySfx_MessageDecide();
                this->picto.actor.textId = 0x164A;
            } else {
                Audio_PlaySfx_MessageCancel();
                this->picto.actor.textId = 0x1661;
            }
        }
        Message_ContinueTextbox(play, this->picto.actor.textId);
    }
}
