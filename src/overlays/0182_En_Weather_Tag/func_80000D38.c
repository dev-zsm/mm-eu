// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_weather_tag.h"

void ref_func_80967148(EnWeatherTag* this, PlayState* play) {
    s16 csId = this->actor.csId;

    if (CutsceneManager_IsNext(csId)) {
        CutsceneManager_Start(csId, &this->actor);
        EnWeatherTag_SetupAction(this, EnWeatherTag_DoNothing);
    } else {
        CutsceneManager_Queue(csId);
    }
}
