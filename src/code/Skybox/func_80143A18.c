// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_vr_box_draw.h"

void Skybox_Draw(SkyboxContext* skyboxCtx, GraphicsContext* gfxCtx, s16 skyboxId, s16 blend, f32 x, f32 y, f32 z) {
    OPEN_DISPS(gfxCtx);

    Gfx_SetupDL40_Opa(gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x0B, skyboxCtx->palette);
    gSPTexture(POLY_OPA_DISP++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);

    
    sSkyboxDrawMatrix = GRAPH_ALLOC(gfxCtx, sizeof(Mtx));
    Matrix_Translate(x, y, z, MTXMODE_NEW);
    Matrix_Scale(1.0f, 1.0f, 1.0f, MTXMODE_APPLY);
    Matrix_RotateXFApply(skyboxCtx->rot.x);
    Matrix_RotateYF(skyboxCtx->rot.y, MTXMODE_APPLY);
    Matrix_RotateZF(skyboxCtx->rot.z, MTXMODE_APPLY);
    Matrix_ToMtx(sSkyboxDrawMatrix);
    gSPMatrix(POLY_OPA_DISP++, sSkyboxDrawMatrix, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    
    gDPSetColorDither(POLY_OPA_DISP++, G_CD_MAGICSQ);
    gDPSetTextureFilter(POLY_OPA_DISP++, G_TF_BILERP);

    
    gDPLoadTLUT_pal256(POLY_OPA_DISP++, skyboxCtx->palette);
    gDPSetTextureLUT(POLY_OPA_DISP++, G_TT_RGBA16);

    
    gDPSetTextureConvert(POLY_OPA_DISP++, G_TC_FILT);

    
    gDPSetCombineLERP(POLY_OPA_DISP++, TEXEL1, TEXEL0, PRIMITIVE_ALPHA, TEXEL0, TEXEL1, TEXEL0, PRIMITIVE, TEXEL0,
                      PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, 0, 0, 0, COMBINED);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, skyboxCtx->prim.r, skyboxCtx->prim.g, skyboxCtx->prim.b, blend);
    gDPSetEnvColor(POLY_OPA_DISP++, skyboxCtx->env.r, skyboxCtx->env.g, skyboxCtx->env.b, 0);

    
    gSPDisplayList(POLY_OPA_DISP++, &skyboxCtx->dListBuf[0]); 
    gSPDisplayList(POLY_OPA_DISP++, &skyboxCtx->dListBuf[2]); 
    gSPDisplayList(POLY_OPA_DISP++, &skyboxCtx->dListBuf[4]); 
    gSPDisplayList(POLY_OPA_DISP++, &skyboxCtx->dListBuf[6]); 
    gSPDisplayList(POLY_OPA_DISP++, &skyboxCtx->dListBuf[8]); 

    if (skyboxId == SKYBOX_CUTSCENE_MAP) {
        
        gSPDisplayList(POLY_OPA_DISP++, &skyboxCtx->dListBuf[10]); 
    }

    gDPPipeSync(POLY_OPA_DISP++);

    CLOSE_DISPS(gfxCtx);
}
