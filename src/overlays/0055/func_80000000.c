// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kaleido_collect.h"

void KaleidoScope_DrawQuestStatus(PlayState* play) {
    static s16 sQuestRemainsColorTimer = 20;
    static s16 sQuestRemainsColorTimerIndex = 0;
    static s16 sQuestHpPrimRed = 0;
    static s16 sQuestHpPrimGreen = 0;
    static s16 sQuestHpPrimBlue = 0;
    static s16 sQuestHpPrimAlpha = 0;
    static s16 sQuestHpColorTimer = 20;
    static s16 sQuestHpPrimColorTargetIndex = 0;
    static TexturePtr sOcarinaButtonTextures[] = {
        gOcarinaATex, gOcarinaCDownTex, gOcarinaCRightTex, gOcarinaCLeftTex, gOcarinaCUpTex,
    };
    static s16 sQuestSongsPrimRed[] = {
        150, 
        255, 
        100, 
        255, 
        255, 
        255, 
        255, 
        255, 
        255, 
        255, 
        255, 
        255, 
    };
    static s16 sQuestSongsPrimGreen[] = {
        255, 
        80,  
        150, 
        160, 
        100, 
        240, 
        255, 
        255, 
        255, 
        255, 
        255, 
        255, 
    };
    static s16 sQuestSongsPrimBlue[] = {
        100, 
        40,  
        255, 
        0,   
        255, 
        100, 
        255, 
        255, 
        255, 
        255, 
        255, 
        255, 
    };
    static TexturePtr sQuestUpgradeTextures[][3] = {
        { gItemIconQuiver30Tex, gItemIconQuiver40Tex, gItemIconQuiver50Tex },    
        { gItemIconBombBag20Tex, gItemIconBombBag30Tex, gItemIconBombBag40Tex }, 
    };
    static u8 sQuestUpgrades[] = { UPG_QUIVER, UPG_BOMB_BAG };
    PauseContext* pauseCtx = &play->pauseCtx;
    s16 sp1CA; 
    s16 sp1C8; 
    s16 sp1C6;
    s16 sp1C4;
    s16 var_v1;
    s16 i;
    s16 j;
    s16 k;
    s16 skullTokenDigits[3];
    u16 isDigitDrawn;
    u32* questItemsPtr;

    OPEN_DISPS(play->state.gfxCtx);

    KaleidoScope_SetCursorVtxPos(pauseCtx, pauseCtx->cursorSlot[PAUSE_QUEST] * 4, pauseCtx->questVtx);

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->alpha);
    gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE,
                      ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);

    
    sQuestRemainsColorTimer--;
    for (i = 0, j = 0; i < 4; i++, j += 4) {
        if ((sQuestRemainsColorTimerIndex != 1) && (sQuestRemainsColorTimerIndex != 3)) {
            var_v1 = (sQuestRemainsColorTimerIndex != 0) ? (i + 6) : i;

            if (sQuestRemainsColorTimer != 0) {
                sp1CA = ABS_ALT(sQuestRemainsEnvRed[i] - sQuestRemainsEnvTargets[var_v1][0]) / sQuestRemainsColorTimer;
                sp1C8 =
                    ABS_ALT(sQuestRemainsEnvGreen[i] - sQuestRemainsEnvTargets[var_v1][1]) / sQuestRemainsColorTimer;
                sp1C6 = ABS_ALT(sQuestRemainsEnvBlue[i] - sQuestRemainsEnvTargets[var_v1][2]) / sQuestRemainsColorTimer;

                if (sQuestRemainsEnvRed[i] >= sQuestRemainsEnvTargets[var_v1][0]) {
                    sQuestRemainsEnvRed[i] -= sp1CA;
                } else {
                    sQuestRemainsEnvRed[i] += sp1CA;
                }
                if (sQuestRemainsEnvGreen[i] >= sQuestRemainsEnvTargets[var_v1][1]) {
                    sQuestRemainsEnvGreen[i] -= sp1C8;
                } else {
                    sQuestRemainsEnvGreen[i] += sp1C8;
                }
                if (sQuestRemainsEnvBlue[i] >= sQuestRemainsEnvTargets[var_v1][2]) {
                    sQuestRemainsEnvBlue[i] -= sp1C6;
                } else {
                    sQuestRemainsEnvBlue[i] += sp1C6;
                }
            } else {
                sQuestRemainsEnvRed[i] = sQuestRemainsEnvTargets[var_v1][0];
                sQuestRemainsEnvGreen[i] = sQuestRemainsEnvTargets[var_v1][1];
                sQuestRemainsEnvBlue[i] = sQuestRemainsEnvTargets[var_v1][2];
            }
        }

        if (CHECK_QUEST_ITEM(i)) {
            gDPPipeSync(POLY_OPA_DISP++);
            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->alpha);
            gDPSetEnvColor(POLY_OPA_DISP++, sQuestRemainsEnvRed[i], sQuestRemainsEnvGreen[i], sQuestRemainsEnvBlue[i],
                           0);
            gSPVertex(POLY_OPA_DISP++, &pauseCtx->questVtx[j], 4, 0);
            KaleidoScope_DrawTexQuadRGBA32(play->state.gfxCtx, gItemIcons[ITEM_REMAINS_ODOLWA + i], 32, 32, 0);
        }
    }

    if (sQuestRemainsColorTimer == 0) {
        sQuestRemainsColorTimer = sQuestRemainsColorTimerInit[sQuestRemainsColorTimerIndex];
        if (++sQuestRemainsColorTimerIndex > 3) {
            sQuestRemainsColorTimerIndex = 0;
        }
    }

    
    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->alpha);
    gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

    if (GET_CUR_EQUIP_VALUE(EQUIP_TYPE_SHIELD) != EQUIP_VALUE_SHIELD_NONE) {
        gSPVertex(POLY_OPA_DISP++, &pauseCtx->questVtx[j], 4, 0);
        KaleidoScope_DrawTexQuadRGBA32(play->state.gfxCtx, gItemIcons[(ITEM_SHIELD_HERO - 1) + GET_CUR_EQUIP_VALUE(1)],
                                       32, 32, 0);
    }

    j += 4;

    
    if (GET_CUR_EQUIP_VALUE(EQUIP_TYPE_SWORD) != EQUIP_VALUE_SWORD_NONE) {
        gSPVertex(POLY_OPA_DISP++, &pauseCtx->questVtx[j], 4, 0);
        KaleidoScope_DrawTexQuadRGBA32(play->state.gfxCtx, gItemIcons[(ITEM_SWORD_KOKIRI - 1) + GET_CUR_EQUIP_VALUE(0)],
                                       32, 32, 0);
    }

    j += 4;

    
    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->alpha);
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);

    gDPLoadTextureBlock(POLY_OPA_DISP++, gItemIconSongNoteTex, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 24, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    for (i = 0; i < 12; i++, j += 4) {
        if (CHECK_QUEST_ITEM(i + QUEST_SONG_SONATA) ||
            ((i == (QUEST_SONG_LULLABY - QUEST_SONG_SONATA)) && !CHECK_QUEST_ITEM(i + QUEST_SONG_SONATA) &&
             CHECK_QUEST_ITEM(QUEST_SONG_LULLABY_INTRO))) {
            if ((i + QUEST_SONG_SONATA) == pauseCtx->cursorSlot[PAUSE_QUEST]) {
                pauseCtx->questVtx[j + 0].v.ob[0] = pauseCtx->questVtx[j + 2].v.ob[0] =
                    pauseCtx->questVtx[j + 0].v.ob[0] - 2;

                pauseCtx->questVtx[j + 1].v.ob[0] = pauseCtx->questVtx[j + 3].v.ob[0] =
                    pauseCtx->questVtx[j + 1].v.ob[0] + 4;

                pauseCtx->questVtx[j + 0].v.ob[1] = pauseCtx->questVtx[j + 1].v.ob[1] =
                    pauseCtx->questVtx[j + 0].v.ob[1] + 2;

                pauseCtx->questVtx[j + 2].v.ob[1] = pauseCtx->questVtx[j + 3].v.ob[1] =
                    pauseCtx->questVtx[j + 2].v.ob[1] - 4;
            }

            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, sQuestSongsPrimRed[i], sQuestSongsPrimGreen[i],
                            sQuestSongsPrimBlue[i], pauseCtx->alpha);
            gSPVertex(POLY_OPA_DISP++, &pauseCtx->questVtx[j], 4, 0);
            gSP1Quadrangle(POLY_OPA_DISP++, 0, 2, 3, 1, 0);
        }
    }

    
    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->alpha);
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);

    if (CHECK_QUEST_ITEM(QUEST_BOMBERS_NOTEBOOK)) {
        gSPVertex(POLY_OPA_DISP++, &pauseCtx->questVtx[j], 4, 0);
        KaleidoScope_DrawTexQuadRGBA32(play->state.gfxCtx, gItemIconBombersNotebookTex, 32, 32, 0);
    }

    j += 4;

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->alpha);

    
    for (i = 0; i < 2; i++, j += 4) {
        gSPVertex(POLY_OPA_DISP++, &pauseCtx->questVtx[j], 4, 0);
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->alpha);

        if (GET_CUR_UPG_VALUE(sQuestUpgrades[i]) != 0) {
            KaleidoScope_DrawTexQuadRGBA32(
                play->state.gfxCtx, sQuestUpgradeTextures[i][GET_CUR_UPG_VALUE(sQuestUpgrades[i]) - 1], 32, 32, 0);
        }
    }

    
    j += 4;

    sp1CA = ABS_ALT(sQuestHpPrimRed - sQuestHpPrimColorTargets[sQuestHpPrimColorTargetIndex][0]) / sQuestHpColorTimer;
    sp1C8 = ABS_ALT(sQuestHpPrimGreen - sQuestHpPrimColorTargets[sQuestHpPrimColorTargetIndex][1]) / sQuestHpColorTimer;
    sp1C6 = ABS_ALT(sQuestHpPrimBlue - sQuestHpPrimColorTargets[sQuestHpPrimColorTargetIndex][2]) / sQuestHpColorTimer;
    sp1C4 = ABS_ALT(sQuestHpPrimAlpha - sQuestHpPrimColorTargets[sQuestHpPrimColorTargetIndex][3]) / sQuestHpColorTimer;

    if (sQuestHpPrimRed >= sQuestHpPrimColorTargets[sQuestHpPrimColorTargetIndex][0]) {
        sQuestHpPrimRed -= sp1CA;
    } else {
        sQuestHpPrimRed += sp1CA;
    }

    if (sQuestHpPrimGreen >= sQuestHpPrimColorTargets[sQuestHpPrimColorTargetIndex][1]) {
        sQuestHpPrimGreen -= sp1C8;
    } else {
        sQuestHpPrimGreen += sp1C8;
    }

    if (sQuestHpPrimBlue >= sQuestHpPrimColorTargets[sQuestHpPrimColorTargetIndex][2]) {
        sQuestHpPrimBlue -= sp1C6;
    } else {
        sQuestHpPrimBlue += sp1C6;
    }

    if (sQuestHpPrimAlpha >= sQuestHpPrimColorTargets[sQuestHpPrimColorTargetIndex][3]) {
        sQuestHpPrimAlpha -= sp1C4;
    } else {
        sQuestHpPrimAlpha += sp1C4;
    }

    sQuestHpColorTimer--;
    if (sQuestHpColorTimer == 0) {
        sQuestHpPrimRed = sQuestHpPrimColorTargets[sQuestHpPrimColorTargetIndex][0];
        sQuestHpPrimGreen = sQuestHpPrimColorTargets[sQuestHpPrimColorTargetIndex][1];
        sQuestHpPrimBlue = sQuestHpPrimColorTargets[sQuestHpPrimColorTargetIndex][2];
        sQuestHpPrimAlpha = sQuestHpPrimColorTargets[sQuestHpPrimColorTargetIndex][3];
        sQuestHpColorTimer = sQuestHpColorTimerInits[sQuestHpPrimColorTargetIndex];
        if (++sQuestHpPrimColorTargetIndex > 3) {
            sQuestHpPrimColorTargetIndex = 0;
        }
    }

    
    if ((GET_SAVE_INVENTORY_QUEST_ITEMS & 0xF0000000) != 0) {}
    questItemsPtr = &gSaveContext.save.saveInfo.inventory.questItems;
    if (1) {}

    if ((*questItemsPtr >> QUEST_HEART_PIECE_COUNT) != 0) {
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);

        if ((pauseCtx->state == PAUSE_STATE_OPENING_3) || (pauseCtx->state == PAUSE_STATE_UNPAUSE_SETUP)) {
            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, sQuestHpPrimColorTargets[0][0], sQuestHpPrimColorTargets[0][1],
                            sQuestHpPrimColorTargets[0][2], pauseCtx->alpha);
        } else {
            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, sQuestHpPrimRed, sQuestHpPrimGreen, sQuestHpPrimBlue,
                            sQuestHpPrimAlpha);
        }

        gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
        gSPVertex(POLY_OPA_DISP++, &pauseCtx->questVtx[j], 4, 0);

        POLY_OPA_DISP = Gfx_DrawTexQuadIA8(
            POLY_OPA_DISP,
            gItemIcons[(0x7A + ((GET_SAVE_INVENTORY_QUEST_ITEMS & 0xF0000000) >> QUEST_HEART_PIECE_COUNT))], 48, 48, 0);
    }

    j += 4;

    if (pauseCtx->state == PAUSE_STATE_MAIN) {
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

        if (pauseCtx->mainState == PAUSE_MAIN_STATE_SONG_PLAYBACK) {
            
            pauseCtx->ocarinaStaff = AudioOcarina_GetPlaybackStaff();

            if (pauseCtx->ocarinaStaff->pos != 0) {
                if (sQuestSongPlayedOcarinaButtonsNum == (pauseCtx->ocarinaStaff->pos - 1)) {
                    sQuestSongPlayedOcarinaButtonsNum++;
                    sQuestSongPlayedOcarinaButtons[pauseCtx->ocarinaStaff->pos - 1] =
                        pauseCtx->ocarinaStaff->buttonIndex;
                }

                for (i = 0, k = 0; i < 8; i++, k += 4, j += 4) {
                    if (sQuestSongPlayedOcarinaButtons[i] == OCARINA_BTN_INVALID) {
                        break;
                    }

                    if (sQuestSongPlayedOcarinaButtonsAlpha[i] != 255) {
                        sQuestSongPlayedOcarinaButtonsAlpha[i] += 50;
                        if (sQuestSongPlayedOcarinaButtonsAlpha[i] >= 255) {
                            sQuestSongPlayedOcarinaButtonsAlpha[i] = 255;
                        }
                    }

                    pauseCtx->questVtx[j + 0].v.ob[1] = pauseCtx->questVtx[j + 1].v.ob[1] =
                        pauseCtx->ocarinaButtonsY[sQuestSongPlayedOcarinaButtons[i]];

                    pauseCtx->questVtx[j + 2].v.ob[1] = pauseCtx->questVtx[j + 3].v.ob[1] =
                        pauseCtx->questVtx[j + 0].v.ob[1] - 12;

                    gDPPipeSync(POLY_OPA_DISP++);

                    if (sQuestSongPlayedOcarinaButtons[i] == OCARINA_BTN_A) {
                        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 80, 150, 255, sQuestSongPlayedOcarinaButtonsAlpha[i]);
                    } else {
                        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 50, sQuestSongPlayedOcarinaButtonsAlpha[i]);
                    }

                    gSPVertex(POLY_OPA_DISP++, &pauseCtx->questVtx[j], 4, 0);

                    POLY_OPA_DISP = Gfx_DrawTexQuadIA8(
                        POLY_OPA_DISP, sOcarinaButtonTextures[sQuestSongPlayedOcarinaButtons[i]], 16, 16, 0);
                }
            }
        } else if (IS_PAUSE_MAIN_STATE_SONG_PROMPT(pauseCtx) ||
                   (pauseCtx->mainState == PAUSE_MAIN_STATE_IDLE_CURSOR_ON_SONG)) {
            
            sp1C8 = pauseCtx->ocarinaSongIndex;
            sp1CA = gOcarinaSongButtons[sp1C8].numButtons;

            i = j;

            for (k = 0; k < sp1CA; k++, j += 4) {
                pauseCtx->questVtx[j + 0].v.ob[1] = pauseCtx->questVtx[j + 1].v.ob[1] =
                    pauseCtx->ocarinaButtonsY[gOcarinaSongButtons[sp1C8].buttonIndex[k]];

                pauseCtx->questVtx[j + 2].v.ob[1] = pauseCtx->questVtx[j + 3].v.ob[1] =
                    pauseCtx->questVtx[j + 0].v.ob[1] - 12;

                gDPPipeSync(POLY_OPA_DISP++);

                if (pauseCtx->mainState == PAUSE_MAIN_STATE_IDLE_CURSOR_ON_SONG) {
                    
                    if (gOcarinaSongButtons[sp1C8].buttonIndex[k] == OCARINA_BTN_A) {
                        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 80, 150, 255, 200);
                    } else {
                        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 50, 200);
                    }
                } else {
                    
                    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 150, 150, 150, 150);
                }

                gSPVertex(POLY_OPA_DISP++, &pauseCtx->questVtx[j], 4, 0);

                POLY_OPA_DISP = Gfx_DrawTexQuadIA8(
                    POLY_OPA_DISP, sOcarinaButtonTextures[gOcarinaSongButtons[sp1C8].buttonIndex[k]], 16, 16, 0);
            }

            if (pauseCtx->mainState != PAUSE_MAIN_STATE_IDLE_CURSOR_ON_SONG) {
                pauseCtx->ocarinaStaff = AudioOcarina_GetPlayingStaff();

                
                if (pauseCtx->ocarinaStaff->pos != 0) {
                    if (sQuestSongPlayedOcarinaButtonsNum == (pauseCtx->ocarinaStaff->pos - 1)) {
                        if (pauseCtx->ocarinaStaff->buttonIndex <= OCARINA_BTN_C_UP) {
                            sQuestSongPlayedOcarinaButtons[pauseCtx->ocarinaStaff->pos - 1] =
                                pauseCtx->ocarinaStaff->buttonIndex;
                            sQuestSongPlayedOcarinaButtons[pauseCtx->ocarinaStaff->pos] = OCARINA_BTN_INVALID;
                            sQuestSongPlayedOcarinaButtonsNum++;
                        }
                    }
                }

                
                j = i + 32;
                k = 0;
                for (; k < 8; k++, j += 4) {
                    if (sQuestSongPlayedOcarinaButtons[k] == OCARINA_BTN_INVALID) {
                        continue;
                    }

                    if (sQuestSongPlayedOcarinaButtonsAlpha[k] != 255) {
                        sQuestSongPlayedOcarinaButtonsAlpha[k] += 50;
                        if (sQuestSongPlayedOcarinaButtonsAlpha[k] >= 255) {
                            sQuestSongPlayedOcarinaButtonsAlpha[k] = 255;
                        }
                    }

                    pauseCtx->questVtx[j + 0].v.ob[1] = pauseCtx->questVtx[j + 1].v.ob[1] =
                        pauseCtx->ocarinaButtonsY[sQuestSongPlayedOcarinaButtons[k]];

                    pauseCtx->questVtx[j + 2].v.ob[1] = pauseCtx->questVtx[j + 3].v.ob[1] =
                        pauseCtx->questVtx[j + 0].v.ob[1] - 12;

                    gDPPipeSync(POLY_OPA_DISP++);

                    if (sQuestSongPlayedOcarinaButtons[k] == OCARINA_BTN_A) {
                        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 80, 150, 255, sQuestSongPlayedOcarinaButtonsAlpha[k]);
                    } else {
                        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 50, sQuestSongPlayedOcarinaButtonsAlpha[k]);
                    }

                    gSPVertex(POLY_OPA_DISP++, &pauseCtx->questVtx[j], 4, 0);

                    POLY_OPA_DISP = Gfx_DrawTexQuadIA8(
                        POLY_OPA_DISP, sOcarinaButtonTextures[sQuestSongPlayedOcarinaButtons[k]], 16, 16, 0);
                }

                if (pauseCtx->mainState == PAUSE_MAIN_STATE_SONG_PROMPT_INIT) {
                    for (k = 0; k < 8; k++) {
                        sQuestSongPlayedOcarinaButtons[k] = OCARINA_BTN_INVALID;
                        sQuestSongPlayedOcarinaButtonsAlpha[k] = 0;
                    }

                    sQuestSongPlayedOcarinaButtonsNum = 0;
                    AudioOcarina_SetInstrument(OCARINA_INSTRUMENT_DEFAULT);
                    AudioOcarina_StartDefault((1 << pauseCtx->ocarinaSongIndex) | 0x80000000);
                    pauseCtx->ocarinaStaff = AudioOcarina_GetPlaybackStaff();
                    pauseCtx->ocarinaStaff->pos = 0;
                    pauseCtx->ocarinaStaff->state = 0xFE;
                    pauseCtx->mainState = PAUSE_MAIN_STATE_SONG_PROMPT;
                }
            }
        }
    }

    
    
    
    if (CHECK_QUEST_ITEM(QUEST_SKULL_TOKEN) && ((play->sceneId == SCENE_KINSTA1) || (play->sceneId == SCENE_KINDAN2))) {
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetCombineLERP(POLY_OPA_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 0);

        skullTokenDigits[0] = skullTokenDigits[1] = 0;
        skullTokenDigits[2] = Inventory_GetSkullTokenCount(play->sceneId);

        while (skullTokenDigits[2] >= 100) {
            skullTokenDigits[0]++;
            skullTokenDigits[2] -= 100;
        }

        while (skullTokenDigits[2] >= 10) {
            skullTokenDigits[1]++;
            skullTokenDigits[2] -= 10;
        }

        
        gSPVertex(POLY_OPA_DISP++, &pauseCtx->questVtx[152], 24, 0);

        
        for (k = 0, i = 0; k < 2; k++) {
            if (k == 0) {
                
                gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 0, 0, 0, pauseCtx->alpha);
            } else {
                if (Inventory_GetSkullTokenCount(play->sceneId) == 100) {
                    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 200, 50, 50, pauseCtx->alpha);
                } else {
                    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->alpha);
                }
            }

            isDigitDrawn = false;
            for (j = 0; j < 3; j++, i += 4) {
                if ((j >= 2) || (skullTokenDigits[j] != 0) || isDigitDrawn) {
                    gDPLoadTextureBlock(POLY_OPA_DISP++, ((u8*)gCounterDigit0Tex + (8 * 16 * skullTokenDigits[j])),
                                        G_IM_FMT_I, G_IM_SIZ_8b, 8, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                    gSP1Quadrangle(POLY_OPA_DISP++, i, i + 2, i + 3, i + 1, 0);

                    isDigitDrawn = true;
                }
            }
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
