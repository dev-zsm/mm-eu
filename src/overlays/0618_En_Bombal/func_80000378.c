// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bombal.h"

void ref_func_80C05DE8(EnBombal* this, PlayState* play) {
    if (this->timer == 0) {
        if (!CHECK_WEEKEVENTREG(WEEKEVENTREG_75_40) && !CHECK_WEEKEVENTREG(WEEKEVENTREG_73_10) &&
            !CHECK_WEEKEVENTREG(WEEKEVENTREG_85_02)) {
            CutsceneManager_Stop(this->csId);
        }
        Actor_Kill(&this->actor);
        return;
    }

    if (this->timer < 10) {
        this->actor.colChkInfo.health = 0;
    }
}
