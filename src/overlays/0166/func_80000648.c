// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_clear_tag.h"

void EnClearTag_CreateLightRayEffect(EnClearTag* this, Vec3f* pos, Vec3f* velocity, Vec3f* accel, f32 scale,
                                     f32 maxScaleTarget, s16 alphaDecrementSpeed) {
    EnClearTagEffect* effect = this->effect;
    s16 i;

    
    for (i = 0; i < ARRAY_COUNT(this->effect) - 1; i++, effect++) {
        if (effect->type == CLEAR_TAG_EFFECT_AVAILABLE) {
            s32 requiredScopeTemp;

            effect->type = CLEAR_TAG_EFFECT_LIGHT_RAYS;

            effect->pos = *pos;
            effect->velocity = *velocity;
            effect->accel = *accel;

            effect->scale = scale / 1000.0f;
            effect->maxScale = 1.0f;
            effect->maxScaleTarget = maxScaleTarget;

            effect->lightRayAlpha = Rand_ZeroFloat(100.0f) + 200.0f;
            effect->lightRayAlphaDecrementSpeed = alphaDecrementSpeed;

            effect->actionTimer = Rand_ZeroFloat(10.0f);

            effect->rotationY = Math_Atan2F_XY(effect->velocity.z, effect->velocity.x);
            effect->rotationX = -Math_Atan2F_XY(sqrtf(SQXZ(effect->velocity)), effect->velocity.y);

            effect->envColor.r = 255.0f;
            effect->envColor.g = 255.0f;
            effect->envColor.b = 0.0f;
            effect->primColor.r = 255.0f;
            effect->primColor.g = 255.0f;
            effect->primColor.b = 255.0f;

            break;
        }
    }
}
