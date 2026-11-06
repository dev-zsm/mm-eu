// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_weather_tag.h"

void ref_func_80966A08(EnWeatherTag* this, PlayState* play) {
    this->unk154 += this->unk158;
    if (this->unk154 > 0x8000) {
        this->unk154 = 0x8000;
        EnWeatherTag_SetupAction(this, ref_func_80966A68);
    }
    ref_func_8096689C(this, play);
}
