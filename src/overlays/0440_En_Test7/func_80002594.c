// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_UpdateSubCamArrivalCs3(EnTest7* this, PlayState* play) {
    Camera* subCam;
    Player* player = GET_PLAYER(play);
    Vec3f* pos = &player->actor.world.pos;

    subCam = Play_GetCamera(play, CutsceneManager_GetCurrentSubCamId(play->playerCsIds[PLAYER_CS_ID_SONG_WARP]));

    
    subCam->eye.x = pos->x + 200.0f * Math_SinS(-player->actor.shape.rot.y) * -0.83907f;
    subCam->eye.y = pos->y + 200.0f * 0.544021f;
    subCam->eye.z = pos->z + 200.0f * Math_CosS(-player->actor.shape.rot.y) * -0.83907f;

    subCam->at.x = pos->x;
    subCam->at.y = pos->y + 40.0f;
    subCam->at.z = pos->z;
}
