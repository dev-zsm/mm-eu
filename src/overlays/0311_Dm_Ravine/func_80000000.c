// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_ravine.h"

void DmRavine_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    DmRavine* this = (DmRavine*)thisx;

    if (CHECK_WEEKEVENTREG_ALT(WEEKEVENTREG_ENTERED_GORMAN_TRACK) | cREG(0)) {
        Actor_Kill(&this->actor);
        return;
    }

    this->isActive = false;
    play->roomCtx.unk7A[0] = 1;
    play->roomCtx.unk7A[1] = 0;
    this->state = 0;
    Actor_SetScale(&this->actor, 1.0f);
    this->actionFunc = DmRavine_DoNothing;
}
