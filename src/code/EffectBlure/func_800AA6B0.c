// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_blure.h"

void EffectBlure_DrawSmooth(EffectBlure* this2, GraphicsContext* gfxCtx) {
    EffectBlure* this = this2;
    EffectBlureElement* elem;
    s32 i;
    MtxF spDC;
    MtxF sp9C;
    MtxF sp5C;
    Mtx* mtx;

    OPEN_DISPS(gfxCtx);

    if (this->numElements < 2) {
        
        return;
    }

    this->elements[0].flags &= ~(EFFECT_BLURE_ELEMENT_FLAG_1 | EFFECT_BLURE_ELEMENT_FLAG_2);
    this->elements[0].flags |= EFFECT_BLURE_ELEMENT_FLAG_2;

    for (elem = &this->elements[1]; elem < this->elements + this->numElements - 1; elem++) {
        EffectBlure_UpdateFlags(elem);
    }

    this->elements[this->numElements - 1].flags &= ~(EFFECT_BLURE_ELEMENT_FLAG_1 | EFFECT_BLURE_ELEMENT_FLAG_2);
    this->elements[this->numElements - 1].flags |= EFFECT_BLURE_ELEMENT_FLAG_2;

    EffectBlure_SetupSmooth(this, gfxCtx);
    SkinMatrix_SetTranslate(&spDC, this->elements[0].p2.x, this->elements[0].p2.y, this->elements[0].p2.z);
    SkinMatrix_SetScale(&sp9C, 0.1f, 0.1f, 0.1f);
    SkinMatrix_MtxFMtxFMult(&spDC, &sp9C, &sp5C);

    mtx = SkinMatrix_MtxFToNewMtx(gfxCtx, &sp5C);
    if (mtx == NULL) {
        
        return;
    }

    gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    for (i = 0, elem = &this->elements[0]; elem < this->elements + this->numElements - 1; i++, elem++) {
        if ((elem->state == 0) || ((elem + 1)->state == 0)) {
            continue;
        }
        if ((((elem->flags & (EFFECT_BLURE_ELEMENT_FLAG_1 | EFFECT_BLURE_ELEMENT_FLAG_2)) == 0) &&
             (((elem + 1)->flags & (EFFECT_BLURE_ELEMENT_FLAG_1 | EFFECT_BLURE_ELEMENT_FLAG_2)) == 0)) ||
            (((elem->flags & (EFFECT_BLURE_ELEMENT_FLAG_1 | EFFECT_BLURE_ELEMENT_FLAG_2)) ==
              EFFECT_BLURE_ELEMENT_FLAG_2) &&
             (((elem + 1)->flags & (EFFECT_BLURE_ELEMENT_FLAG_1 | EFFECT_BLURE_ELEMENT_FLAG_2)) == 0)) ||
            (((elem->flags & (EFFECT_BLURE_ELEMENT_FLAG_1 | EFFECT_BLURE_ELEMENT_FLAG_2)) == 0) &&
             (((elem + 1)->flags & (EFFECT_BLURE_ELEMENT_FLAG_1 | EFFECT_BLURE_ELEMENT_FLAG_2)) ==
              EFFECT_BLURE_ELEMENT_FLAG_2)) ||
            (((elem->flags & (EFFECT_BLURE_ELEMENT_FLAG_1 | EFFECT_BLURE_ELEMENT_FLAG_2)) ==
              EFFECT_BLURE_ELEMENT_FLAG_2) &&
             (((elem + 1)->flags & (EFFECT_BLURE_ELEMENT_FLAG_1 | EFFECT_BLURE_ELEMENT_FLAG_2)) ==
              EFFECT_BLURE_ELEMENT_FLAG_2))) {
            EffectBlure_DrawElemNoInterpolation(this, elem, i, gfxCtx);
        } else {
            EffectBlure_DrawElemHermiteInterpolation(this, elem, i, gfxCtx);
        }
    }

    CLOSE_DISPS(gfxCtx);
}
