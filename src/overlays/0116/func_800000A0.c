// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_horse_link_child.h"

void func_800000A0(EnHorseLinkChild* this) {
    if (this->animIndex == OOT_CHILD_EPONA_ANIM_WALK) {
        EnHorseLinkChild_PlayWalkingSound(this);
    } else if (this->skin.skelAnime.curFrame == 0.0f) {
        if ((this->animIndex == OOT_CHILD_EPONA_ANIM_TROT) || (this->animIndex == OOT_CHILD_EPONA_ANIM_GALLOP)) {
            Audio_PlaySfx_AtPos(&this->actor.projectedPos, NA_SE_EV_KID_HORSE_RUN);
        } else if (this->animIndex == OOT_CHILD_EPONA_ANIM_WHINNY) {
            if (Rand_ZeroOne() > 0.5f) {
                Audio_PlaySfx_AtPos(&this->actor.projectedPos, NA_SE_EV_KID_HORSE_GROAN);
            } else {
                Audio_PlaySfx_AtPos(&this->actor.projectedPos, NA_SE_EV_KID_HORSE_NEIGH);
            }
        }
    }
}
