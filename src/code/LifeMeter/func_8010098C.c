// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_lifemeter.h"

void LifeMeter_Draw(PlayState* play) {
    s32 pad[5];
    TexturePtr heartTex;
    s32 curColorSet;
    f32 offsetX;
    f32 offsetY;
    s32 i;
    f32 posY;
    f32 posX;
    f32 halfTexSize;
    f32 temp_f4;
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    InterfaceContext* interfaceCtx = &play->interfaceCtx;
    Vtx* beatingHeartVtx = interfaceCtx->beatingHeartVtx;
    s32 fractionHeartCount = gSaveContext.save.saveInfo.playerData.health % 0x10;
    s16 healthCapacity = gSaveContext.save.saveInfo.playerData.healthCapacity / 0x10;
    s16 fullHeartCount = gSaveContext.save.saveInfo.playerData.health / 0x10;
    s32 pad2;
    f32 lifesize = interfaceCtx->lifeSizeChange * 0.1f;
    u32 curCombineModeSet = 0;
    TexturePtr temp = NULL;
    s32 ddCount = gSaveContext.save.saveInfo.inventory.defenseHearts - 1;

    OPEN_DISPS(gfxCtx);

    if ((gSaveContext.save.saveInfo.playerData.health % 0x10) == 0) {
        fullHeartCount--;
    }

    offsetY = 0.0f;
    offsetX = 0.0f;
    curColorSet = -1;

    for (i = 0; i < healthCapacity; i++) {
        if ((ddCount < 0) || (ddCount < i)) {
            if (i < fullHeartCount) {
                if (curColorSet != 0) {
                    curColorSet = 0;
                    gDPPipeSync(OVERLAY_DISP++);
                    gDPSetPrimColor(OVERLAY_DISP++, 0, 0, interfaceCtx->heartsPrimR[0], interfaceCtx->heartsPrimG[0],
                                    interfaceCtx->heartsPrimB[0], interfaceCtx->healthAlpha);
                    gDPSetEnvColor(OVERLAY_DISP++, interfaceCtx->heartsEnvR[0], interfaceCtx->heartsEnvG[0],
                                   interfaceCtx->heartsEnvB[0], 255);
                }
            } else if (i == fullHeartCount) {
                if (curColorSet != 1) {
                    curColorSet = 1;
                    gDPPipeSync(OVERLAY_DISP++);
                    gDPSetPrimColor(OVERLAY_DISP++, 0, 0, interfaceCtx->beatingHeartPrim[0],
                                    interfaceCtx->beatingHeartPrim[1], interfaceCtx->beatingHeartPrim[2],
                                    interfaceCtx->healthAlpha);
                    gDPSetEnvColor(OVERLAY_DISP++, interfaceCtx->beatingHeartEnv[0], interfaceCtx->beatingHeartEnv[1],
                                   interfaceCtx->beatingHeartEnv[2], 255);
                }
            } else if (fullHeartCount < i) {
                if (curColorSet != 2) {
                    curColorSet = 2;
                    gDPPipeSync(OVERLAY_DISP++);
                    gDPSetPrimColor(OVERLAY_DISP++, 0, 0, interfaceCtx->heartsPrimR[0], interfaceCtx->heartsPrimG[0],
                                    interfaceCtx->heartsPrimB[0], interfaceCtx->healthAlpha);
                    gDPSetEnvColor(OVERLAY_DISP++, interfaceCtx->heartsEnvR[0], interfaceCtx->heartsEnvG[0],
                                   interfaceCtx->heartsEnvB[0], 255);
                }
            } else {
                if (curColorSet != 3) {
                    curColorSet = 3;
                    gDPPipeSync(OVERLAY_DISP++);
                    gDPSetPrimColor(OVERLAY_DISP++, 0, 0, interfaceCtx->heartsPrimR[1], interfaceCtx->heartsPrimG[1],
                                    interfaceCtx->heartsPrimB[1], interfaceCtx->healthAlpha);
                    gDPSetEnvColor(OVERLAY_DISP++, interfaceCtx->heartsEnvR[1], interfaceCtx->heartsEnvG[1],
                                   interfaceCtx->heartsEnvB[1], 255);
                }
            }

            if (i < fullHeartCount) {
                heartTex = gHeartFullTex;
            } else if (i == fullHeartCount) {
                heartTex = sHeartTextures[fractionHeartCount];
            } else {
                heartTex = gHeartEmptyTex;
            }
        } else {
            if (i < fullHeartCount) {
                if (curColorSet != 4) {
                    curColorSet = 4;
                    gDPPipeSync(OVERLAY_DISP++);
                    gDPSetPrimColor(OVERLAY_DISP++, 0, 0, sHeartsDDPrim[0][0], sHeartsDDPrim[0][1], sHeartsDDPrim[0][2],
                                    interfaceCtx->healthAlpha);
                    gDPSetEnvColor(OVERLAY_DISP++, sHeartsDDEnv[0][0], sHeartsDDEnv[0][1], sHeartsDDEnv[0][2], 255);
                }
            } else if (i == fullHeartCount) {
                if (curColorSet != 5) {
                    curColorSet = 5;
                    gDPPipeSync(OVERLAY_DISP++);
                    gDPSetPrimColor(OVERLAY_DISP++, 0, 0, sBeatingHeartsDDPrim[0], sBeatingHeartsDDPrim[1],
                                    sBeatingHeartsDDPrim[2], interfaceCtx->healthAlpha);
                    gDPSetEnvColor(OVERLAY_DISP++, sBeatingHeartsDDEnv[0], sBeatingHeartsDDEnv[1],
                                   sBeatingHeartsDDEnv[2], 255);
                }
            } else if (i > fullHeartCount) {
                if (curColorSet != 6) {
                    curColorSet = 6;
                    gDPPipeSync(OVERLAY_DISP++);
                    gDPSetPrimColor(OVERLAY_DISP++, 0, 0, sHeartsDDPrim[0][0], sHeartsDDPrim[0][1], sHeartsDDPrim[0][2],
                                    interfaceCtx->healthAlpha);
                    gDPSetEnvColor(OVERLAY_DISP++, sHeartsDDEnv[0][0], sHeartsDDEnv[0][1], sHeartsDDEnv[0][2], 255);
                }
            } else if (curColorSet != 7) {
                curColorSet = 7;
                gDPPipeSync(OVERLAY_DISP++);
                gDPSetPrimColor(OVERLAY_DISP++, 0, 0, sHeartsDDPrim[1][0], sHeartsDDPrim[1][1], sHeartsDDPrim[1][2],
                                interfaceCtx->healthAlpha);
                gDPSetEnvColor(OVERLAY_DISP++, sHeartsDDEnv[1][0], sHeartsDDEnv[1][1], sHeartsDDEnv[1][2], 255);
            }
            if (i < fullHeartCount) {
                heartTex = gDefenseHeartFullTex;
            } else if (i == fullHeartCount) {
                heartTex = sHeartDDTextures[fractionHeartCount];
            } else {
                heartTex = gDefenseHeartEmptyTex;
            }
        }

        if (temp != heartTex) {
            temp = heartTex;
            gDPLoadTextureBlock(OVERLAY_DISP++, heartTex, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 16, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
        }

        if (i != fullHeartCount) {
            if ((ddCount < 0) || (i > ddCount)) {
                if (curCombineModeSet != 1) {
                    curCombineModeSet = 1;
                    Gfx_SetupDL39_Overlay(gfxCtx);
                    gDPSetCombineLERP(OVERLAY_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE,
                                      0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
                }
            } else if (curCombineModeSet != 3) {
                curCombineModeSet = 3;
                Gfx_SetupDL39_Overlay(gfxCtx);
                gDPSetCombineLERP(OVERLAY_DISP++, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0,
                                  ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
            }
            posY = 26.0f + offsetY;
            posX = 30.0f + offsetX;
            temp_f4 = 1.0f;
            temp_f4 /= 0.68f;
            temp_f4 *= 1 << 10;
            halfTexSize = 8.0f;
            halfTexSize *= 0.68f;
            gSPTextureRectangle(OVERLAY_DISP++, (s32)((posX - halfTexSize) * 4), (s32)((posY - halfTexSize) * 4),
                                (s32)((posX + halfTexSize) * 4), (s32)((posY + halfTexSize) * 4), G_TX_RENDERTILE, 0, 0,
                                (s32)temp_f4, (s32)temp_f4);
        } else {
            Mtx* mtx;

            if ((ddCount < 0) || (ddCount < i)) {
                if (curCombineModeSet != 2) {
                    curCombineModeSet = 2;
                    Gfx_SetupDL42_Overlay(gfxCtx);
                    gDPSetCombineLERP(OVERLAY_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE,
                                      0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
                    gDPSetAlphaCompare(OVERLAY_DISP++, G_AC_THRESHOLD);
                }
            } else {
                if (curCombineModeSet != 4) {
                    curCombineModeSet = 4;
                    Gfx_SetupDL42_Overlay(gfxCtx);
                    gDPSetCombineLERP(OVERLAY_DISP++, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, PRIMITIVE,
                                      0, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
                    gDPSetAlphaCompare(OVERLAY_DISP++, G_AC_THRESHOLD);
                }
            }
            mtx = GRAPH_ALLOC(gfxCtx, sizeof(Mtx));
            Mtx_SetTranslateScaleMtx(mtx, 1.0f - (0.32f * lifesize), 1.0f - (0.32f * lifesize),
                                     1.0f - (0.32f * lifesize), -130.0f + offsetX, 94.5f - offsetY, 0.0f);
            gSPMatrix(OVERLAY_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPVertex(OVERLAY_DISP++, beatingHeartVtx, 4, 0);
            gSP1Quadrangle(OVERLAY_DISP++, 0, 2, 3, 1, 0);
        }

        offsetX += 10.0f;
        if (i == 9) {
            offsetY += 10.0f;
            offsetX = 0.0f;
        }
    }
    CLOSE_DISPS(gfxCtx);
}
