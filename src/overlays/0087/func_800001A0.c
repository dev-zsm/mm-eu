// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_river_sound.h"

void EnRiverSound_Draw(Actor* thisx, PlayState* play) {
    static f32 freqScale[] = {
        0.7f, 
        1.0f, 
        1.4f, 
    };
    EnRiverSound* this = (EnRiverSound*)thisx;
    s16 params = this->actor.params;

    if (params < RS_RIVER_DEFAULT_LOW_FREQ) {
        Actor_PlaySfx(&this->actor, gAudioEnvironmentalSfx[params]);
    } else {
        Audio_PlaySfx_River(&this->actor.projectedPos, freqScale[this->soundFreqIndex]);
    }
}
