// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_clear_tag.h"

void EnClearTag_CreateDebrisEffect(EnClearTag* this, Vec3f* pos, Vec3f* velocity, Vec3f* accel, f32 scale,
                                   f32 rotationZ) {
    EnClearTagEffect* effect = this->effect;
    s16 i;

    
    for (i = 0; i < ARRAY_COUNT(this->effect) - 1; i++, effect++) {
        if (effect->type == CLEAR_TAG_EFFECT_AVAILABLE) {
            effect->type = CLEAR_TAG_EFFECT_DEBRIS;

            effect->pos = *pos;
            effect->velocity = *velocity;
            effect->accel = *accel;

            effect->scale = scale;

            
            effect->rotationY = Rand_ZeroFloat(M_PIf * 2);
            effect->rotationX = Rand_ZeroFloat(M_PIf * 2);

            effect->effectsTimer = effect->bounces = 0;

            effect->rotationZ = rotationZ;

            effect->actionTimer = Rand_ZeroFloat(10.0f);

            break;
        }
    }
}
