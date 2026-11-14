// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kakasi.h"

void func_800002F8(EnKakasi* this) {
    if ((this->animIndex == ENKAKASI_ANIM_SIDEWAYS_SHAKING) || (this->animIndex == ENKAKASI_ANIM_ARMS_CROSSED_STILL)) {
        if (Animation_OnFrame(&this->skelAnime, 1.0f) || Animation_OnFrame(&this->skelAnime, 8.0f)) {
            Actor_PlaySfx(&this->picto.actor, NA_SE_EV_KAKASHI_SWING);
        }
    }
    if ((this->animIndex == ENKAKASI_ANIM_HOPPING_REGULAR) || (this->animIndex == ENKAKASI_ANIM_SLOWROLL)) {
        if (Animation_OnFrame(&this->skelAnime, 4.0f) || Animation_OnFrame(&this->skelAnime, 8.0f)) {
            Actor_PlaySfx(&this->picto.actor, NA_SE_EV_KAKASHI_SWING);
        }
        if (Animation_OnFrame(&this->skelAnime, 1.0f) || Animation_OnFrame(&this->skelAnime, 9.0f) ||
            Animation_OnFrame(&this->skelAnime, 16.0f)) {
            Actor_PlaySfx(&this->picto.actor, NA_SE_IT_KAKASHI_JUMP);
        }
        if (Animation_OnFrame(&this->skelAnime, 18.0f)) {
            Actor_PlaySfx(&this->picto.actor, NA_SE_EV_KAKASHI_ROLL);
        }
    }
    if ((this->animIndex == ENKAKASI_ANIM_SPIN_REACH_OFFER) || (this->animIndex == ENKAKASI_ANIM_TWIRL)) {
        if (Animation_OnFrame(&this->skelAnime, 1.0f)) {
            Actor_PlaySfx(&this->picto.actor, NA_SE_EV_KAKASH_LONGI_ROLL);
        }
    }
}
