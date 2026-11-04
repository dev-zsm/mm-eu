// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_clear_tag.h"

void EnClearTag_CreateSplashEffect(EnClearTag* this, Vec3f* pos, s16 effectsTimer) {
    s16 i;
    EnClearTagEffect* effect = this->effect;

    
    for (i = 0; i < ARRAY_COUNT(this->effect) - 1; i++, effect++) {
        if (effect->type == CLEAR_TAG_EFFECT_AVAILABLE) {
            
            effect->actionTimer = Rand_ZeroFloat(100.0f);
            effect->type = CLEAR_TAG_EFFECT_SPLASH;

            effect->pos = *pos;
            effect->velocity = sZeroVector;
            effect->accel = sZeroVector;

            effect->scale = 0.0f;
            effect->maxScale = 0.0f;

            effect->actionTimer = 0;
            effect->effectsTimer = effectsTimer;

            effect->rotationX = 0.78f;

            break;
        }
    }
}
