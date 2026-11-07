// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_clear_tag.h"

void EnClearTag_CreateIsolatedSmokeEffect(EnClearTag* this, Vec3f* pos, f32 scale) {
    s16 i;
    EnClearTagEffect* effect = this->effect;

    
    for (i = 0; i < ARRAY_COUNT(this->effect); i++, effect++) {
        if (effect->type == CLEAR_TAG_EFFECT_AVAILABLE) {
            effect->actionTimer = Rand_ZeroFloat(100.0f);
            effect->type = CLEAR_TAG_EFFECT_ISOLATED_SMOKE;

            effect->pos = *pos;
            effect->velocity = sZeroVector;
            effect->accel = sZeroVector;

            effect->scale = scale;
            effect->maxScale = 2.0f * scale;
            effect->smokeScaleX = 1.0f;
            effect->smokeScaleY = 1.0f;

            if (scale <= 1.1f) {
                effect->scale = ((KREG(23) * 0.1f) + 1.0f) * scale;
                effect->primColor.a = KREG(16) + 150.0f;
                effect->primColor.r = KREG(17);
                effect->primColor.g = KREG(18);
                effect->primColor.b = KREG(19);
                effect->envColor.r = KREG(20);
                effect->envColor.g = KREG(21);
                effect->envColor.b = KREG(22);
            } else {
                effect->envColor.r = effect->envColor.g = effect->envColor.b = 0.0f;
                effect->primColor.r = effect->primColor.g = effect->primColor.b = 0.0f;
                effect->primColor.a = 255.0f;
            }

            break;
        }
    }
}
