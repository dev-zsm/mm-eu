// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_bombwall.h"

void ref_func_80BD5134(BgIkanaBombwall* this, PlayState* play) {
    if (!BGIKANABOMBWALL_GET_100(&this->dyna.actor)) {
        this->unk_1AC--;
        if (this->unk_1AC <= 0) {
            CutsceneManager_Stop(this->dyna.actor.csId);
            Actor_Kill(&this->dyna.actor);
        }
    } else if (this->dyna.actor.csId > CS_ID_NONE) {
        if (CutsceneManager_GetCurrentCsId() != this->dyna.actor.csId) {
            Actor_Kill(&this->dyna.actor);
        }
    } else {
        Actor_Kill(&this->dyna.actor);
    }
}
