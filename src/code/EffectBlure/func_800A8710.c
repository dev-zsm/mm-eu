// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_blure.h"

void EffectBlure_AddVertex(EffectBlure* this, Vec3f* p1, Vec3f* p2) {
    EffectBlureElement* elem;
    s32 pad;

    
    if (this) {}
    if (this) {}

    if (this != NULL) {
        if (this->numElements >= ARRAY_COUNT(this->elements)) {
            return;
        }

        elem = &this->elements[this->numElements];
        elem->state = 1;

        if (!(this->flags & EFFECT_BLURE_FLAG_2)) {
            elem->p1.x = p1->x;
            elem->p1.y = p1->y;
            elem->p1.z = p1->z;
            elem->p2.x = p2->x;
            elem->p2.y = p2->y;
            elem->p2.z = p2->z;
        } else {
            Vec3f sp16C;
            Vec3f sp160;
            Vec3f sp154;
            f32 scale;
            MtxF sp110;
            MtxF spD0;
            MtxF sp90;
            MtxF sp50;
            Vec3f sp44;
            Vec3f sp38;
            EffectBlureElement* prev = elem - 1;

            sp16C.x = ((f32)prev->p2.x + (f32)prev->p1.x) / 2.0f;
            sp16C.y = ((f32)prev->p2.y + (f32)prev->p1.y) / 2.0f;
            sp16C.z = ((f32)prev->p2.z + (f32)prev->p1.z) / 2.0f;
            sp160.x = (p1->x + p2->x) / 2.0f;
            sp160.y = (p1->y + p2->y) / 2.0f;
            sp160.z = (p1->z + p2->z) / 2.0f;

            Math_Vec3f_Diff(&sp160, &sp16C, &sp154);
            scale = Math3D_Vec3fMagnitude(&sp154);
            if (!IS_ZERO(scale)) {
                scale = 1.0f / scale;
                Math_Vec3f_Scale(&sp154, scale);

                SkinMatrix_SetTranslate(&sp110, sp160.x, sp160.y, sp160.z);
                SkinMatrix_SetRotateAroundVec(&spD0, this->addAngle, sp154.x, sp154.y, sp154.z);
                SkinMatrix_MtxFMtxFMult(&sp110, &spD0, &sp90);
                SkinMatrix_SetTranslate(&sp110, -sp160.x, -sp160.y, -sp160.z);
                SkinMatrix_MtxFMtxFMult(&sp90, &sp110, &sp50);
                SkinMatrix_Vec3fMtxFMultXYZ(&sp50, p1, &sp38);
                SkinMatrix_Vec3fMtxFMultXYZ(&sp50, p2, &sp44);

                elem->p1.x = sp38.x;
                elem->p1.y = sp38.y;
                elem->p1.z = sp38.z;
                elem->p2.x = sp44.x;
                elem->p2.y = sp44.y;
                elem->p2.z = sp44.z;
            }
        }

        elem->timer = 1;
        this->numElements++;
    }
}
