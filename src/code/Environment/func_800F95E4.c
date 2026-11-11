// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

void Environment_DrawLensFlare(PlayState* play, EnvironmentContext* envCtx, View* view, GraphicsContext* gfxCtx,
                               Vec3f pos, f32 scale, f32 colorIntensity, s16 glareStrength, u8 isSun) {
    s16 i;
    f32 tempX;
    f32 tempY;
    f32 tempZ;
    f32 lookDirX;
    f32 lookDirY;
    f32 lookDirZ;
    f32 tempX2;
    f32 tempY2;
    f32 tempZ2;
    f32 posDirX;
    f32 posDirY;
    f32 posDirZ;
    f32 length;
    f32 dist;
    f32 halfPosX;
    f32 halfPosY;
    f32 halfPosZ;
    f32 cosAngle;
    s32 pad;
    f32 lensFlareAlphaScaleTarget;
    f32 alpha;
    f32 adjScale;
    f32 fogInfluence;
    Vec3f screenPos;
    u8 isOffScreen = false;
    f32 weight = 0.0f;
    f32 glareAlphaScale;
    Mtx* mtx;

    OPEN_DISPS(gfxCtx);

    dist = Math3D_Vec3f_DistXYZ(&pos, &view->eye) / 12.0f;

    
    tempX = view->at.x - view->eye.x;
    tempY = view->at.y - view->eye.y;
    tempZ = view->at.z - view->eye.z;

    length = sqrtf(SQ(tempX) + SQ(tempY) + SQ(tempZ));

    lookDirX = tempX / length;
    lookDirY = tempY / length;
    lookDirZ = tempZ / length;

    
    halfPosX = view->eye.x + lookDirX * (dist * 6.0f);
    halfPosY = view->eye.y + lookDirY * (dist * 6.0f);
    halfPosZ = view->eye.z + lookDirZ * (dist * 6.0f);

    
    tempX2 = pos.x - halfPosX;
    tempY2 = pos.y - halfPosY;
    tempZ2 = pos.z - halfPosZ;

    length = sqrtf(SQ(tempX2) + SQ(tempY2) + SQ(tempZ2));

    posDirX = tempX2 / length;
    posDirY = tempY2 / length;
    posDirZ = tempZ2 / length;

    
    cosAngle = (lookDirX * posDirX + lookDirY * posDirY + lookDirZ * posDirZ) /
               sqrtf((SQ(lookDirX) + SQ(lookDirY) + SQ(lookDirZ)) * (SQ(posDirX) + SQ(posDirY) + SQ(posDirZ)));

    lensFlareAlphaScaleTarget = cosAngle * 3.5f;
    lensFlareAlphaScaleTarget = CLAMP_MAX(lensFlareAlphaScaleTarget, 1.0f);

    if (!isSun) {
        lensFlareAlphaScaleTarget = cosAngle;
    }

    if (cosAngle < 0.0f) {
        
    } else {
        if (isSun) {
            Play_GetScreenPos(play, &pos, &screenPos);
            sSunDepthTestX = screenPos.x;
            sSunDepthTestY = screenPos.y - 5.0f;
            if (sSunDepthTestY < 0) {
                sSunDepthTestY = 0;
            }
            if ((sSunScreenDepth != GPACK_ZDZ(G_MAXFBZ, 0)) || (screenPos.x < 0.0f) || (screenPos.y < 0.0f) ||
                (screenPos.x > SCREEN_WIDTH) || (screenPos.y > SCREEN_HEIGHT)) {
                isOffScreen = true;
            }
        }

        for (i = 0; i < ARRAY_COUNT(sLensFlareTypes); i++) {
            Matrix_Translate(pos.x, pos.y, pos.z, MTXMODE_NEW);

            if (isSun) {
                weight = Environment_LerpWeight(60, 15, play->view.fovy);
            }

            Matrix_Translate(-posDirX * i * dist, -posDirY * i * dist, -posDirZ * i * dist, MTXMODE_APPLY);
            adjScale = sLensFlareScales[i] * cosAngle;

            if (isSun) {
                adjScale *= 0.001f * (scale + 630.0f * weight);
            } else {
                adjScale *= 0.0001f * scale * (2.0f * dist);
            }

            Matrix_Scale(adjScale, adjScale, adjScale, MTXMODE_APPLY);

            alpha = colorIntensity / 10.0f;
            alpha = CLAMP_MAX(alpha, 1.0f);
            alpha = alpha * sLensFlareAlphas[i];
            alpha = CLAMP_MIN(alpha, 0.0f);

            if (isSun) {
                fogInfluence = (ENV_FOGNEAR_MAX - play->lightCtx.fogNear) / 50.0f;

                fogInfluence = CLAMP_MAX(fogInfluence, 1.0f);

                alpha *= 1.0f - fogInfluence;
            }

            if (isOffScreen == false) {
                Math_SmoothStepToF(&envCtx->lensFlareAlphaScale, lensFlareAlphaScaleTarget, 0.5f, 0.05f, 0.001f);
            } else {
                Math_SmoothStepToF(&envCtx->lensFlareAlphaScale, 0.0f, 0.5f, 0.05f, 0.001f);
            }

            POLY_XLU_DISP = Gfx_SetupDL65_NoCD(POLY_XLU_DISP++);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, sLensFlareColors[i].r, sLensFlareColors[i].g, sLensFlareColors[i].b,
                            alpha * envCtx->lensFlareAlphaScale);
            mtx = Matrix_Finalize(gfxCtx);
            if (mtx != NULL) {
                gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gDPSetCombineLERP(POLY_XLU_DISP++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE,
                                  TEXEL0, 0, PRIMITIVE, 0);
                gDPSetAlphaDither(POLY_XLU_DISP++, G_AD_DISABLE);
                gDPSetColorDither(POLY_XLU_DISP++, G_CD_DISABLE);
                gSPMatrix(POLY_XLU_DISP++, &ref_D_01000000, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                switch (sLensFlareTypes[i]) {
                    case LENS_FLARE_CIRCLE0:
                    case LENS_FLARE_CIRCLE1:
                        gSPDisplayList(POLY_XLU_DISP++, gLensFlareCircleDL);
                        break;

                    case LENS_FLARE_RING:
                        gSPDisplayList(POLY_XLU_DISP++, gLensFlareRingDL);
                        break;

                    default:
                        break;
                }
            }
        }

        glareAlphaScale = cosAngle - (1.5f - cosAngle);

        if (glareStrength != 0) {
            if (glareAlphaScale > 0.0f) {
                POLY_XLU_DISP = Gfx_SetupDL57(POLY_XLU_DISP);
                alpha = colorIntensity / 10.0f;
                alpha = CLAMP_MAX(alpha, 1.0f);
                alpha = alpha * glareStrength;
                alpha = CLAMP_MIN(alpha, 0.0f);

                fogInfluence = (ENV_FOGNEAR_MAX - play->lightCtx.fogNear) / 50.0f;

                fogInfluence = CLAMP_MAX(fogInfluence, 1.0f);

                alpha *= 1.0f - fogInfluence;

                gDPSetAlphaDither(POLY_XLU_DISP++, G_AD_DISABLE);
                gDPSetColorDither(POLY_XLU_DISP++, G_CD_DISABLE);

                
                if (i) {}

                if (isOffScreen == false) {
                    Math_SmoothStepToF(&envCtx->glareAlpha, alpha * glareAlphaScale, 0.5f, 50.0f, 0.1f);
                } else {
                    Math_SmoothStepToF(&envCtx->glareAlpha, 0.0f, 0.5f, 50.0f, 0.1f);
                }

                weight = colorIntensity / 120.0f;
                weight = CLAMP_MIN(weight, 0.0f);

                gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, (u8)(weight * 75.0f) + 180, (u8)(weight * 155.0f) + 100,
                                (u8)envCtx->glareAlpha);
                gSPDisplayList(POLY_XLU_DISP++, ref_D_0E000000.clearFillRect);
            } else {
                envCtx->glareAlpha = 0.0f;
            }
        }
    }

    CLOSE_DISPS(gfxCtx);
}
