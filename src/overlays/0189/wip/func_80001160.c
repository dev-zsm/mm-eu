// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnKakasi_TeachingSong), score 3.00 (3 differ, size +2)
#include "generated/mm/z_en_kakasi.h"

void func_80001160(EnKakasi* this, PlayState* play) {
    Vec3f tempVec;

    EnKakasi_CheckPlayerPosition(this, play);
    Math_SmoothStepToS(&this->picto.actor.shape.rot.y, this->picto.actor.home.rot.y, 1, 0xBB8, 0);
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
        CutsceneManager_StartWithPlayerCs(this->csIdList[0], &this->picto.actor);
        this->subCamId = CutsceneManager_GetCurrentSubCamId(this->picto.actor.csId);
        Math_Vec3f_Copy(&this->unk22C, &this->picto.actor.home.pos);
        this->unkState1A8 = 1;
        this->unkState1A8 = 1;
    }

    if (this->unkState1A8 == 1) {
        this->unk22C.y = this->picto.actor.home.pos.y + 50.0f;
        this->subCamEyeNext.x = ref_D_80971DCC[this->unk190].x;
        this->subCamEyeNext.y = ref_D_80971DCC[this->unk190].y;
        this->subCamEyeNext.z = ref_D_80971DCC[this->unk190].z;

        Math_Vec3f_Copy(&tempVec, &this->subCamEyeNext);
        OLib_Vec3fAdd(&this->picto.actor.home, &tempVec, &this->subCamEyeNext, OLIB_ADD_OFFSET);
        Math_Vec3f_Copy(&this->subCamAtNext, &this->unk22C);
        Math_Vec3f_Copy(&this->subCamEye, &this->subCamEyeNext);
        Math_Vec3f_Copy(&this->subCamAt, &this->subCamAtNext);
        ref_func_8096FAAC(this, play);
        ref_func_8096FBB8(this, play);

        if (play->msgCtx.ocarinaMode == OCARINA_MODE_END) { 
            this->unk190 = 0;
            this->unkCounter1A4 = 0;
            CutsceneManager_Stop(this->csIdList[0]);
            Actor_PlaySfx(&this->picto.actor, NA_SE_EN_YASE_DEAD);
            this->unkState196 = 2;
            this->subCamId = SUB_CAM_ID_DONE;
            this->picto.actor.textId = 0x1647;
            this->unkState1A8 = 2;
            this->talkState = TEXT_STATE_EVENT;
            EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_ARMS_CROSSED_ROCKING);
            this->actionFunc = EnKakasi_RegularDialogue;

        } else if (play->msgCtx.ocarinaMode == OCARINA_MODE_EVENT) { 
            this->postTeachTimer = 30;
            this->skelAnime.playSpeed = 2.0f;
            EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_HOPPING_REGULAR);
            this->actionFunc = EnKakasi_PostSongLearnTwirl;
        }
    }
}
