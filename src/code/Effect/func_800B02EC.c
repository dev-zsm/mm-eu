// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_effect.h"

void Effect_Destroy(PlayState* play, s32 index) {
    if (index == TOTAL_EFFECT_COUNT) {
        return;
    }

    if (index < SPARK_COUNT) {
        sEffectContext.sparks[index].status.active = false;
        sEffectInfoTable[EFFECT_SPARK].destroy(&sEffectContext.sparks[index].effect);
        return;
    }

    index -= SPARK_COUNT;
    if (index < BLURE_COUNT) {
        sEffectContext.blures[index].status.active = false;
        sEffectInfoTable[EFFECT_BLURE1].destroy(&sEffectContext.blures[index].effect);
        return;
    }

    index -= BLURE_COUNT;
    if (index < SHIELD_PARTICLE_COUNT) {
        sEffectContext.shieldParticles[index].status.active = false;
        sEffectInfoTable[EFFECT_SHIELD_PARTICLE].destroy(&sEffectContext.shieldParticles[index].effect);
        return;
    }

    index -= SHIELD_PARTICLE_COUNT;
    if (index < TIRE_MARK_COUNT) {
        sEffectContext.tireMarks[index].status.active = false;
        sEffectInfoTable[EFFECT_TIRE_MARK].destroy(&sEffectContext.tireMarks[index].effect);
        return;
    }
}
