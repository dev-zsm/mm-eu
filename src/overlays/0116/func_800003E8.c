// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_horse_link_child.h"

void func_800003E8(EnHorseLinkChild* this) {
    this->action = OOT_CHILD_EPONA_ACTION_0;
    this->animIndex++;
    if (this->animIndex >= OOT_CHILD_EPONA_ANIM_MAX) {
        this->animIndex = OOT_CHILD_EPONA_ANIM_IDLE;
    }
    Animation_PlayOnce(&this->skin.skelAnime, sAnimations[this->animIndex]);
    this->skin.skelAnime.playSpeed = EnHorseLinkChild_GetAnimSpeed(this);
}
