// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test6.h"

void EnTest6_StartCutscene(EnTest6* this, PlayState* play) {
    switch (SOTCS_GET_OCARINA_MODE(&this->actor)) {
        case OCARINA_MODE_APPLY_INV_SOT_FAST:
        case OCARINA_MODE_APPLY_INV_SOT_SLOW:
            if (!CutsceneManager_IsNext(play->playerCsIds[PLAYER_CS_ID_SONG_WARP])) {
                CutsceneManager_Queue(play->playerCsIds[PLAYER_CS_ID_SONG_WARP]);
            } else {
                CutsceneManager_Start(play->playerCsIds[PLAYER_CS_ID_SONG_WARP], NULL);
                this->subCamId = CutsceneManager_GetCurrentSubCamId(play->playerCsIds[PLAYER_CS_ID_SONG_WARP]);
                EnTest6_SetupAction(this, EnTest6_InvertedSoTCutscene);
            }
            break;

        case OCARINA_MODE_APPLY_DOUBLE_SOT:
            if (!CutsceneManager_IsNext(play->playerCsIds[PLAYER_CS_ID_SONG_WARP])) {
                CutsceneManager_Queue(play->playerCsIds[PLAYER_CS_ID_SONG_WARP]);
            } else {
                CutsceneManager_Start(play->playerCsIds[PLAYER_CS_ID_SONG_WARP], NULL);
                this->subCamId = CutsceneManager_GetCurrentSubCamId(play->playerCsIds[PLAYER_CS_ID_SONG_WARP]);
                EnTest6_SetupAction(this, EnTest6_DoubleSoTCutscene);
            }
            break;

        default:
            gSaveContext.save.eventDayCount = 0;
            gSaveContext.save.day = 0;
            gSaveContext.save.time = CLOCK_TIME(6, 0) - 1;
            EnTest6_SetupAction(this, EnTest6_SharedSoTCutscene);
            break;
    }
}
