// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_weather_tag.h"

void ref_func_809672DC(EnWeatherTag* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    s32 pad;
    f32 distance;
    f32 range;
    f32 strength = 0.0f;

    Actor_GetClosestPosOnPath(this->pathPoints, this->pathCount, &GET_PLAYER(play)->actor.world.pos,
                              &this->actor.world.pos, false);

    distance = Actor_WorldDistXZToActor(&player->actor, &this->actor);
    range = WEATHER_TAG_RANGE100(&this->actor);

    if (distance < range) {
        play->envCtx.sandstormState = SANDSTORM_6;
        strength = 1.0f - (distance / range);
        if (0.8f < strength) {
            strength = 1.0f;
        }
        ref_D_801F4E30 = 200.0f * strength;
    } else if (play->envCtx.sandstormState == SANDSTORM_6) {
        ref_D_801F4E30 = 0;
        play->envCtx.sandstormState = SANDSTORM_7;
    }

    Math_SmoothStepToS(&play->envCtx.adjLightSettings.fogNear, -40.0f * strength, 1, 1, 1);
}
