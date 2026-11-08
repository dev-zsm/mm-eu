// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_clear_tag.h"

void EnClearTag_DrawEffects(Actor* thisx, PlayState* play) {
    u8 isMaterialApplied = false;
    s16 i;
    s16 j;
    Vec3f vec;
    WaterBox* waterBox;
    f32 ySurface;
    MtxF mtxF;
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    EnClearTag* this = (EnClearTag*)thisx;
    EnClearTagEffect* effect = this->effect;
    EnClearTagEffect* firstEffect = this->effect;

    OPEN_DISPS(gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    
    for (i = 0; i < ARRAY_COUNT(this->effect); i++, effect++) {
        if (effect->type == CLEAR_TAG_EFFECT_DEBRIS) {
            
            if (!isMaterialApplied) {
                isMaterialApplied++;
                gSPDisplayList(POLY_OPA_DISP++, gClearTagDebrisEffectMaterialDL);
            }

            
            Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
            Matrix_Scale(effect->scale, effect->scale, effect->scale, MTXMODE_APPLY);
            Matrix_RotateYF(effect->rotationY, MTXMODE_APPLY);
            Matrix_RotateXFApply(effect->rotationX);
            MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, gfxCtx);
            gSPDisplayList(POLY_OPA_DISP++, gClearTagDebrisEffectDL);
        }
    }

    
    effect = firstEffect;
    if (this->actor.floorPoly != NULL) {
        for (i = 0; i < ARRAY_COUNT(this->effect); i++, effect++) {
            if (effect->type == CLEAR_TAG_EFFECT_SHOCKWAVE) {
                
                gDPPipeSync(POLY_XLU_DISP++);
                gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, (s8)effect->primColor.a);
                gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (s8)effect->primColor.a);
                ref_func_800C0094(this->actor.floorPoly, effect->pos.x, effect->pos.y, effect->pos.z, &mtxF);
                Matrix_Put(&mtxF);
                Matrix_Scale(effect->scale, 1.0f, effect->scale, MTXMODE_APPLY);
                MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, gfxCtx);
                gSPDisplayList(POLY_XLU_DISP++, gEffShockwaveDL);
            }
        }
    }

    
    effect = firstEffect;
    isMaterialApplied = false;
    if (this->actor.floorPoly != NULL) {
        for (i = 0; i < ARRAY_COUNT(this->effect); i++, effect++) {
            if (effect->type == CLEAR_TAG_EFFECT_FLASH) {
                
                if (!isMaterialApplied) {
                    gDPPipeSync(POLY_XLU_DISP++);
                    gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 200, 0);
                    isMaterialApplied++;
                }

                
                gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 200, (s8)(effect->primColor.a * 0.7f));
                ref_func_800C0094(this->actor.floorPoly, effect->pos.x, this->actor.floorHeight, effect->pos.z, &mtxF);
                Matrix_Put(&mtxF);
                Matrix_Scale(effect->scale * 3.0f, 1.0f, effect->scale * 3.0f, MTXMODE_APPLY);
                MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, gfxCtx);
                gSPDisplayList(POLY_XLU_DISP++, gClearTagFlashEffectGroundDL);
            }
        }
    }

    
    effect = firstEffect;
    isMaterialApplied = false;
    for (i = 0; i < ARRAY_COUNT(this->effect); i++, effect++) {
        if ((effect->type == CLEAR_TAG_EFFECT_SMOKE) || (effect->type == CLEAR_TAG_EFFECT_ISOLATED_SMOKE)) {
            
            if (!isMaterialApplied) {
                gSPDisplayList(POLY_XLU_DISP++, gClearTagFireEffectMaterialDL);
                isMaterialApplied++;
            }

            
            gDPPipeSync(POLY_XLU_DISP++);
            gDPSetEnvColor(POLY_XLU_DISP++, (s8)effect->envColor.r, (s8)effect->envColor.g, (s8)effect->envColor.b,
                           128);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, (s8)effect->primColor.r, (s8)effect->primColor.g,
                            (s8)effect->primColor.b, (s8)effect->primColor.a);
            gSPSegment(POLY_XLU_DISP++, 0x08,
                       Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, -effect->actionTimer * 5, 32, 64, 1, 0, 0, 32, 32));
            Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
            Matrix_ReplaceRotation(&play->billboardMtxF);
            Matrix_Scale(effect->smokeScaleX * effect->scale, effect->smokeScaleY * effect->scale, 1.0f, MTXMODE_APPLY);
            Matrix_Translate(0.0f, 20.0f, 0.0f, MTXMODE_APPLY);
            MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, gfxCtx);
            gSPDisplayList(POLY_XLU_DISP++, gClearTagFireEffectDL);
        }
    }

    
    effect = firstEffect;
    isMaterialApplied = false;
    for (i = 0; i < ARRAY_COUNT(this->effect); i++, effect++) {
        if (effect->type == CLEAR_TAG_EFFECT_FIRE) {
            
            if (!isMaterialApplied) {
                gSPDisplayList(POLY_XLU_DISP++, gClearTagFireEffectMaterialDL);
                gDPSetEnvColor(POLY_XLU_DISP++, 255, 215, 255, 128);
                isMaterialApplied++;
            }

            
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 200, 20, 0, (s8)effect->primColor.a);
            gSPSegment(POLY_XLU_DISP++, 0x08,
                       Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, -effect->actionTimer * 15, 32, 64, 1, 0, 0, 32, 32));
            Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
            Matrix_ReplaceRotation(&play->billboardMtxF);
            Matrix_Scale(effect->scale, effect->scale, 1.0f, MTXMODE_APPLY);
            MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, gfxCtx);
            gSPDisplayList(POLY_XLU_DISP++, gClearTagFireEffectDL);
        }
    }

    
    effect = firstEffect;
    isMaterialApplied = false;
    for (i = 0; i < ARRAY_COUNT(this->effect); i++, effect++) {
        if (effect->type == CLEAR_TAG_EFFECT_FLASH) {
            
            if (!isMaterialApplied) {
                gDPPipeSync(POLY_XLU_DISP++);
                gDPSetEnvColor(POLY_XLU_DISP++, this->flashEnvColor.r, this->flashEnvColor.g, this->flashEnvColor.b, 0);
                isMaterialApplied++;
            }

            
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 200, (s8)effect->primColor.a);
            Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
            Matrix_ReplaceRotation(&play->billboardMtxF);
            Matrix_Scale(2.0f * effect->scale, 2.0f * effect->scale, 1.0f, MTXMODE_APPLY);
            MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, gfxCtx);
            gSPDisplayList(POLY_XLU_DISP++, gClearTagFlashEffectDL);
        }
    }

    
    effect = firstEffect;
    isMaterialApplied = false;
    for (i = 0; i < ARRAY_COUNT(this->effect); i++, effect++) {
        if (effect->type == CLEAR_TAG_EFFECT_LIGHT_RAYS) {
            
            if (!isMaterialApplied) {
                gDPPipeSync(POLY_XLU_DISP++);
                gDPSetEnvColor(POLY_XLU_DISP++, (u8)effect->envColor.r, (u8)effect->envColor.g, (u8)effect->envColor.b,
                               0);
                gSPDisplayList(POLY_XLU_DISP++, gClearTagLightRayEffectMaterialDL);
                isMaterialApplied++;
            }

            
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, (u8)effect->primColor.r, (u8)effect->primColor.g,
                            (u8)effect->primColor.b, (u8)effect->primColor.a);
            Matrix_Translate(effect->pos.x, effect->pos.y, effect->pos.z, MTXMODE_NEW);
            Matrix_RotateYF(effect->rotationY, MTXMODE_APPLY);
            Matrix_RotateXFApply(effect->rotationX);
            Matrix_RotateZF(effect->rotationZ, MTXMODE_APPLY);
            Matrix_Scale(effect->scale * 0.5f, effect->scale * 0.5f, effect->maxScale * effect->scale, MTXMODE_APPLY);
            Matrix_RotateXFApply(M_PIf / 2);
            MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, gfxCtx);
            gSPDisplayList(POLY_XLU_DISP++, gClearTagLightRayEffectDL);
        }
    }

    
    effect = firstEffect;
    for (i = 0; i < ARRAY_COUNT(this->effect); i++, effect++) {
        if (effect->type == CLEAR_TAG_EFFECT_SPLASH) {
            gDPPipeSync(POLY_XLU_DISP++);
            gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, 255, 200);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, 200);
            gSPSegment(POLY_XLU_DISP++, 0x08, Lib_SegmentedToVirtual(sWaterSplashTextures[effect->actionTimer]));
            Gfx_SetupDL61_Xlu(gfxCtx);
            gSPClearGeometryMode(POLY_XLU_DISP++, G_CULL_BACK);
            isMaterialApplied++;

            
            for (j = 0; j < 16; j++) {
                Matrix_RotateYF(2.0f * (j * M_PIf) * (1.0f / 16.0f), MTXMODE_NEW);
                Matrix_MultVecZ(effect->maxScale, &vec);
                 
                ySurface = effect->pos.y;
                if (BgCheck_GetWaterSurfaceNoBgIdAlt(play, &play->colCtx, effect->pos.x + vec.x, effect->pos.z + vec.z,
                                                     &ySurface, &waterBox)) {
                    if ((effect->pos.y - ySurface) < 200.0f) {
                        
                        Matrix_Translate(effect->pos.x + vec.x, ySurface, effect->pos.z + vec.z, MTXMODE_NEW);
                        Matrix_RotateYF(2.0f * (j * M_PIf) * (1.0f / 16.0f), MTXMODE_APPLY);
                        Matrix_RotateXFApply(effect->rotationX);
                        Matrix_Scale(effect->scale, effect->scale, effect->scale, MTXMODE_APPLY);
                        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, gfxCtx);
                        gSPDisplayList(POLY_XLU_DISP++, gEffWaterSplashDL);
                    }
                }
            }
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
