// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_weather_tag.h"

void ref_func_80966E0C(EnWeatherTag* this, PlayState* play) {
    if (ref_func_80966608(this, play, 0, 1, 0, 2, 60, WEATHER_MODE_SNOW)) {
        play->envCtx.precipitation[PRECIP_SNOW_MAX] = 128;
        EnWeatherTag_SetupAction(this, ref_func_80966E84);
    }
}
