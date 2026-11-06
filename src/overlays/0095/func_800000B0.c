// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_breakwall.h"

bool ref_func_808B7410(BgBreakwall* this, PlayState* play) {
    if (Flags_GetSwitch(play, this->switchFlag)) {
        this->dyna.actor.draw = NULL;
    }
    Actor_SetScale(&this->dyna.actor, 0.1f);
    return true;
}
