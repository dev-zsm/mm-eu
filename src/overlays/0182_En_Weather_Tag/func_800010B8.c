// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_weather_tag.h"

void ref_func_809674C8(EnWeatherTag* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (Actor_WorldDistXZToActor(&player->actor, &this->actor) < WEATHER_TAG_RANGE100(&this->actor)) {
        if (CURRENT_DAY == 2) {
            if ((CURRENT_TIME >= CLOCK_TIME(7, 0)) && (CURRENT_TIME < CLOCK_TIME(17, 30)) &&
                (play->envCtx.precipitation[PRECIP_SNOW_CUR] == 0)) {

                gWeatherMode = WEATHER_MODE_RAIN;
                Environment_PlayStormNatureAmbience(play);
                play->envCtx.precipitation[PRECIP_SOS_MAX] = 32;
                EnWeatherTag_SetupAction(this, ref_func_80967608);
            }
        }
    } else {
        if ((play->envCtx.precipitation[PRECIP_SOS_MAX] != 0) && !(play->state.frames & 3)) {
            play->envCtx.precipitation[PRECIP_SOS_MAX]--;
            if ((play->envCtx.precipitation[PRECIP_SOS_MAX]) == 8) {
                Environment_StopStormNatureAmbience(play);
            }
        }
    }
}
