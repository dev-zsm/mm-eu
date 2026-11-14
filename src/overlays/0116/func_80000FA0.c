// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_horse_link_child.h"

void func_80000FA0(EnHorseLinkChild* this) {
    this->action = OOT_CHILD_EPONA_ACTION_5;

    if (Rand_ZeroOne() > 0.5f) {
        this->animIndex = OOT_CHILD_EPONA_ANIM_IDLE;
    } else {
        this->animIndex = OOT_CHILD_EPONA_ANIM_WHINNY;
    }

    gHorsePlayedEponasSong = false;
    Animation_Change(&this->skin.skelAnime, sAnimations[this->animIndex], EnHorseLinkChild_GetAnimSpeed(this), 0.0f,
                     Animation_GetLastFrame(sAnimations[this->animIndex]), ANIMMODE_ONCE, 0.0f);
}
