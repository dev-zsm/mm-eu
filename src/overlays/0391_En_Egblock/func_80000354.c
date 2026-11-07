// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_egblock.h"

void EnEgblock_SpawnEffect(EnEgblock* this, Vec3f* pos, s16 lifetime, s16 arg3) {
    EnEgblockEffect* effect = this->effects;
    s16 i;

    for (i = 0; i < ARRAY_COUNT(this->effects); i++, effect++) {
        if (!effect->isActive) {
            effect->isActive = true;
            effect->pos = *pos;
            effect->pos.x += Rand_CenteredFloat(50.0f);
            effect->pos.z += Rand_CenteredFloat(50.0f);
            effect->timer = lifetime;
            effect->alpha = 255;
            effect->type = arg3;
            effect->accel.x = Rand_ZeroOne() - 0.5f;
            effect->accel.y = -1.0f;
            effect->accel.z = Rand_ZeroOne() - 0.5f;
            effect->velocity.x = 2.0f * (Rand_ZeroOne() - 0.5f);
            effect->velocity.y = 5.0f + (10.0f * Rand_ZeroOne());
            effect->velocity.z = 2.0f * (Rand_ZeroOne() - 0.5f);
            effect->scale = 0.5f + (0.2f * Rand_ZeroFloat(1.0f));
            effect->rot.x = Rand_CenteredFloat(0x7530);
            effect->rot.y = Rand_CenteredFloat(0x7530);
            effect->rot.z = Rand_CenteredFloat(0x7530);
            break;
        }
    }
}
