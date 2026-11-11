// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_tire_mark.h"

void EffectTireMark_Draw(void* thisx, GraphicsContext* gfxCtx) {
    EffectTireMark* this = (EffectTireMark*)thisx;
    EffectTireMarkElement* elem;
    Vtx* vtx;
    s32 pad;
    f32 sp34;
    s32 i;

    sp34 = 1.0f / this->elemDuration;

    OPEN_DISPS(gfxCtx);

    if (this->numElements >= 2) {
        vtx = GRAPH_ALLOC(gfxCtx, this->numElements * (2 * sizeof(Vtx)));

        if (vtx != NULL) {
            gSPMatrix(POLY_OPA_DISP++, &gIdentityMtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

            POLY_OPA_DISP = Gfx_SetupDL(POLY_OPA_DISP++, SETUPDL_44);
            gDPSetRenderMode(POLY_OPA_DISP++, G_RM_PASS, G_RM_ZB_CLD_SURF2);

            gDPLoadTextureBlock(POLY_OPA_DISP++, gameplay_keep_Tex_014570, G_IM_FMT_I, G_IM_SIZ_8b, 64, 32, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_WRAP, 6, 5, G_TX_NOLOD, G_TX_NOLOD);

            gDPSetCombineLERP(POLY_OPA_DISP++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0,
                              COMBINED);
            gSPSetGeometryMode(POLY_OPA_DISP++, G_SHADE | G_SHADING_SMOOTH);
            gSPClearGeometryMode(POLY_OPA_DISP++, G_CULL_BACK | G_LIGHTING);

            EffectTireMark_SetVertices(vtx, &this->elements[0], 0, 255);

            vtx[0].v.tc[0] = 0;
            vtx[0].v.tc[1] = 0;
            vtx[1].v.tc[0] = 0;
            vtx[1].v.tc[1] = 1024;

            for (i = 1; i < this->numElements; i++) {
                elem = &this->elements[i];

                EffectTireMark_SetVertices(vtx, elem, i, 255);

                if ((elem - 1)->flags & EFFECT_TIRE_MARK_ELEMENT_FLAG_1) {
                    if (!(elem->flags & EFFECT_TIRE_MARK_ELEMENT_FLAG_1)) {
                        s32 requiredScopeTemp;

                        vtx[i * 2 + 0].v.tc[0] = 0;
                        vtx[i * 2 + 0].v.tc[1] = 0;
                        vtx[i * 2 + 1].v.tc[0] = 0;
                        vtx[i * 2 + 1].v.tc[1] = 1024;
                    } else if ((i >= 2) && !((elem - 2)->flags & EFFECT_TIRE_MARK_ELEMENT_FLAG_1)) {
                        vtx[i * 2 - 2].v.tc[0] = 0;
                        vtx[i * 2 - 2].v.tc[1] = 0;
                        vtx[i * 2 - 1].v.tc[0] = 0;
                        vtx[i * 2 - 1].v.tc[1] = 1024;
                    }

                    if (i == (this->numElements - 1)) {
                        vtx[i * 2 + 0].v.tc[0] = 0;
                        vtx[i * 2 + 0].v.tc[1] = 0;
                        vtx[i * 2 + 1].v.tc[0] = 0;
                        vtx[i * 2 + 1].v.tc[1] = 1024;
                    }

                    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, this->color.r, this->color.g, this->color.b,
                                    (s32)((f32)this->color.a * (f32)elem->life * sp34));
                    gSPVertex(POLY_OPA_DISP++, &vtx[i * 2 - 2], 4, 0);
                    gSP2Triangles(POLY_OPA_DISP++, 0, 1, 3, 0, 0, 3, 2, 0);
                }
            }
        }
    }

    CLOSE_DISPS(gfxCtx);
}
