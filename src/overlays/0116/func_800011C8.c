// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_horse_link_child.h"

void func_800011C8(EnHorseLinkChild* this) {
    this->timer = 0;
    this->action = OOT_CHILD_EPONA_ACTION_4;
    this->animIndex = OOT_CHILD_EPONA_ANIM_WALK;
    this->isReturningHome = false;
    this->actor.speed = 2.0f;
    Animation_Change(&this->skin.skelAnime, sAnimations[this->animIndex], EnHorseLinkChild_GetAnimSpeed(this), 0.0f,
                     Animation_GetLastFrame(sAnimations[this->animIndex]), ANIMMODE_ONCE, -5.0f);
}
