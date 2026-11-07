// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ingate.h"

void ref_func_80954340(BgIngate* this, PlayState* play) {
    if (DECR(this->unk16A) == 0) {
        if (this->timePath != NULL) {
            Player_SetCsActionWithHaltedActors(play, &this->dyna.actor, PLAYER_CSACTION_END);
            this->timePath = &play->setupPathList[this->timePath->additionalPathIndex];
            ref_func_80953F14(this, play);
            Environment_StopTime();
        }
    }
}
