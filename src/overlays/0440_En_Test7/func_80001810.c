// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_WarpCsPart5(EnTest7* this, PlayState* play) {
    s32 pad;
    s32 temp = this->timer - 96;
    f32 lerp = 1.0f - (temp / (f32)(100 - 96));
    Camera* subCam;
    f32 temp_f2;
    f32 temp_f4;

    this->windCapsule.xzScale = ((temp * -0.1f) / 4) + 0.1f;
    this->windCapsule.yScale = ((temp * 5.9f) / 4) + 0.1f;
    this->windCapsule.yaw -= 0x2EE0;

    this->actor.world.pos.y += 100.0f;

    subCam = Play_GetCamera(play, CutsceneManager_GetCurrentSubCamId(play->playerCsIds[PLAYER_CS_ID_SONG_WARP]));
    subCam->focalActor = NULL;

    subCam->eye.x = LERPIMP_ALT(this->subCamEye.x, subCam->eye.x, lerp);
    subCam->eye.y = LERPIMP_ALT(this->subCamEye.y, subCam->eye.y, lerp);
    subCam->eye.z = LERPIMP_ALT(this->subCamEye.z, subCam->eye.z, lerp);

    subCam->fov = LERPIMP_ALT(this->subCamFov, subCam->fov, lerp);

    if (this->timer >= 100) {
        R_PLAY_FILL_SCREEN_ON = true;
        R_PLAY_FILL_SCREEN_R = 255;
        R_PLAY_FILL_SCREEN_G = 255;
        R_PLAY_FILL_SCREEN_B = 255;
        R_PLAY_FILL_SCREEN_ALPHA = 255;
        play->soaringCsOrSoTCsPlaying = false;
        this->flags &= ~OWL_WARP_FLAGS_DRAW_LENS_FLARE;
        EnTest7_SetupAction(this, EnTest7_WarpCsPart6);
        Play_DisableMotionBlur();
    }
}
