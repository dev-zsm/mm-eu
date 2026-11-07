// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_cha.h"

void EnCha_Ring(EnCha* this, PlayState* play) {
    EnCha_Idle(this, play);
    if (this->actor.csId == CS_ID_NONE) {
        this->actionFunc = EnCha_Idle;
    } else if (CutsceneManager_IsNext(this->actor.csId)) {
        CutsceneManager_StartWithPlayerCs(this->actor.csId, &this->actor);
        this->actionFunc = EnCha_Idle;
    } else {
        CutsceneManager_Queue(this->actor.csId);
    }
}
