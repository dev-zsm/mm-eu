// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_effect.h"

void Effect_DrawAll(GraphicsContext* gfxCtx) {
    s32 i;

    for (i = 0; i < SPARK_COUNT; i++) {
        if (!sEffectContext.sparks[i].status.active) {
            continue;
        }
        sEffectInfoTable[EFFECT_SPARK].draw(&sEffectContext.sparks[i].effect, gfxCtx);
    }

    for (i = 0; i < BLURE_COUNT; i++) {
        if (!sEffectContext.blures[i].status.active) {
            continue;
        }
        sEffectInfoTable[EFFECT_BLURE1].draw(&sEffectContext.blures[i].effect, gfxCtx);
    }

    for (i = 0; i < SHIELD_PARTICLE_COUNT; i++) {
        if (!sEffectContext.shieldParticles[i].status.active) {
            continue;
        }
        sEffectInfoTable[EFFECT_SHIELD_PARTICLE].draw(&sEffectContext.shieldParticles[i].effect, gfxCtx);
    }

    for (i = 0; i < TIRE_MARK_COUNT; i++) {
        if (!sEffectContext.tireMarks[i].status.active) {
            continue;
        }
        sEffectInfoTable[EFFECT_TIRE_MARK].draw(&sEffectContext.tireMarks[i].effect, gfxCtx);
    }
}
