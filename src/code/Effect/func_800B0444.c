// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_effect.h"

void Effect_DestroyAll(PlayState* play) {
    s32 i;

    for (i = 0; i < SPARK_COUNT; i++) {
        sEffectContext.sparks[i].status.active = false;
        sEffectInfoTable[EFFECT_SPARK].destroy(&sEffectContext.sparks[i].effect);
    }

    for (i = 0; i < BLURE_COUNT; i++) {
        sEffectContext.blures[i].status.active = false;
        sEffectInfoTable[EFFECT_BLURE1].destroy(&sEffectContext.blures[i].effect);
    }

    for (i = 0; i < SHIELD_PARTICLE_COUNT; i++) {
        sEffectContext.shieldParticles[i].status.active = false;
        sEffectInfoTable[EFFECT_SHIELD_PARTICLE].destroy(&sEffectContext.shieldParticles[i].effect);
    }

    for (i = 0; i < TIRE_MARK_COUNT; i++) {
        sEffectContext.tireMarks[i].status.active = false;
        sEffectInfoTable[EFFECT_TIRE_MARK].destroy(&sEffectContext.tireMarks[i].effect);
    }
}
