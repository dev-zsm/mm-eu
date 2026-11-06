// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_weather_tag.h"

void ref_func_80967060(EnWeatherTag* this, PlayState* play) {
    Vec3f worldPos;
    Vec3f screenPos;

    worldPos.x = 1055.0f;
    worldPos.y = -145.0f;
    worldPos.z = 181.0f;

    Play_GetScreenPos(play, &worldPos, &screenPos);

    if (play->view.fovy < 25.0f) {
        if ((screenPos.x >= 70.0f) && (screenPos.x < (SCREEN_WIDTH - 70.0f)) && (screenPos.y >= 30.0f) &&
            (screenPos.y < (SCREEN_HEIGHT - 30.0f))) {
            EnWeatherTag_SetupAction(this, ref_func_80967148);
        }
    }
}
