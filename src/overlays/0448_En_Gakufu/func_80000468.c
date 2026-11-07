// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_gakufu.h"

void EnGakufu_WaitForSong(EnGakufu* this, PlayState* play) {
    if (CHECK_EVENTINF(EVENTINF_31)) {
        if (CHECK_EVENTINF(EVENTINF_32)) {
            CLEAR_EVENTINF(EVENTINF_31);
            CLEAR_EVENTINF(EVENTINF_32);

            this->actionFunc = EnGakufu_PlayRewardCutscene;
            EnGakufu_PlayRewardCutscene(this, play);
            this->actor.draw = NULL;
        } else if (!EnGakufu_IsPlayerInRange(this, play)) {
            CLEAR_EVENTINF(EVENTINF_31);
        }
    } else if (EnGakufu_IsPlayerInRange(this, play)) {
        SET_EVENTINF(EVENTINF_31);
    }
}
