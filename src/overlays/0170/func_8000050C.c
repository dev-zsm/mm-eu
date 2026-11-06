// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ingate.h"

void ref_func_80953F9C(BgIngate* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    Camera* mainCam = Play_GetCamera(play, CAM_ID_MAIN);

    if (!CHECK_EVENTINF(EVENTINF_40)) {

        if (!CHECK_EVENTINF(EVENTINF_35) && (this->unk160 & 0x10) && (this->unk16C == 0)) {
            this->dyna.actor.textId = 0x9E3;
            Message_StartTextbox(play, this->dyna.actor.textId, NULL);
            this->unk160 &= ~0x10;
        }

        if (this->unk160 & 2) {

            if (this->timePath->additionalPathIndex != ADDITIONAL_PATH_INDEX_NONE) {
                ref_func_80953E38(play);
                Player_SetCsActionWithHaltedActors(play, &this->dyna.actor, PLAYER_CSACTION_WAIT);
                this->dyna.actor.textId = 0x9E4;
                Message_StartTextbox(play, this->dyna.actor.textId, NULL);
                this->unk16C += 1;
                SET_WEEKEVENTREG(WEEKEVENTREG_90_40);
                this->actionFunc = ref_func_809543D4;
            } else {
                if (!CHECK_EVENTINF(EVENTINF_35)) {
                    CLEAR_EVENTINF(EVENTINF_41);
                } else {
                    SET_EVENTINF(EVENTINF_40);
                }
                this->actionFunc = ref_func_809542A0;
            }
        } else if ((CutsceneManager_GetCurrentCsId() == CS_ID_NONE) && (this->timePath != NULL)) {
            Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_CRUISER - SFX_FLAG);
            ref_func_80953BEC(this);
        }
    }
    if (CutsceneManager_GetCurrentCsId() != this->csId) {
        if (CutsceneManager_GetCurrentCsId() != CS_ID_NONE) {
            Camera_ChangeSetting(mainCam, CAM_SET_NORMAL0);
            player->stateFlags1 |= PLAYER_STATE1_20;
            play->actorCtx.flags &= ~ACTORCTX_FLAG_PICTO_BOX_ON;
        } else {
            Camera_ChangeSetting(mainCam, CAM_SET_BOAT_CRUISE);
            player->stateFlags1 &= ~PLAYER_STATE1_20;
        }
    }
    this->csId = CutsceneManager_GetCurrentCsId();
}
