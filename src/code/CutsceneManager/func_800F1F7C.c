// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eventmgr.h"

s16 CutsceneManager_FindEntranceCsId(void) {
    PlayState* play;
    s32 csId;

    for (csId = 0; csId < sSceneCutsceneCount; csId++) {
        if (sSceneCutsceneList[csId].scriptIndex != CS_SCRIPT_ID_NONE) {
            PlayState* play = sCutsceneMgr.play;

            if ((sSceneCutsceneList[csId].scriptIndex < play->csCtx.scriptListCount) &&
                (sCutsceneMgr.play->curSpawn ==
                 sCutsceneMgr.play->csCtx.scriptList[sSceneCutsceneList[csId].scriptIndex].spawn)) {
                return csId;
            }
        }
    }

    for (csId = 0; csId < sSceneCutsceneCount; csId++) {
        if ((sSceneCutsceneList[csId].customValue >= 100) &&
            (sSceneCutsceneList[csId].customValue == (sCutsceneMgr.play->curSpawn + 100))) {
            return csId;
        }
    }

    return -1;
}
