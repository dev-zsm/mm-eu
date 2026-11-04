// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_effect.h"

void Effect_UpdateAll(PlayState* play) {
    s32 i;

    for (i = 0; i < SPARK_COUNT; i++) {
        if (!sEffectContext.sparks[i].status.active) {
            continue;
        }
        if (sEffectInfoTable[EFFECT_SPARK].update(&sEffectContext.sparks[i].effect) == 1) {
            Effect_Destroy(play, i);
        }
    }

    for (i = 0; i < BLURE_COUNT; i++) {
        if (!sEffectContext.blures[i].status.active) {
            continue;
        }
        if (sEffectInfoTable[EFFECT_BLURE1].update(&sEffectContext.blures[i].effect) == 1) {
            Effect_Destroy(play, i + SPARK_COUNT);
        }
    }

    for (i = 0; i < SHIELD_PARTICLE_COUNT; i++) {
        if (!sEffectContext.shieldParticles[i].status.active) {
            continue;
        }
        if (sEffectInfoTable[EFFECT_SHIELD_PARTICLE].update(&sEffectContext.shieldParticles[i].effect) == 1) {
            Effect_Destroy(play, i + SPARK_COUNT + BLURE_COUNT);
        }
    }

    for (i = 0; i < TIRE_MARK_COUNT; i++) {
        if (!sEffectContext.tireMarks[i].status.active) {
            continue;
        }
        if (sEffectInfoTable[EFFECT_TIRE_MARK].update(&sEffectContext.tireMarks[i].effect) == 1) {
            Effect_Destroy(play, i + SPARK_COUNT + BLURE_COUNT + SHIELD_PARTICLE_COUNT);
        }
    }
}
