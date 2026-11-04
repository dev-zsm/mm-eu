// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test6.h"

void EnTest6_Destroy(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EnTest6* this = (EnTest6*)thisx;
    s32 i;

    play->envCtx.adjLightSettings.ambientColor[0] = 0;
    play->envCtx.adjLightSettings.ambientColor[1] = 0;
    play->envCtx.adjLightSettings.ambientColor[2] = 0;

    play->envCtx.adjLightSettings.light1Color[0] = 0;
    play->envCtx.adjLightSettings.light1Color[1] = 0;
    play->envCtx.adjLightSettings.light1Color[2] = 0;

    play->envCtx.adjLightSettings.light2Color[0] = 0;
    play->envCtx.adjLightSettings.light2Color[1] = 0;
    play->envCtx.adjLightSettings.light2Color[2] = 0;

    play->envCtx.adjLightSettings.fogColor[0] = 0;
    play->envCtx.adjLightSettings.fogColor[1] = 0;
    play->envCtx.adjLightSettings.fogColor[2] = 0;

    play->envCtx.adjLightSettings.fogNear = 0;
    play->envCtx.adjLightSettings.zFar = 0;

    play->envCtx.fillScreen = false;

    for (i = 0; i < ARRAY_COUNT(this->lights); i++) {
        LightContext_RemoveLight(play, &play->lightCtx, this->lights[i].node);
    }
}
