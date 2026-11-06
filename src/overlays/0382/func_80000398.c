// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char03.h"

void ref_func_80AAB838(DmChar03* this, PlayState* play) {
    if (Animation_OnFrame(&this->skelAnime, 5.0f)) {
        Actor_PlaySfx(&this->actor, NA_SE_IT_MASK_BOUND_0);
    } else if (Animation_OnFrame(&this->skelAnime, 10.0f) || Animation_OnFrame(&this->skelAnime, 18.0f) ||
               Animation_OnFrame(&this->skelAnime, 30.0f) || Animation_OnFrame(&this->skelAnime, 38.0f)) {
        Actor_PlaySfx(&this->actor, NA_SE_IT_MASK_BOUND_1);
    }
}
