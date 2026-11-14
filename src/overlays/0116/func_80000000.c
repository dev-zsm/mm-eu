// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_horse_link_child.h"

void func_80000000(EnHorseLinkChild* this) {
    if ((sAnimSoundFrames[this->footstepCounter] < this->skin.skelAnime.curFrame) &&
        ((this->footstepCounter != 0) || !(sAnimSoundFrames[1] < this->skin.skelAnime.curFrame))) {
        Audio_PlaySfx_AtPos(&this->actor.projectedPos, NA_SE_EV_KID_HORSE_WALK);

        this->footstepCounter++;
        if (this->footstepCounter >= 2) {
            this->footstepCounter = 0;
        }
    }
}
