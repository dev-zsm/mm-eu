// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_weather_tag.h"

void ref_func_80966A68(EnWeatherTag* this, PlayState* play) {
    this->unk154 -= (this->unk158 >> 1);
    if (this->unk154 == 0) {
        this->unk154 = 1;
    }

    if ((s16)this->unk154 < 0) { 
        this->unk154 = 0;
        
        Actor_Kill(&this->actor);
        EnWeatherTag_SetupAction(this, EnWeatherTag_Die);
    }

    ref_func_8096689C(this, play);
}
