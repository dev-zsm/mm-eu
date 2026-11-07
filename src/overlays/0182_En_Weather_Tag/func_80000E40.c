// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_weather_tag.h"

void EnWeatherTag_Unused_80967250(EnWeatherTag* this, PlayState* play) {
    if (ref_func_80966758(this, play, 1, 0, 4, 0, 100)) {
        Environment_StopStormNatureAmbience(play);
        play->envCtx.lightningState = LIGHTNING_LAST;
        play->envCtx.precipitation[PRECIP_RAIN_MAX] = 0;
        EnWeatherTag_SetupAction(this, EnWeatherTag_Unused_809671B8);
    }
}
