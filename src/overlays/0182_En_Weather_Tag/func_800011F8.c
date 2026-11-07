// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_weather_tag.h"

void ref_func_80967608(EnWeatherTag* this, PlayState* play) {
    if ((WEATHER_TAG_RANGE100(&this->actor) + 10.0f) <
        Actor_WorldDistXZToActor(&GET_PLAYER(play)->actor, &this->actor)) {
        gWeatherMode = WEATHER_MODE_CLEAR;
        EnWeatherTag_SetupAction(this, ref_func_809674C8);
    }
}
