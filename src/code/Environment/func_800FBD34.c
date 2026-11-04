// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

void Environment_FadeInGameOverLights(PlayState* play) {
    Player* player = GET_PLAYER(play);
    s16 i;

    Lights_PointNoGlowSetInfo(&sNGameOverLightInfo, player->actor.world.pos.x - 10.0f,
                              player->actor.world.pos.y + 10.0f, player->actor.world.pos.z - 10.0f,
                              sGameOverLightsIntensity, sGameOverLightsIntensity, sGameOverLightsIntensity, 255);
    Lights_PointNoGlowSetInfo(&sSGameOverLightInfo, player->actor.world.pos.x + 10.0f,
                              player->actor.world.pos.y + 10.0f, player->actor.world.pos.z + 10.0f,
                              sGameOverLightsIntensity, sGameOverLightsIntensity, sGameOverLightsIntensity, 255);

    if (sGameOverLightsIntensity < 254) {
        sGameOverLightsIntensity += 2;
    }

    if (Play_CamIsNotFixed(play)) {
        for (i = 0; i < 3; i++) {
            if (play->envCtx.adjLightSettings.ambientColor[i] > -255) {
                play->envCtx.adjLightSettings.ambientColor[i] -= 12;
                play->envCtx.adjLightSettings.light1Color[i] -= 12;
            }
            play->envCtx.adjLightSettings.fogColor[i] = -255;
        }

        if (play->envCtx.lightSettings.zFar + play->envCtx.adjLightSettings.zFar > 900) {
            play->envCtx.adjLightSettings.zFar -= 100;
        }

        if (play->envCtx.lightSettings.fogNear + play->envCtx.adjLightSettings.fogNear > 950) {
            play->envCtx.adjLightSettings.fogNear -= 10;
        }
    } else {
        play->envCtx.fillScreen = true;
        play->envCtx.screenFillColor[0] = 0;
        play->envCtx.screenFillColor[1] = 0;
        play->envCtx.screenFillColor[2] = 0;
        play->envCtx.screenFillColor[3] = sGameOverLightsIntensity;
    }
}
