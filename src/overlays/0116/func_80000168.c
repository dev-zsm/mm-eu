// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_horse_link_child.h"

f32 func_80000168(EnHorseLinkChild* this) {
    f32 animSpeed;

    if (this->animIndex == OOT_CHILD_EPONA_ANIM_WALK) {
        animSpeed = sAnimPlaySpeeds[this->animIndex] * this->actor.speed * (1.0f / 2.0f);
    } else if (this->animIndex == OOT_CHILD_EPONA_ANIM_TROT) {
        animSpeed = sAnimPlaySpeeds[this->animIndex] * this->actor.speed * (1.0f / 3.0f);
    } else if (this->animIndex == OOT_CHILD_EPONA_ANIM_GALLOP) {
        animSpeed = sAnimPlaySpeeds[this->animIndex] * this->actor.speed * (1.0f / 5.0f);
    } else {
        animSpeed = sAnimPlaySpeeds[this->animIndex];
    }

    return animSpeed;
}
