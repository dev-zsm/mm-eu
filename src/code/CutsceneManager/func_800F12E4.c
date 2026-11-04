// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eventmgr.h"

void CutsceneManager_Init(PlayState* play, CutsceneEntry* cutsceneList, s16 numEntries) {
    s32 i;

    sSceneCutsceneList = cutsceneList;
    sSceneCutsceneCount = numEntries;

    for (i = 0; i < ARRAY_COUNT(sWaitingCutsceneList); i++) {
        sWaitingCutsceneList[i] = 0;
        sNextCutsceneList[i] = 0;
    }

    sCutsceneMgr.endCsId = CS_ID_NONE;
    sCutsceneMgr.play = play;
    sCutsceneMgr.length = -1;
    sCutsceneMgr.targetActor = NULL;
    sCutsceneMgr.subCamId = SUB_CAM_ID_DONE;
    sCutsceneMgr.isCameraStored = false;
    sCutsceneMgr.csId = sCutsceneMgr.endCsId;
}
