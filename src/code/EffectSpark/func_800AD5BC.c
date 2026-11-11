// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_spark.h"

void EffectSpark_Draw(void* thisx, GraphicsContext* gfxCtx) {
    Vtx* vtx;
    EffectSpark* this = (EffectSpark*)thisx;
    PlayState* play = Effect_GetPlayState();
    s32 i;
    s32 j;
    u8 sp1D3;
    u8 sp1D2;
    u8 sp1D1;
    u8 sp1D0;
    u8 sp1CF;
    u8 sp1CE;
    u8 sp1CD;
    u8 sp1CC;
    u8 sp1CB;
    u8 sp1CA;
    u8 sp1C9;
    u8 sp1C8;
    u8 sp1C7;
    u8 sp1C6;
    u8 sp1C5;
    u8 sp1C4;
    f32 ratio;

    OPEN_DISPS(gfxCtx);

    if (this != NULL) {
        gSPMatrix(POLY_XLU_DISP++, &gIdentityMtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        POLY_XLU_DISP = Gfx_SetupDL(POLY_XLU_DISP, SETUPDL_38);
        gDPSetCycleType(POLY_XLU_DISP++, G_CYC_2CYCLE);
        gDPPipeSync(POLY_XLU_DISP++);

        gSPTexture(POLY_XLU_DISP++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
        gDPLoadTextureBlock(POLY_XLU_DISP++, gameplay_keep_Tex_054F20, G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

        gDPSetCombineMode(POLY_XLU_DISP++, G_CC_SHADEDECALA, G_CC_PASS2);
        gDPSetRenderMode(POLY_XLU_DISP++, G_RM_PASS, G_RM_ZB_CLD_SURF2);
        gSPClearGeometryMode(POLY_XLU_DISP++, G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
        gSPSetGeometryMode(POLY_XLU_DISP++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
        gDPPipeSync(POLY_XLU_DISP++);

        vtx = GRAPH_ALLOC(gfxCtx, this->numElements * (4 * sizeof(Vtx)));
        if (vtx == NULL) {
            goto end;
        }

        j = 0;

        ratio = (f32)this->timer / (f32)this->duration;
        sp1D3 = F32_LERPIMP(this->colorStart[0].r, this->colorEnd[0].r, ratio);
        sp1D2 = F32_LERPIMP(this->colorStart[0].g, this->colorEnd[0].g, ratio);
        sp1D1 = F32_LERPIMP(this->colorStart[0].b, this->colorEnd[0].b, ratio);
        sp1D0 = F32_LERPIMP(this->colorStart[0].a, this->colorEnd[0].a, ratio);
        sp1CF = F32_LERPIMP(this->colorStart[1].r, this->colorEnd[1].r, ratio);
        sp1CE = F32_LERPIMP(this->colorStart[1].g, this->colorEnd[1].g, ratio);
        sp1CD = F32_LERPIMP(this->colorStart[1].b, this->colorEnd[1].b, ratio);
        sp1CC = F32_LERPIMP(this->colorStart[1].a, this->colorEnd[1].a, ratio);
        sp1CB = F32_LERPIMP(this->colorStart[2].r, this->colorEnd[2].r, ratio);
        sp1CA = F32_LERPIMP(this->colorStart[2].g, this->colorEnd[2].g, ratio);
        sp1C9 = F32_LERPIMP(this->colorStart[2].b, this->colorEnd[2].b, ratio);
        sp1C8 = F32_LERPIMP(this->colorStart[2].a, this->colorEnd[2].a, ratio);
        sp1C7 = F32_LERPIMP(this->colorStart[3].r, this->colorEnd[3].r, ratio);
        sp1C6 = F32_LERPIMP(this->colorStart[3].g, this->colorEnd[3].g, ratio);
        sp1C5 = F32_LERPIMP(this->colorStart[3].b, this->colorEnd[3].b, ratio);
        sp1C4 = F32_LERPIMP(this->colorStart[3].a, this->colorEnd[3].a, ratio);

        for (i = 0; i < this->numElements; i++) {
            MtxF sp12C;
            MtxF spEC;
            MtxF spAC;
            MtxF sp6C;
            EffectSparkElement* elem = &this->elements[i];
            Mtx* mtx;
            f32 temp;

            SkinMatrix_SetTranslate(&spEC, elem->position.x, elem->position.y, elem->position.z);
            temp = ((Rand_ZeroOne() * 2.5f) + 1.5f) / 64.0f;
            SkinMatrix_SetScale(&spAC, temp, temp, 1.0f);
            SkinMatrix_MtxFMtxFMult(&spEC, &play->billboardMtxF, &sp6C);
            SkinMatrix_MtxFMtxFMult(&sp6C, &spAC, &sp12C);

            vtx[j].v.ob[0] = -32;
            vtx[j].v.ob[1] = -32;
            vtx[j].v.ob[2] = 0;
            vtx[j].v.cn[0] = sp1D3;
            vtx[j].v.cn[1] = sp1D2;
            vtx[j].v.cn[2] = sp1D1;
            vtx[j].v.cn[3] = sp1D0;
            vtx[j].v.tc[0] = 0;
            vtx[j].v.tc[1] = 1024;
            vtx[j].v.flag = 0;

            vtx[j + 1].v.ob[0] = 32;
            vtx[j + 1].v.ob[1] = 32;
            vtx[j + 1].v.ob[2] = 0;
            vtx[j + 1].v.cn[0] = sp1CF;
            vtx[j + 1].v.cn[1] = sp1CE;
            vtx[j + 1].v.cn[2] = sp1CD;
            vtx[j + 1].v.cn[3] = sp1CC;
            vtx[j + 1].v.tc[0] = 1024;
            vtx[j + 1].v.tc[1] = 0;
            vtx[j + 1].v.flag = 0;

            vtx[j + 2].v.ob[0] = -32;
            vtx[j + 2].v.ob[1] = 32;
            vtx[j + 2].v.ob[2] = 0;
            vtx[j + 2].v.cn[0] = sp1CB;
            vtx[j + 2].v.cn[1] = sp1CA;
            vtx[j + 2].v.cn[2] = sp1C9;
            vtx[j + 2].v.cn[3] = sp1C8;
            vtx[j + 2].v.tc[0] = 0;
            vtx[j + 2].v.tc[1] = 0;
            vtx[j + 2].v.flag = 0;

            vtx[j + 3].v.ob[0] = 32;
            vtx[j + 3].v.ob[1] = -32;
            vtx[j + 3].v.ob[2] = 0;
            vtx[j + 3].v.cn[0] = sp1C7;
            vtx[j + 3].v.cn[1] = sp1C6;
            vtx[j + 3].v.cn[2] = sp1C5;
            vtx[j + 3].v.cn[3] = sp1C4;
            vtx[j + 3].v.tc[0] = 1024;
            vtx[j + 3].v.tc[1] = 1024;
            vtx[j + 3].v.flag = 0;

            j += 4;

            mtx = SkinMatrix_MtxFToNewMtx(gfxCtx, &sp12C);
            if (mtx == NULL) {
                goto end;
            }

            gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPVertex(POLY_XLU_DISP++, &vtx[4 * i], 4, 0);
            gSP2Triangles(POLY_XLU_DISP++, 2, 0, 3, 0, 2, 3, 1, 0);
        }

        gDPPipeSync(POLY_XLU_DISP++);
    }

end:
    CLOSE_DISPS(gfxCtx);
}
