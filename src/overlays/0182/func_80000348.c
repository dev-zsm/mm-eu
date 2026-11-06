// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_weather_tag.h"

u8 ref_func_80966758(EnWeatherTag* this, PlayState* play, UNK_TYPE a3, UNK_TYPE a4, u8 lightConfig,
                 u8 changeLightNextConfig, u16 changeDuration) {
    Player* player = GET_PLAYER(play);
    u8 returnVal = 0;

    if (WEATHER_TAG_RANGE100(&this->actor) < Actor_WorldDistXZToActor(&player->actor, &this->actor)) {
        if (play->envCtx.lightConfig == play->envCtx.changeLightNextConfig) {
            gInterruptSongOfStorms = true;
            if (!(play->envCtx.lightMode == LIGHT_MODE_TIME) ||
                ((play->envCtx.lightConfig != 1) && !play->envCtx.changeLightEnabled)) {

                gInterruptSongOfStorms = false;
                gWeatherMode = WEATHER_MODE_CLEAR;
                play->envCtx.changeLightEnabled = true;
                play->envCtx.lightConfig = lightConfig;
                play->envCtx.changeLightNextConfig = changeLightNextConfig;
                gLightConfigAfterUnderwater = changeLightNextConfig;
                play->envCtx.changeDuration = changeDuration;
                play->envCtx.changeLightTimer = play->envCtx.changeDuration;
                returnVal = 1;
            }
        }
    }
    return returnVal;
}
