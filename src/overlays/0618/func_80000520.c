// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bombal.h"

void EnBombal_InitEffects(EnBombal* this, Vec3f* pos, s16 fadeDelay) {
    s16 i;
    EnBombalEffect* effect = this->effects;

    for (i = 0; i < ARRAY_COUNT(this->effects); i++, effect++) {
        if (!effect->isEnabled) {
            effect->isEnabled = true;
            effect->pos = *pos;
            effect->alphaFadeDelay = fadeDelay;
            effect->alpha = 255;

            effect->accel.x = (Rand_ZeroOne() - 0.5f) * 10.0f;
            effect->accel.y = (Rand_ZeroOne() - 0.5f) * 10.0f;
            effect->accel.z = (Rand_ZeroOne() - 0.5f) * 10.0f;

            effect->velocity.x = Rand_ZeroOne() - 0.5f;
            effect->velocity.y = Rand_ZeroOne() - 0.5f;
            effect->velocity.z = Rand_ZeroOne() - 0.5f;

            effect->scale = (Rand_ZeroFloat(1.0f) * 0.5f) + 2.0f;
            return;
        }
    }
}
