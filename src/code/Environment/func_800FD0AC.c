// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

s32 Environment_AdjustLights(PlayState* play, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 temp;
    s32 i;
    Player* player = GET_PLAYER(play);

    if (play->roomCtx.curRoom.type == ROOM_TYPE_BOSS) {
        return 0;
    }

    if (!Play_CamIsNotFixed(play)) {
        return 0;
    }
    if (play->unk_18880) {
        return 0;
    }
    if ((player != NULL) && (player->stateFlags1 & PLAYER_STATE1_2)) {
        return 0;
    }

    arg1 = CLAMP_MIN(arg1, 0.0f);
    arg1 = CLAMP_MAX(arg1, 1.0f);

    temp = arg1 - arg3;

    if (arg1 < arg3) {
        temp = 0.0f;
    }

    play->envCtx.adjLightSettings.fogNear = (arg2 - play->envCtx.lightSettings.fogNear) * temp;

    if (arg1 == 0.0f) {
        for (i = 0; i < 3; i++) {
            play->envCtx.adjLightSettings.fogColor[i] = 0;
        }
    } else {
        temp = arg1 * 5.0f;
        temp = CLAMP_MAX(temp, 1.0f);

        for (i = 0; i < 3; i++) {
            play->envCtx.adjLightSettings.fogColor[i] = -(f32)play->envCtx.lightSettings.fogColor[i] * temp;
        }
    }

    if (arg4 <= 0.0f) {
        return 1;
    }

    arg1 *= arg4;

    for (i = 0; i < 3; i++) {
        play->envCtx.adjLightSettings.ambientColor[i] = -(f32)play->envCtx.lightSettings.ambientColor[i] * arg1;
        play->envCtx.adjLightSettings.light1Color[i] = -(f32)play->envCtx.lightSettings.light1Color[i] * arg1;
    }

    return 1;
}
