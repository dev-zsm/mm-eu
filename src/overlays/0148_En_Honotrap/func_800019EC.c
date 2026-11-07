// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_honotrap.h"

void EnHonotrap_UpdateFlameGroup(Actor* thisx, PlayState* play) {
    EnHonotrap* this = (EnHonotrap*)thisx;
    Actor* parent = this->actor.parent;

    if ((parent != NULL) && (parent->update == NULL)) {
        this->actor.parent = NULL;
    }
    if (this->timer > 0) {
        this->timer--;
    }
    this->bobPhase += 0x640;
    Actor_PlaySfx(&this->actor, NA_SE_EV_BURN_OUT - SFX_FLAG);
    this->actionFunc(this, play);
}
