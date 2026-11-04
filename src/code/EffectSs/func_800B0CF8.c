// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_effect_soft_sprite.h"

void EffectSs_Draw(PlayState* play, s32 index) {
    EffectSs* effectSs = &sEffectSsInfo.table[index];

    if (effectSs->draw != NULL) {
        effectSs->draw(play, index, effectSs);
    }
}
