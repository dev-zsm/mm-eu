// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_gakufu.h"

void EnGakufu_PlayRewardCutscene(EnGakufu* this, PlayState* play) {
    if (this->actor.csId == CS_ID_NONE) {
        EnGakufu_GiveReward(this, play);
    } else if (CutsceneManager_IsNext(this->actor.csId)) {
        CutsceneManager_StartWithPlayerCs(this->actor.csId, &this->actor);
        EnGakufu_GiveReward(this, play);
    } else {
        CutsceneManager_Queue(this->actor.csId);
    }
}
