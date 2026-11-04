// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_blure.h"

void EffectBlure_UpdateFlags(EffectBlureElement* elem) {
    Vec3f sp64;
    Vec3f sp58;
    Vec3f sp4C;
    Vec3f sp40;
    EffectBlureElement* prev = elem - 1;
    EffectBlureElement* next = elem + 1;
    f32 sp34;
    f32 sp30;
    f32 sp2C;

    if (((elem - 1)->state == 0) || ((elem + 1)->state == 0)) {
        elem->flags &= ~(EFFECT_BLURE_ELEMENT_FLAG_1 | EFFECT_BLURE_ELEMENT_FLAG_2);
        elem->flags |= EFFECT_BLURE_ELEMENT_FLAG_2;
    } else {
        Math_Vec3s_DiffToVec3f(&sp64, &elem->p1, &prev->p1);
        Math_Vec3s_DiffToVec3f(&sp58, &elem->p2, &prev->p2);
        Math_Vec3s_DiffToVec3f(&sp4C, &next->p1, &elem->p1);
        Math_Vec3s_DiffToVec3f(&sp40, &next->p2, &elem->p2);

        if (Math3D_CosOut(&sp64, &sp4C, &sp34) || Math3D_CosOut(&sp58, &sp40, &sp30) ||
            Math3D_CosOut(&sp4C, &sp40, &sp2C)) {
            elem->flags &= ~(EFFECT_BLURE_ELEMENT_FLAG_1 | EFFECT_BLURE_ELEMENT_FLAG_2);
            elem->flags |= 0;
        } else if ((sp34 <= -0.5f) || (sp30 <= -0.5f) || (sp2C <= 0.7071f)) {
            elem->flags &= ~(EFFECT_BLURE_ELEMENT_FLAG_1 | EFFECT_BLURE_ELEMENT_FLAG_2);
            elem->flags |= 0;
        } else {
            elem->flags &= ~(EFFECT_BLURE_ELEMENT_FLAG_1 | EFFECT_BLURE_ELEMENT_FLAG_2);
            elem->flags |= EFFECT_BLURE_ELEMENT_FLAG_1;
        }
    }
}
