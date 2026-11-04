// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eventmgr.h"

void CutsceneManager_End(void) {
    CutsceneEntry* csEntry;
    s16 oldCamId;
    s16 oldStateFlags;

    switch (sCutsceneMgr.startMethod) {
        case CS_START_2:
            sCutsceneMgr.targetActor->flags &= ~ACTOR_FLAG_FREEZE_EXCEPTION;
            FALLTHROUGH;
        case CS_START_1:
            Player_SetCsActionWithHaltedActors(sCutsceneMgr.play, NULL, PLAYER_CSACTION_END);
            sCutsceneMgr.startMethod = CS_START_0;
            break;

        default:
            break;
    }

    csEntry = CutsceneManager_GetCutsceneEntryImpl(sCutsceneMgr.csId);

    switch (csEntry->endSfx) {
        case CS_END_SFX_TRE_BOX_APPEAR:
            Audio_PlaySfx(NA_SE_SY_TRE_BOX_APPEAR);
            break;

        case CS_END_SFX_CORRECT_CHIME:
            Audio_PlaySfx(NA_SE_SY_CORRECT_CHIME);
            break;

        default: 
            break;
    }

    switch (csEntry->endCam) {
        case CS_END_CAM_SMOOTH:
            Play_CopyCamera(sCutsceneMgr.play, sCutsceneMgr.retCamId, sCutsceneMgr.subCamId);
            RET_CAM->stateFlags =
                (RET_CAM->stateFlags & ~CAM_STATE_UNDERWATER) | (CUR_CAM->stateFlags & CAM_STATE_UNDERWATER);
            CutsceneManager_Queue(CS_ID_GLOBAL_RETURN_TO_CAM);
            break;

        case CS_END_CAM_0:
        default:
            Play_CopyCamera(sCutsceneMgr.play, sCutsceneMgr.retCamId, sCutsceneMgr.subCamId);
            RET_CAM->stateFlags =
                (RET_CAM->stateFlags & ~CAM_STATE_UNDERWATER) | (CUR_CAM->stateFlags & CAM_STATE_UNDERWATER);
            break;

        case CS_END_CAM_1:
            oldCamId = RET_CAM->camId;
            oldStateFlags = RET_CAM->stateFlags;

            if (sCutsceneMgr.isCameraStored) {
                
                memcpy(RET_CAM, &sCutsceneMgr.play->subCameras[2], sizeof(Camera));

                RET_CAM->stateFlags =
                    (RET_CAM->stateFlags & ~CAM_STATE_UNDERWATER) | (CUR_CAM->stateFlags & CAM_STATE_UNDERWATER);

                RET_CAM->stateFlags = (RET_CAM->stateFlags & ~CAM_STATE_2) | (oldStateFlags & CAM_STATE_2);
                sCutsceneMgr.isCameraStored = false;
            }
            RET_CAM->camId = oldCamId;
            break;
    }

    if (sCutsceneMgr.subCamId != SUB_CAM_ID_DONE) {
        Play_ClearCamera(sCutsceneMgr.play, sCutsceneMgr.subCamId);
        Play_ChangeCameraStatus(sCutsceneMgr.play, sCutsceneMgr.retCamId, CAM_STATUS_ACTIVE);
    }

    sCutsceneMgr.csId = CS_ID_NONE;
    sCutsceneMgr.endCsId = CS_ID_NONE;
    sCutsceneMgr.length = -1;
    sCutsceneMgr.targetActor = NULL;
    sCutsceneMgr.subCamId = SUB_CAM_ID_DONE;
}
