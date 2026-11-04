// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_effect.h"

void* Effect_GetByIndex(s32 index) {
    if (index == TOTAL_EFFECT_COUNT) {
        return NULL;
    }

    if (index < SPARK_COUNT) {
        if (sEffectContext.sparks[index].status.active == true) {
            return &sEffectContext.sparks[index].effect;
        } else {
            return NULL;
        }
    }

    index -= SPARK_COUNT;
    if (index < BLURE_COUNT) {
        if (sEffectContext.blures[index].status.active == true) {
            return &sEffectContext.blures[index].effect;
        } else {
            return NULL;
        }
    }

    index -= BLURE_COUNT;
    if (index < SHIELD_PARTICLE_COUNT) {
        if (sEffectContext.shieldParticles[index].status.active == true) {
            return &sEffectContext.shieldParticles[index].effect;
        } else {
            return NULL;
        }
    }

    index -= SHIELD_PARTICLE_COUNT;
    if (index < TIRE_MARK_COUNT) {
        if (sEffectContext.tireMarks[index].status.active == true) {
            return &sEffectContext.tireMarks[index].effect;
        } else {
            return NULL;
        }
    }

    return NULL;
}
