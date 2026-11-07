// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_WarpCsPart1(EnTest7* this, PlayState* play) {
    Color_RGB8 fogColor = { 64, 0, 0 };
    Color_RGB8 ambientColor = { 220, 220, 255 };
    f32 envLerp = this->timer / (f32)(10 - 0);

    Environment_LerpAmbientColor(play, &ambientColor, envLerp);
    Environment_LerpFogColor(play, &fogColor, envLerp);
    Environment_LerpFog(play, 2000, 4000, envLerp);

    if (this->timer >= 10) {
        Camera* subCam =
            Play_GetCamera(play, CutsceneManager_GetCurrentSubCamId(play->playerCsIds[PLAYER_CS_ID_SONG_WARP]));

        this->subCamEye = subCam->eye;
        this->subCamAt = subCam->at;
        this->subCamFov = subCam->fov;

        EnTest7_SetupAction(this, EnTest7_WarpCsPart2);
        this->flags |= OWL_WARP_FLAGS_20;
        Audio_PlaySfx_AtPos(&this->actor.projectedPos, NA_SE_PL_WARP_WING_OPEN);
        Play_EnableMotionBlur(120);
    }
}
