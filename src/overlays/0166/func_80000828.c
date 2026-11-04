// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_clear_tag.h"

void EnClearTag_CreateIsolatedLightRayEffect(EnClearTag* this, Vec3f* pos, Vec3f* velocity, Vec3f* accel, f32 scale,
                                             f32 maxScaleTarget, s16 colorIndex, s16 alphaDecrementSpeed) {
    EnClearTagEffect* effect = this->effect;
    s16 i;

    
    for (i = 0; i < ARRAY_COUNT(this->effect) - 1; i++, effect++) {
        if (effect->type == CLEAR_TAG_EFFECT_AVAILABLE) {
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

            effect->envColor.r = sLightRayEnvColor[colorIndex].x;
            effect->envColor.g = sLightRayEnvColor[colorIndex].y;
            effect->envColor.b = sLightRayEnvColor[colorIndex].z;
            effect->primColor.r = sLightRayPrimColor[colorIndex].x;
            effect->primColor.g = sLightRayPrimColor[colorIndex].y;
            effect->primColor.b = sLightRayPrimColor[colorIndex].z;

            break;
        }
    }
}
