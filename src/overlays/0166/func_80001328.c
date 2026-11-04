// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_clear_tag.h"

void EnClearTag_UpdateCamera(EnClearTag* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    Camera* mainCam;
    s32 pad;

    switch (this->cameraState) {
        case 0:
            if (((player->actor.world.pos.z > 0.0f) && (player->actor.world.pos.z > 290.0f) &&
                 (fabsf(player->actor.world.pos.x) < 60.0f)) ||
                ((player->actor.world.pos.z < 0.0f) && (player->actor.world.pos.z < -950.0f) &&
                 (fabsf(player->actor.world.pos.x) < 103.0f))) {

                if (player->actor.world.pos.z > 0.0f) {
                    player->actor.world.pos.z = 290.0f;
                } else {
                    player->actor.world.pos.z = -950.0f;
                }

                player->actor.speed = 0.0f;
                if (this->activeTimer == 0) {
                    this->cameraState = 1;
                }
            }
            break;

        case 1:
            Cutscene_StartManual(play, &play->csCtx);
            this->subCamId = Play_CreateSubCamera(play);
            Play_ChangeCameraStatus(play, CAM_ID_MAIN, CAM_STATUS_WAIT);
            Play_ChangeCameraStatus(play, this->subCamId, CAM_STATUS_ACTIVE);
            Player_SetCsActionWithHaltedActors(play, &this->actor, PLAYER_CSACTION_4);
            mainCam = Play_GetCamera(play, CAM_ID_MAIN);
            this->subCamEye.x = mainCam->eye.x;
            this->subCamEye.y = mainCam->eye.y;
            this->subCamEye.z = mainCam->eye.z;
            this->subCamAt.x = mainCam->at.x;
            this->subCamAt.y = mainCam->at.y;
            this->subCamAt.z = mainCam->at.z;
            Message_StartTextbox(play, 0xF, NULL);
            this->cameraState = 2;
            Audio_PlaySfx_AtPosWithReverb(&gSfxDefaultPos, NA_SE_VO_NA_LISTEN, 0x20);
            FALLTHROUGH;
        case 2:
            if (player->actor.world.pos.z > 0.0f) {
                player->actor.world.pos.z = 290.0f;
            } else {
                player->actor.world.pos.z = -950.0f;
            }

            player->actor.speed = 0.0f;
            if (Message_GetState(&play->msgCtx) == TEXT_STATE_NONE) {
                mainCam = Play_GetCamera(play, CAM_ID_MAIN);
                mainCam->eye = this->subCamEye;
                mainCam->eyeNext = this->subCamEye;
                mainCam->at = this->subCamAt;
                ref_func_80169AFC(play, this->subCamId, 0);
                Cutscene_StopManual(play, &play->csCtx);
                Player_SetCsActionWithHaltedActors(play, &this->actor, PLAYER_CSACTION_END);
                this->cameraState = 0;
                this->subCamId = SUB_CAM_ID_DONE;
                this->activeTimer = 20;
            }
            break;
    }

    if (this->subCamId != SUB_CAM_ID_DONE) {
        Play_SetCameraAtEye(play, this->subCamId, &this->subCamAt, &this->subCamEye);
    }
}
