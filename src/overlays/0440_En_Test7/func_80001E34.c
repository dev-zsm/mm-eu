// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_UpdateSubCamWarpCs1(EnTest7* this, PlayState* play, f32 lerp) {
    Vec3f* playerPos;
    Player* player = GET_PLAYER(play);
    Camera* subCam =
        Play_GetCamera(play, CutsceneManager_GetCurrentSubCamId(play->playerCsIds[PLAYER_CS_ID_SONG_WARP]));
    Vec3f eyeNext;

    subCam->focalActor = NULL;

    playerPos = &player->actor.world.pos;

    eyeNext.x = playerPos->x + 80.0f * Math_SinS(this->playerYaw) * Math_CosS(0xBB8);
    eyeNext.y = playerPos->y + 80.0f * Math_SinS(0xBB8);
    eyeNext.z = playerPos->z + 80.0f * Math_CosS(this->playerYaw) * Math_CosS(0xBB8);

    subCam->eye.x = LERPIMP_ALT(subCam->eye.x, eyeNext.x, lerp);
    subCam->eye.y = LERPIMP_ALT(subCam->eye.y, eyeNext.y, lerp);
    subCam->eye.z = LERPIMP_ALT(subCam->eye.z, eyeNext.z, lerp);

    subCam->at.x = LERPIMP_ALT(subCam->at.x, playerPos->x, lerp);
    subCam->at.y = LERPIMP_ALT(subCam->at.y, playerPos->y + 40.0f, lerp);
    subCam->at.z = LERPIMP_ALT(subCam->at.z, playerPos->z, lerp);

    subCam->fov = LERPIMP_ALT(subCam->fov, this->subCamFov, lerp);
}
