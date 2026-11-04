// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_clear_tag.h"

void EnClearTag_CreateFlashEffect(EnClearTag* this, Vec3f* pos, f32 scale, f32 floorHeight) {
    EnClearTagEffect* effect = this->effect;
    s16 i;

    
    for (i = 0; i < ARRAY_COUNT(this->effect) - 1; i++, effect++) {
        if (effect->type == CLEAR_TAG_EFFECT_AVAILABLE) {
            effect->type = CLEAR_TAG_EFFECT_FLASH;

            effect->pos = *pos;
            effect->velocity = sZeroVector;
            effect->accel = sZeroVector;

            effect->scale = 0.0f;
            effect->maxScale = scale * 3.0f;

            
            effect->rotationZ = floorHeight;

            effect->primColor.a = 255.0f;

            break;
        }
    }
}
