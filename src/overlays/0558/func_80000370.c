// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_f40_switch.h"

void BgF40Switch_Unpress(BgF40Switch* this, PlayState* play) {
    this->dyna.actor.scale.y += 0.0495f;
    if (this->dyna.actor.scale.y >= 0.165f) {
        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_IKANA_BLOCK_SWITCH);
        this->actionFunc = BgF40Switch_IdleUnpressed;
        this->dyna.actor.scale.y = 0.165f;
    }
}
