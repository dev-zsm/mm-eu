// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_weather_tag.h"

void ref_func_8096689C(EnWeatherTag* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    f32 distance;
    f32 partialResult;

    distance = Actor_WorldDistXZToActor(&player->actor, &this->actor);
    if (this->fadeDistance < distance) {
        distance = this->fadeDistance;
    }

    if (this->fadeDistance == 0) {
        this->fadeDistance = 1; 
    }

    
    partialResult = 1.0f - (distance / this->fadeDistance);    
    partialResult = (this->unk154 / 32768.0f) * partialResult; 

    play->envCtx.windSpeed = (this->actor.world.rot.z * partialResult) + 30.0f;
    if (partialResult > 0.01f) {
        play->envCtx.sandstormState = SANDSTORM_8;
        ref_D_801F4E30 = 0x9B;
    } else if (play->envCtx.sandstormState == SANDSTORM_8) {
        ref_D_801F4E30 = 0;
        play->envCtx.sandstormState = SANDSTORM_9;
    }
}
