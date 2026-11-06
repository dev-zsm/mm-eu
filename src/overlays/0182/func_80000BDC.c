// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_weather_tag.h"

void ref_func_80966FEC(EnWeatherTag* this, PlayState* play) {
    s32 numStars = WEATHER_TAG_GET_SKYBOX_NUM_STARS(&this->actor);

    if (numStars > 0) {
        gSkyboxNumStars = numStars;
    }

    if ((play->sceneId == SCENE_KAIZOKU) && (play->actorCtx.flags & ACTORCTX_FLAG_TELESCOPE_ON)) {
        EnWeatherTag_SetupAction(this, ref_func_80967060);
    }
}
