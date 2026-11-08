// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_weather_tag.h"

void ref_func_80966B08(EnWeatherTag* this, PlayState* play) {
    if (ref_func_80966608(this, play, 0, 0, play->envCtx.lightConfig, 5, 100, WEATHER_MODE_2) ||
        (gWeatherMode == WEATHER_MODE_2)) {
        play->skyboxId = SKYBOX_3;
        EnWeatherTag_SetupAction(this, ref_func_80966D20);
    } else if (ref_D_801F4E74 <= 0.01f) {
        play->skyboxId = SKYBOX_NORMAL_SKY;
    } else {
        Math_SmoothStepToF(&ref_D_801F4E74, 0.0f, 0.2f, 0.02f, 0.001f);
    }
}
