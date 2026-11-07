// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_dt_bubble.h"

void EffectSsDtBubble_Update(PlayState* play, u32 index, EffectSs* this) {
    if (this->rRandXZ == true) {
        this->pos.x += (Rand_ZeroOne() * 2.0f) - 1.0f;
        this->pos.z += (Rand_ZeroOne() * 2.0f) - 1.0f;
    }
}
