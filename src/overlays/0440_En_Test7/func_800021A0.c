// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_UpdateSubCamArrivalCs1(EnTest7* this, PlayState* play) {
    static OwlWarpVecGeo sSubCamAtOffset = { 0, 0x31C7, 3500.0f };
    s32 pad;
    Player* player = GET_PLAYER(play);
    Vec3f* pos = &player->actor.world.pos;
    Camera* subCam =
        Play_GetCamera(play, CutsceneManager_GetCurrentSubCamId(play->playerCsIds[PLAYER_CS_ID_SONG_WARP]));

    subCam->at.x = pos->x + (sSubCamAtOffset.r * Math_SinS(sSubCamAtOffset.yaw) * Math_CosS(sSubCamAtOffset.pitch));
    subCam->at.y = pos->y + (sSubCamAtOffset.r * Math_SinS(sSubCamAtOffset.pitch));
    subCam->at.z = pos->z + (sSubCamAtOffset.r * Math_CosS(sSubCamAtOffset.yaw)) * Math_CosS(sSubCamAtOffset.pitch);

    this->actor.world.pos.x = subCam->at.x;
    this->actor.world.pos.y = subCam->at.y - 40.0f;
    this->actor.world.pos.z = subCam->at.z;
}
