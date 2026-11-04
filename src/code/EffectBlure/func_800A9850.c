// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_blure.h"

void EffectBlure_DrawElemNoInterpolation(EffectBlure* this, EffectBlureElement* elem, s32 index,
                                         GraphicsContext* gfxCtx) {
    static Vtx_t sBaseVtx = VTX_T(0, 0, 0, 0, 0, 255, 255, 255, 255);
    Vtx* vtx;
    Vec3s sp8C;
    Vec3s sp84;
    f32 ratio;
    Color_RGBA8 sp7C;
    Color_RGBA8 sp78;
    Vec3f sp6C;
    Vec3f sp60;
    Vec3f sp54;

    OPEN_DISPS(gfxCtx);

    Math_Vec3s_ToVec3f(&sp6C, &this->elements[0].p2);

    vtx = GRAPH_ALLOC(gfxCtx, 4 * sizeof(Vtx));
    if (vtx == NULL) {
    } else {
        vtx[0].v = sBaseVtx;
        vtx[1].v = sBaseVtx;
        vtx[2].v = sBaseVtx;
        vtx[3].v = sBaseVtx;

        ratio = (f32)elem->timer / (f32)this->elemDuration;
        EffectBlure_GetComputedValues(this, index, ratio, &sp8C, &sp84, &sp7C, &sp78);

        sp60.x = sp84.x;
        sp60.y = sp84.y;
        sp60.z = sp84.z;
        Math_Vec3f_Diff(&sp60, &sp6C, &sp54);
        Math_Vec3f_Scale(&sp54, 10.0f);
        vtx[0].v.ob[0] = sp54.x;
        vtx[0].v.ob[1] = sp54.y;
        vtx[0].v.ob[2] = sp54.z;
        vtx[0].v.cn[0] = sp78.r;
        vtx[0].v.cn[1] = sp78.g;
        vtx[0].v.cn[2] = sp78.b;
        vtx[0].v.cn[3] = sp78.a;

        sp60.x = sp8C.x;
        sp60.y = sp8C.y;
        sp60.z = sp8C.z;
        Math_Vec3f_Diff(&sp60, &sp6C, &sp54);
        Math_Vec3f_Scale(&sp54, 10.0f);
        vtx[1].v.ob[0] = sp54.x;
        vtx[1].v.ob[1] = sp54.y;
        vtx[1].v.ob[2] = sp54.z;
        vtx[1].v.cn[0] = sp7C.r;
        vtx[1].v.cn[1] = sp7C.g;
        vtx[1].v.cn[2] = sp7C.b;
        vtx[1].v.cn[3] = sp7C.a;

        ratio = (f32)(elem + 1)->timer / (f32)this->elemDuration;
        EffectBlure_GetComputedValues(this, index + 1, ratio, &sp8C, &sp84, &sp7C, &sp78);

        sp60.x = sp8C.x;
        sp60.y = sp8C.y;
        sp60.z = sp8C.z;
        Math_Vec3f_Diff(&sp60, &sp6C, &sp54);
        Math_Vec3f_Scale(&sp54, 10.0f);
        vtx[2].v.ob[0] = sp54.x;
        vtx[2].v.ob[1] = sp54.y;
        vtx[2].v.ob[2] = sp54.z;
        vtx[2].v.cn[0] = sp7C.r;
        vtx[2].v.cn[1] = sp7C.g;
        vtx[2].v.cn[2] = sp7C.b;
        vtx[2].v.cn[3] = sp7C.a;

        sp60.x = sp84.x;
        sp60.y = sp84.y;
        sp60.z = sp84.z;
        Math_Vec3f_Diff(&sp60, &sp6C, &sp54);
        Math_Vec3f_Scale(&sp54, 10.0f);
        vtx[3].v.ob[0] = sp54.x;
        vtx[3].v.ob[1] = sp54.y;
        vtx[3].v.ob[2] = sp54.z;
        vtx[3].v.cn[0] = sp78.r;
        vtx[3].v.cn[1] = sp78.g;
        vtx[3].v.cn[2] = sp78.b;
        vtx[3].v.cn[3] = sp78.a;

        gSPVertex(POLY_XLU_DISP++, vtx, 4, 0);
        gSP2Triangles(POLY_XLU_DISP++, 0, 1, 2, 0, 0, 2, 3, 0);
    }

    CLOSE_DISPS(gfxCtx);
}
