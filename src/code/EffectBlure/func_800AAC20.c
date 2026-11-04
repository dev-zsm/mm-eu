// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_blure.h"

void EffectBlure_DrawSimpleVertices(GraphicsContext* gfxCtx, EffectBlure* this, Vtx* vtx) {
    Mtx* mtx;

    OPEN_DISPS(gfxCtx);

    sSetupHandlers[this->drawMode](gfxCtx, this, vtx);
    gDPPipeSync(POLY_XLU_DISP++);

    {
        Vec3f sp1B0;
        Vec3f sp1A4;
        Vec3f sp198;
        f32 alphaRatio;
        MtxF sp154;
        MtxF sp114;
        MtxF spD4;
        MtxF sp94;
        f32 scale;
        s32 i;
        s32 j;

        j = 0;

        for (i = 0; i < this->numElements - 1; i++, j += 4) {
            if (this->drawMode == EFF_BLURE_DRAW_MODE_SIMPLE_ALT_COLORS) {
                alphaRatio = (f32)this->elements[i].timer / (f32)this->elemDuration;
                gDPSetPrimColor(POLY_XLU_DISP++, 0x00, 0x80, this->altPrimColor.r, this->altPrimColor.g,
                                this->altPrimColor.b, this->altPrimColor.a * (1.0f - alphaRatio));
                gDPPipeSync(POLY_XLU_DISP++);
            }

            gSPVertex(POLY_XLU_DISP++, &vtx[j], 4, 0);
            gSP2Triangles(POLY_XLU_DISP++, 0, 1, 3, 0, 0, 3, 2, 0);

            if (!(this->flags & EFFECT_BLURE_FLAG_4)) {
                continue;
            }

            sp1B0.x = ((f32)vtx[4 * i + 0].v.ob[0] + (f32)vtx[4 * i + 1].v.ob[0]) / 2.0f;
            sp1B0.y = ((f32)vtx[4 * i + 0].v.ob[1] + (f32)vtx[4 * i + 1].v.ob[1]) / 2.0f;
            sp1B0.z = ((f32)vtx[4 * i + 0].v.ob[2] + (f32)vtx[4 * i + 1].v.ob[2]) / 2.0f;
            sp1A4.x = ((f32)vtx[4 * i + 2].v.ob[0] + (f32)vtx[4 * i + 3].v.ob[0]) / 2.0f;
            sp1A4.y = ((f32)vtx[4 * i + 2].v.ob[1] + (f32)vtx[4 * i + 3].v.ob[1]) / 2.0f;
            sp1A4.z = ((f32)vtx[4 * i + 2].v.ob[2] + (f32)vtx[4 * i + 3].v.ob[2]) / 2.0f;

            Math_Vec3f_Diff(&sp1A4, &sp1B0, &sp198);
            scale = sqrtf(SQXYZ(sp198));

            if (fabsf(scale) > 0.0005f) {
                scale = 1.0f / scale;
                Math_Vec3f_Scale(&sp198, scale);

                SkinMatrix_SetTranslate(&sp154, sp1B0.x, sp1B0.y, sp1B0.z);
                SkinMatrix_SetRotateAroundVec(&sp114, 0x3FFF, sp198.x, sp198.y, sp198.z);
                SkinMatrix_MtxFMtxFMult(&sp154, &sp114, &spD4);
                SkinMatrix_SetTranslate(&sp154, -sp1B0.x, -sp1B0.y, -sp1B0.z);
                SkinMatrix_MtxFMtxFMult(&spD4, &sp154, &sp94);

                mtx = SkinMatrix_MtxFToNewMtx(gfxCtx, &sp94);
                if (mtx == NULL) {
                    break;
                }

                gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPVertex(POLY_XLU_DISP++, &vtx[j], 4, 0);
                gSP2Triangles(POLY_XLU_DISP++, 0, 1, 3, 0, 0, 3, 2, 0);
                gSPMatrix(POLY_XLU_DISP++, &gIdentityMtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            }
        }
    }

    CLOSE_DISPS(gfxCtx);
}
