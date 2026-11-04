// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_clear_tag.h"

void EnClearTag_UpdateEffects(EnClearTag* this, PlayState* play) {
    EnClearTagEffect* effect = this->effect;
    s16 i;
    f32 originalYPosition;
    Vec3f sphereCenter;
    s32 pad;

    for (i = 0; i < ARRAY_COUNT(this->effect); i++, effect++) {
        if (effect->type != CLEAR_TAG_EFFECT_AVAILABLE) {
            effect->actionTimer++;

            
            effect->pos.x += effect->velocity.x;
            originalYPosition = effect->pos.y;
            effect->pos.y += effect->velocity.y;
            effect->pos.z += effect->velocity.z;
            effect->velocity.x += effect->accel.x;
            effect->velocity.y += effect->accel.y;
            effect->velocity.z += effect->accel.z;

            if (effect->type == CLEAR_TAG_EFFECT_DEBRIS) {
                
                if (effect->velocity.y < -5.0f) {
                    effect->velocity.y = -5.0f;
                }

                
                if (effect->velocity.y < 0.0f) {
                    sphereCenter = effect->pos;
                    sphereCenter.y += 5.0f;

                    
                    if (BgCheck_SphVsFirstPoly(&play->colCtx, &sphereCenter, 11.0f)) {
                        effect->pos.y = originalYPosition;

                        
                        if (effect->bounces <= 0) {
                            effect->bounces++;
                            effect->velocity.y *= -0.5f;
                            effect->effectsTimer = Rand_ZeroFloat(20.0f) + 25.0f;
                        } else {
                            
                            effect->velocity.x = effect->velocity.z = effect->accel.y = effect->velocity.y = 0.0f;
                        }
                    }
                }

                
                if (effect->accel.y != 0.0f) {
                    effect->rotationY += 0.5f;
                    effect->rotationX += 0.35f;
                }

                if (effect->effectsTimer == 1) {
                    effect->type = CLEAR_TAG_EFFECT_AVAILABLE;
                }
            } else if (effect->type == CLEAR_TAG_EFFECT_FIRE) {
                
                Math_ApproachZeroF(&effect->primColor.a, 1.0f, 15.0f);
                if (effect->primColor.a <= 0.0f) {
                    effect->type = CLEAR_TAG_EFFECT_AVAILABLE;
                }
            } else if (effect->type == CLEAR_TAG_EFFECT_SHOCKWAVE) {
                if (effect->actionTimer > 3) {
                    Math_ApproachF(&effect->scale, effect->maxScale, 0.2f, effect->maxScale * 0.6666666f);
                    Math_ApproachZeroF(&effect->primColor.a, 1.0f, 15.0f);
                    if (effect->primColor.a <= 0.0f) {
                        effect->type = CLEAR_TAG_EFFECT_AVAILABLE;
                    }
                }
            } else if (effect->type == CLEAR_TAG_EFFECT_SMOKE) {
                
                Math_ApproachZeroF(&effect->primColor.r, 1.0f, 20.0f);
                Math_ApproachZeroF(&effect->primColor.g, 1.0f, 2.0f);
                Math_ApproachZeroF(&effect->envColor.r, 1.0f, 25.5f);
                Math_ApproachZeroF(&effect->envColor.g, 1.0f, 21.5f);
                Math_ApproachZeroF(&effect->envColor.b, 1.0f, 25.5f);

                
                Math_ApproachF(&effect->scale, effect->maxScale, 0.05f, 0.1f);

                if (effect->primColor.r == 0.0f) {
                    Math_ApproachF(&effect->smokeScaleX, 3.0f, 0.1f, 0.01f);
                    Math_ApproachF(&effect->smokeScaleY, 3.0f, 0.1f, 0.02f);

                    
                    Math_ApproachZeroF(&effect->primColor.a, 1.0f, 5.f);

                    
                    if (effect->primColor.a <= 0.0f) {
                        effect->type = CLEAR_TAG_EFFECT_AVAILABLE;
                    }
                }
            } else if (effect->type == CLEAR_TAG_EFFECT_ISOLATED_SMOKE) {
                
                Math_ApproachF(&effect->scale, effect->maxScale, 0.05f, 0.1f);
                if (effect->actionTimer > 10) {
                    Math_ApproachF(&effect->smokeScaleX, 3.0f, 0.1f, 0.01f);
                    Math_ApproachF(&effect->smokeScaleY, 3.0f, 0.1f, 0.02f);

                    
                    Math_ApproachZeroF(&effect->primColor.a, 1.0f, 5.f);
                    if (effect->primColor.a <= 0.0f) {
                        effect->type = CLEAR_TAG_EFFECT_AVAILABLE;
                    }
                }
            } else if (effect->type == CLEAR_TAG_EFFECT_FLASH) {
                
                Math_ApproachF(&effect->scale, effect->maxScale, 0.5f, 6.0f);

                
                Math_ApproachZeroF(&effect->primColor.a, 1.0f, 15.0f);
                if (effect->primColor.a <= 0.0f) {
                    effect->type = CLEAR_TAG_EFFECT_AVAILABLE;
                }
            } else if (effect->type == CLEAR_TAG_EFFECT_LIGHT_RAYS) {
                
                effect->rotationZ += Rand_ZeroFloat(M_PIf / 2) + (M_PIf / 2);

                
                effect->lightRayAlpha -= effect->lightRayAlphaDecrementSpeed;
                if (effect->lightRayAlpha <= 0) {
                    effect->lightRayAlpha = 0;
                    effect->type = CLEAR_TAG_EFFECT_AVAILABLE;
                }
                effect->primColor.a = effect->lightRayAlpha;
                if (effect->primColor.a > 255.0f) {
                    effect->primColor.a = 255.0f;
                }

                
                Math_ApproachF(&effect->maxScale, effect->maxScaleTarget, 1.0f,
                               (effect->maxScaleTarget / 15.0f) * 4.0f);
            } else if (effect->type == CLEAR_TAG_EFFECT_SPLASH) {
                if (effect->effectsTimer == 0) {
                    effect->scale = 7.0f;

                    
                    Math_ApproachF(&effect->maxScale, 500.0f, 1.0f, 50.0f);
                    Math_ApproachF(&effect->rotationX, 1.5f, 1.0f, 0.12f);
                    if (effect->actionTimer > 7) {
                        effect->type = CLEAR_TAG_EFFECT_AVAILABLE;
                    }
                } else {
                    effect->actionTimer = 0;
                }
            }

            if (effect->effectsTimer != 0) {
                effect->effectsTimer--;
            }
        }
    }
}
