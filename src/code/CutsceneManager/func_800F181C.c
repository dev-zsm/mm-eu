// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eventmgr.h"

s16 CutsceneManager_Update(void) {
    s16 sp1E = 0;

    if (CutsceneManager_IsNext(CS_ID_GLOBAL_RETURN_TO_CAM)) {
        CutsceneManager_StartWithPlayerCs(CS_ID_GLOBAL_RETURN_TO_CAM, &GET_PLAYER(sCutsceneMgr.play)->actor);
    }

    if (sCutsceneMgr.endCsId == CS_ID_NONE) {
        if (sCutsceneMgr.csId != CS_ID_NONE) {
            if (sCutsceneMgr.length > 0) {
                sCutsceneMgr.length--;
            }
            sp1E = 1;
            if (sCutsceneMgr.length == 0) {
                CutsceneManager_Stop(sCutsceneMgr.csId);
            }
        }
    }

    if (sCutsceneMgr.endCsId != CS_ID_NONE) {
        CutsceneManager_End();
        sp1E = 2;
    }

    CutsceneManager_ClearNextCutscenes();

    if (sCutsceneMgr.csId == CS_ID_NONE) {
        if ((CutsceneManager_MarkNextCutscenes() == 0) && (sp1E != 0)) {
            ShrinkWindow_Letterbox_SetSizeTarget(0);
        } else if (sp1E == 0) {
            CutsceneManager_StoreCamera(Play_GetCamera(sCutsceneMgr.play, sCutsceneMgr.retCamId));
        }
    }
    return sp1E;
}
