// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_StartArriveCsSkip(EnTest7* this, PlayState* play) {
    Camera* subCam;

    if (!CutsceneManager_IsNext(play->playerCsIds[PLAYER_CS_ID_SONG_WARP])) {
        CutsceneManager_Queue(play->playerCsIds[PLAYER_CS_ID_SONG_WARP]);
    } else {
        CutsceneManager_Start(play->playerCsIds[PLAYER_CS_ID_SONG_WARP], NULL);
        EnTest7_SetupAction(this, EnTest7_ArriveCsPart2);

        subCam = Play_GetCamera(play, CutsceneManager_GetCurrentSubCamId(play->playerCsIds[PLAYER_CS_ID_SONG_WARP]));
        this->subCamEye = subCam->eye;
        this->subCamAt = subCam->at;
        this->timer = 40;

        EnTest7_UpdateSubCamArrivalCs3(this, play);
    }
}
