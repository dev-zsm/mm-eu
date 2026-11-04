// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_play.h"

void Play_UpdateWaterCamera(PlayState* this, Camera* camera) {
    static s16 sQuakeIndex = -1;
    static s16 sIsCameraUnderwater = false;
    s32 pad;
    s32 lightIndex;
    Player* player = GET_PLAYER(this);

    sIsCameraUnderwater = camera->stateFlags & CAM_STATE_UNDERWATER;
    if (Play_GetWaterSurface(this, &camera->eye, &lightIndex) != BGCHECK_Y_MIN) {
        if (!sIsCameraUnderwater) {
            Camera_SetStateFlag(camera, CAM_STATE_UNDERWATER);
            sQuakeIndex = -1;
            Distortion_Request(DISTORTION_TYPE_UNDERWATER_ENTRY);
            Distortion_SetDuration(80);
        }

        Audio_SetExtraFilter(0x20);
        Environment_EnableUnderwaterLights(this, lightIndex);

        if ((sQuakeIndex == -1) || (Quake_GetTimeLeft(sQuakeIndex) == 10)) {
            s16 quakeIndex = Quake_Request(camera, QUAKE_TYPE_5);

            sQuakeIndex = quakeIndex;
            if (quakeIndex != 0) {
                Quake_SetSpeed(sQuakeIndex, 550);
                Quake_SetPerturbations(sQuakeIndex, 1, 1, 180, 0);
                Quake_SetDuration(sQuakeIndex, 1000);
            }
        }
        if (player->stateFlags3 & PLAYER_STATE3_8000) {
            Distortion_Request(DISTORTION_TYPE_ZORA_SWIMMING);
            Distortion_RemoveRequest(DISTORTION_TYPE_NON_ZORA_SWIMMING);
        } else {
            Distortion_Request(DISTORTION_TYPE_NON_ZORA_SWIMMING);
            Distortion_RemoveRequest(DISTORTION_TYPE_ZORA_SWIMMING);
        }
    } else {
        if (sIsCameraUnderwater) {
            Camera_UnsetStateFlag(camera, CAM_STATE_UNDERWATER);
        }
        Distortion_RemoveRequest(DISTORTION_TYPE_NON_ZORA_SWIMMING);
        Distortion_RemoveRequest(DISTORTION_TYPE_UNDERWATER_ENTRY);
        Distortion_RemoveRequest(DISTORTION_TYPE_ZORA_SWIMMING);
        if (sQuakeIndex != 0) {
            Quake_RemoveRequest(sQuakeIndex);
        }
        Environment_DisableUnderwaterLights(this);
        Audio_SetExtraFilter(0);
    }
}
