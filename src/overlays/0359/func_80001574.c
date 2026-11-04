// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall.h"

s32 EnFall_RisingDebris_InitializeEffect(EnFall* this) {
    s16 angle;
    s32 i;
    f32 scale;

    for (i = 0; i < ARRAY_COUNT(debrisEffects); i++) {
        if (debrisEffects[i].modelIndex >= 3) {
            debrisEffects[i].modelIndex = (s32)Rand_ZeroFloat(3.0f);
            debrisEffects[i].pos.x = this->actor.world.pos.x;
            debrisEffects[i].pos.y = this->actor.world.pos.y;
            debrisEffects[i].pos.z = this->actor.world.pos.z;
            angle = Rand_CenteredFloat(0x10000);
            scale = (1.0f - (Rand_ZeroFloat(1.0f) * Rand_ZeroFloat(1.0f))) * 3000.0f;
            debrisEffects[i].pos.x += Math_SinS(angle) * scale;
            debrisEffects[i].pos.z += Math_CosS(angle) * scale;
            debrisEffects[i].velocity.x = 0.0f;
            debrisEffects[i].velocity.z = 0.0f;
            debrisEffects[i].velocity.y = 80.0f;
            debrisEffects[i].rot.x = Rand_CenteredFloat(0x10000);
            debrisEffects[i].rot.y = Rand_CenteredFloat(0x10000);
            debrisEffects[i].rot.z = Rand_CenteredFloat(0x10000);
            this->activeDebrisEffectCount++;
            return true;
        }
    }

    return false;
}
