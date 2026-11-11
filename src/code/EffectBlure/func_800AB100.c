// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_blure.h"

void EffectBlure_DrawSimple(EffectBlure* this2, GraphicsContext* gfxCtx) {
    EffectBlure* this = this2;
    Vtx* vtx;
    Vtx* vtxIter;
    EffectBlureElement* elem;
    s32 vtxCount;
    s32 i;
    s32 j;
    Vec3s sp74;
    Vec3s sp6C;
    f32 ratio;
    Color_RGBA8 sp64;
    Color_RGBA8 sp60;

    if (this->numElements >= 2) {
        vtxCount = this->numElements * ARRAY_COUNT(ref_D_801AE26C);

        vtx = GRAPH_ALLOC(gfxCtx, vtxCount * sizeof(Vtx));
        if (vtx == NULL) {
            return;
        }

        vtxIter = vtx;
        for (i = 0; i < ARRAY_COUNT(ref_D_801AE26C); i++) {
            vtxIter->v = ref_D_801AE26C[i];
            vtxIter++;
        }

        if (this->numElements >= 2) {
            for (elem = this->elements; elem < this->elements + this->numElements - 2; elem++) {
                for (i = 0; i < ARRAY_COUNT(ref_D_801AE2AC); i++) {
                    vtxIter->v = ref_D_801AE2AC[i];
                    vtxIter++;
                }
            }
        }

        for (i = 0; i < this->numElements; i++) {
            elem = &this->elements[i];

            ratio = (f32)elem->timer / (f32)this->elemDuration;
            EffectBlure_GetComputedValues(this, i, ratio, &sp74, &sp6C, &sp64, &sp60);

            j = i * 4 - 2;
            if (j >= 0) {
                vtx[j].v.ob[0] = sp74.x;
                vtx[j].v.ob[1] = sp74.y;
                vtx[j].v.ob[2] = sp74.z;
                vtx[j].v.cn[0] = sp64.r;
                vtx[j].v.cn[1] = sp64.g;
                vtx[j].v.cn[2] = sp64.b;
                vtx[j].v.cn[3] = sp64.a;
            }

            j++;
            if (j >= 0) {
                vtx[j].v.ob[0] = sp6C.x;
                vtx[j].v.ob[1] = sp6C.y;
                vtx[j].v.ob[2] = sp6C.z;
                vtx[j].v.cn[0] = sp60.r;
                vtx[j].v.cn[1] = sp60.g;
                vtx[j].v.cn[2] = sp60.b;
                vtx[j].v.cn[3] = sp60.a;
            }

            j++;
            if (vtxCount >= j) {
                vtx[j].v.ob[0] = sp74.x;
                vtx[j].v.ob[1] = sp74.y;
                vtx[j].v.ob[2] = sp74.z;
                vtx[j].v.cn[0] = sp64.r;
                vtx[j].v.cn[1] = sp64.g;
                vtx[j].v.cn[2] = sp64.b;
                vtx[j].v.cn[3] = sp64.a;
            }

            j++;
            if (vtxCount >= j) {
                vtx[j].v.ob[0] = sp6C.x;
                vtx[j].v.ob[1] = sp6C.y;
                vtx[j].v.ob[2] = sp6C.z;
                vtx[j].v.cn[0] = sp60.r;
                vtx[j].v.cn[1] = sp60.g;
                vtx[j].v.cn[2] = sp60.b;
                vtx[j].v.cn[3] = sp60.a;
            }
        }

        EffectBlure_DrawSimpleVertices(gfxCtx, this, vtx);
    }
}
