// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_blure.h"

void EffectBlure_GetComputedValues(EffectBlure* this, s32 index, f32 ratio, Vec3s* vec1, Vec3s* vec2,
                                   Color_RGBA8* color1, Color_RGBA8* color2) {
    Vec3s sp30;
    f32 mode4Param;
    EffectBlureElement* elem = &this->elements[index];
    Vec3s* unusedPtr = &sp30; 

    switch (this->calcMode) {
        case 1:
            vec1->x = EffectSs_LerpS16(elem->p1.x, elem->p2.x, ratio);
            vec1->y = EffectSs_LerpS16(elem->p1.y, elem->p2.y, ratio);
            vec1->z = EffectSs_LerpS16(elem->p1.z, elem->p2.z, ratio);
            vec2->x = elem->p2.x;
            vec2->y = elem->p2.y;
            vec2->z = elem->p2.z;
            break;

        case 2:
            vec1->x = elem->p1.x;
            vec1->y = elem->p1.y;
            vec1->z = elem->p1.z;
            vec2->x = EffectSs_LerpS16(elem->p2.x, elem->p1.x, ratio);
            vec2->y = EffectSs_LerpS16(elem->p2.y, elem->p1.y, ratio);
            vec2->z = EffectSs_LerpS16(elem->p2.z, elem->p1.z, ratio);
            break;

        case 3:
            ratio *= 0.5f;
            vec1->x = EffectSs_LerpS16(elem->p1.x, elem->p2.x, ratio);
            vec1->y = EffectSs_LerpS16(elem->p1.y, elem->p2.y, ratio);
            vec1->z = EffectSs_LerpS16(elem->p1.z, elem->p2.z, ratio);
            vec2->x = EffectSs_LerpS16(elem->p2.x, elem->p1.x, ratio);
            vec2->y = EffectSs_LerpS16(elem->p2.y, elem->p1.y, ratio);
            vec2->z = EffectSs_LerpS16(elem->p2.z, elem->p1.z, ratio);
            ratio *= 2.0f;
            break;

        case 4:
            sp30.x = elem->p1.x - elem->p2.x;
            sp30.y = elem->p1.y - elem->p2.y;
            sp30.z = elem->p1.z - elem->p2.z;
            mode4Param = this->mode4Param - 1.0f;

            vec1->x = (sp30.x * 0.5f * mode4Param * ratio) + elem->p1.x;
            vec1->y = (sp30.y * 0.5f * mode4Param * ratio) + elem->p1.y;
            
            if (1) {}
            vec1->z = (sp30.z * 0.5f * mode4Param * ratio) + elem->p1.z;

            vec2->x = -(sp30.x * 0.5f * mode4Param * ratio) + elem->p2.x;
            vec2->y = -(sp30.y * 0.5f * mode4Param * ratio) + elem->p2.y;
            vec2->z = -(sp30.z * 0.5f * mode4Param * ratio) + elem->p2.z;
            break;

        case 0:
        default:
            vec1->x = elem->p1.x;
            vec1->y = elem->p1.y;
            vec1->z = elem->p1.z;
            vec2->x = elem->p2.x;
            vec2->y = elem->p2.y;
            vec2->z = elem->p2.z;
            break;
    }

    if (this->flags & EFFECT_BLURE_FLAG_10) {
        color1->r = color1->g = color1->b = color1->a = 255;
        color2->r = color2->g = color2->b = color2->a = 255;
    } else {
        color1->r = EffectSs_LerpU8(this->p1StartColor[0], this->p1EndColor[0], ratio);
        color1->g = EffectSs_LerpU8(this->p1StartColor[1], this->p1EndColor[1], ratio);
        color1->b = EffectSs_LerpU8(this->p1StartColor[2], this->p1EndColor[2], ratio);
        color1->a = EffectSs_LerpU8(this->p1StartColor[3], this->p1EndColor[3], ratio);
        color2->r = EffectSs_LerpU8(this->p2StartColor[0], this->p2EndColor[0], ratio);
        color2->g = EffectSs_LerpU8(this->p2StartColor[1], this->p2EndColor[1], ratio);
        color2->b = EffectSs_LerpU8(this->p2StartColor[2], this->p2EndColor[2], ratio);
        color2->a = EffectSs_LerpU8(this->p2StartColor[3], this->p2EndColor[3], ratio);
    }
}
