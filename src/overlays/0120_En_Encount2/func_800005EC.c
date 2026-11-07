// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_encount2.h"

void EnEncount2_UpdateEffects(EnEncount2* this, PlayState* play) {
    s32 i;
    EnEncount2Effect* effect = this->effects;

    for (i = 0; i < ARRAY_COUNT(this->effects); i++, effect++) {
        if (effect->isEnabled) {
            effect->pos.x += effect->velocity.x;
            effect->pos.y += effect->velocity.y;
            effect->pos.z += effect->velocity.z;
            effect->velocity.x += effect->accel.x;
            effect->velocity.y += effect->accel.y;
            effect->velocity.z += effect->accel.z;

            if (effect->alphaFadeDelay != 0) {
                effect->alphaFadeDelay--;
            } else {
                effect->alpha -= 10;
                if (effect->alpha < 10) {
                    effect->isEnabled = 0;
                }
            }
        }
    }
}
