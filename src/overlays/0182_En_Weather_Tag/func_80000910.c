// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_weather_tag.h"

void ref_func_80966D20(EnWeatherTag* this, PlayState* play) {
    u8 lightConfig;

    switch (gSaveContext.save.day) {
        case 0:
        case 1:
        default:
            lightConfig = 0;
            break;

        case 2:
            lightConfig = 3;
            break;

        case 3:
            lightConfig = 4;
            break;
    }

    Math_SmoothStepToF(&ref_D_801F4E74, 1.0f, 0.2f, 0.02f, 0.001f);

    if (ref_func_80966758(this, play, 1, 0, 5, lightConfig, 100)) {
        EnWeatherTag_SetupAction(this, ref_func_80966B08);
    }

    if (gWeatherMode != WEATHER_MODE_2) {
        EnWeatherTag_SetupAction(this, ref_func_80966B08);
    }
}
