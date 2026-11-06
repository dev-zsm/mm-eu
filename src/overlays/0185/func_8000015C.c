// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_okarina_effect.h"

void ref_func_8096B1FC(EnOkarinaEffect* this, PlayState* play) {
    if (play->envCtx.precipitation[PRECIP_SOS_MAX] != 0) {
        if ((play->state.frames & 3) == 0) {
            play->envCtx.precipitation[PRECIP_SOS_MAX]--;
            if (play->envCtx.precipitation[PRECIP_SOS_MAX] == 8) {
                Environment_StopStormNatureAmbience(play);
            }
        }
    } else {
        Actor_Kill(&this->actor);
    }
}
