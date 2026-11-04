// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_clear_tag.h"

void EnClearTag_CreateShockwaveEffect(EnClearTag* this, Vec3f* pos, f32 maxScale, s16 actionTimer) {
    EnClearTagEffect* effect = this->effect;
    s16 i;

    
    for (i = 0; i < ARRAY_COUNT(this->effect) - 1; i++, effect++) {
        if (effect->type == CLEAR_TAG_EFFECT_AVAILABLE) {
            effect->type = CLEAR_TAG_EFFECT_SHOCKWAVE;

            effect->pos = *pos;
            effect->velocity = sZeroVector;
            effect->accel = sZeroVector;

            effect->maxScale = maxScale;
            effect->scale = 0.0f;

            effect->actionTimer = actionTimer;

            effect->primColor.a = 200.0f;

            break;
        }
    }
}
