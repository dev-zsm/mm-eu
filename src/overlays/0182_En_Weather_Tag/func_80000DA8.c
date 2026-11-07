// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_weather_tag.h"

void EnWeatherTag_Unused_809671B8(EnWeatherTag* this, PlayState* play) {
    if (ref_func_80966608(this, play, 0, 1, 0, 4, 100, WEATHER_MODE_5)) {
        Environment_PlayStormNatureAmbience(play);
        play->envCtx.lightningState = LIGHTNING_ON;
        play->envCtx.precipitation[PRECIP_RAIN_MAX] = 60;
        EnWeatherTag_SetupAction(this, EnWeatherTag_Unused_80967250);
    }
}
