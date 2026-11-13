// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (KaleidoScope_UpdateQuestCursor), score 6.00 (6 differ, size +2)
#include "generated/mm/z_kaleido_collect.h"

void func_80001ABC(PlayState* play) {
    static s16 sQuestSongPlaybackDelayTimer = 0;
    static CursorPointDirection sCursorPointLinks[] = {
        { CURSOR_NONE, QUEST_REMAINS_TWINMOLD, QUEST_REMAINS_GYORG, QUEST_REMAINS_GOHT },     
        { QUEST_REMAINS_ODOLWA, QUEST_SHIELD, QUEST_REMAINS_TWINMOLD, CURSOR_TO_RIGHT },      
        { QUEST_REMAINS_ODOLWA, QUEST_SWORD, QUEST_HEART_PIECE, QUEST_REMAINS_TWINMOLD },     
        { QUEST_REMAINS_ODOLWA, QUEST_SHIELD, QUEST_REMAINS_GYORG, QUEST_REMAINS_GOHT },      
        { QUEST_REMAINS_GOHT, QUEST_BOMB_BAG, QUEST_SWORD, CURSOR_TO_RIGHT },                 
        { QUEST_REMAINS_GYORG, QUEST_QUIVER, QUEST_SONG_STORMS, QUEST_SHIELD },               
        { QUEST_SONG_TIME, CURSOR_NONE, CURSOR_TO_LEFT, QUEST_SONG_LULLABY },                 
        { QUEST_SONG_HEALING, CURSOR_NONE, QUEST_SONG_SONATA, QUEST_SONG_BOSSA_NOVA },        
        { QUEST_SONG_EPONA, CURSOR_NONE, QUEST_SONG_LULLABY, QUEST_SONG_ELEGY },              
        { QUEST_SONG_SOARING, CURSOR_NONE, QUEST_SONG_BOSSA_NOVA, QUEST_SONG_OATH },          
        { QUEST_SONG_STORMS, CURSOR_NONE, QUEST_SONG_ELEGY, QUEST_QUIVER },                   
        { QUEST_SONG_SUN, CURSOR_NONE, QUEST_SONG_OATH, QUEST_SWORD },                        
        { QUEST_BOMBERS_NOTEBOOK, QUEST_SONG_SONATA, CURSOR_TO_LEFT, QUEST_SONG_HEALING },    
        { QUEST_BOMBERS_NOTEBOOK, QUEST_SONG_LULLABY, QUEST_SONG_TIME, QUEST_SONG_EPONA },    
        { QUEST_HEART_PIECE, QUEST_SONG_BOSSA_NOVA, QUEST_SONG_HEALING, QUEST_SONG_SOARING }, 
        { QUEST_HEART_PIECE, QUEST_SONG_ELEGY, QUEST_SONG_EPONA, QUEST_SONG_STORMS },         
        { QUEST_HEART_PIECE, QUEST_SONG_OATH, QUEST_SONG_SOARING, QUEST_SWORD },              
        { QUEST_HEART_PIECE, QUEST_SONG_SARIA, QUEST_SONG_STORMS, QUEST_SWORD },              
        { CURSOR_NONE, QUEST_SONG_TIME, CURSOR_TO_LEFT, QUEST_HEART_PIECE },                  
        { QUEST_SWORD, CURSOR_NONE, QUEST_SONG_OATH, QUEST_BOMB_BAG },                        
        { QUEST_SHIELD, CURSOR_NONE, QUEST_QUIVER, CURSOR_TO_RIGHT },                         
        { QUEST_QUIVER, QUEST_SONG_TIME, CURSOR_TO_LEFT, QUEST_HEART_PIECE },                 
        { CURSOR_NONE, QUEST_SONG_STORMS, QUEST_BOMBERS_NOTEBOOK, QUEST_REMAINS_GYORG },      
    };
    PauseContext* pauseCtx = &play->pauseCtx;
    MessageContext* msgCtx = &play->msgCtx;
    InterfaceContext* interfaceCtx = &play->interfaceCtx;
    s32 pad;
    s16 nextCursorPoint;
    s16 oldCursorPoint;
    s16 i;
    u16 cursor;
    u16 cursorItem;

    pauseCtx->nameColorSet = PAUSE_NAME_COLOR_SET_WHITE;
    pauseCtx->cursorColorSet = PAUSE_CURSOR_COLOR_SET_WHITE;

    
    if ((pauseCtx->state == PAUSE_STATE_MAIN) &&
        (!pauseCtx->mainState || (pauseCtx->mainState == PAUSE_MAIN_STATE_SONG_PROMPT) ||
         (pauseCtx->mainState == PAUSE_MAIN_STATE_IDLE_CURSOR_ON_SONG)) &&
        (pauseCtx->pageIndex == PAUSE_QUEST) && !pauseCtx->itemDescriptionOn) {
        if (pauseCtx->cursorSpecialPos == 0) {
            oldCursorPoint = pauseCtx->cursorPoint[PAUSE_QUEST];

            if (pauseCtx->stickAdjX < -30) {
                
                if (pauseCtx->mainState == PAUSE_MAIN_STATE_SONG_PROMPT) {
                    AudioOcarina_SetInstrument(OCARINA_INSTRUMENT_OFF);
                }
                pauseCtx->cursorShrinkRate = 4.0f;

                nextCursorPoint = sCursorPointLinks[oldCursorPoint].left;
                if (nextCursorPoint == CURSOR_TO_LEFT) {
                    KaleidoScope_MoveCursorToSpecialPos(play, PAUSE_CURSOR_PAGE_LEFT);
                    pauseCtx->mainState = PAUSE_MAIN_STATE_IDLE;
                    if (interfaceCtx->aButtonDoActionDelayed == DO_ACTION_DECIDE) {
                        Interface_SetAButtonDoAction(play, DO_ACTION_INFO);
                    }
                    return;
                } else {
                    while (nextCursorPoint > CURSOR_NONE) {
                        if (KaleidoScope_UpdateQuestStatusPoint(pauseCtx, nextCursorPoint)) {
                            break;
                        }
                        nextCursorPoint = sCursorPointLinks[nextCursorPoint].left;
                    }
                }
            } else if (pauseCtx->stickAdjX > 30) {
                
                if (pauseCtx->mainState == PAUSE_MAIN_STATE_SONG_PROMPT) {
                    AudioOcarina_SetInstrument(OCARINA_INSTRUMENT_OFF);
                }
                pauseCtx->cursorShrinkRate = 4.0f;
                nextCursorPoint = sCursorPointLinks[oldCursorPoint].right;

                if (nextCursorPoint == CURSOR_TO_RIGHT) {
                    KaleidoScope_MoveCursorToSpecialPos(play, PAUSE_CURSOR_PAGE_RIGHT);
                    pauseCtx->mainState = PAUSE_MAIN_STATE_IDLE;
                    return;
                }

                while (nextCursorPoint > CURSOR_NONE) {
                    if (KaleidoScope_UpdateQuestStatusPoint(pauseCtx, nextCursorPoint)) {
                        break;
                    }
                    nextCursorPoint = sCursorPointLinks[nextCursorPoint].right;
                }
            }

            if (pauseCtx->stickAdjY < -30) {
                
                if (pauseCtx->mainState == PAUSE_MAIN_STATE_SONG_PROMPT) {
                    AudioOcarina_SetInstrument(OCARINA_INSTRUMENT_OFF);
                }
                nextCursorPoint = sCursorPointLinks[oldCursorPoint].down;

                while (nextCursorPoint > CURSOR_NONE) {
                    pauseCtx->cursorShrinkRate = 4.0f;
                    if (KaleidoScope_UpdateQuestStatusPoint(pauseCtx, nextCursorPoint)) {
                        break;
                    }
                    nextCursorPoint = sCursorPointLinks[nextCursorPoint].down;
                }
            } else if (pauseCtx->stickAdjY > 30) {
                
                if (pauseCtx->mainState == PAUSE_MAIN_STATE_SONG_PROMPT) {
                    AudioOcarina_SetInstrument(OCARINA_INSTRUMENT_OFF);
                }
                nextCursorPoint = sCursorPointLinks[oldCursorPoint].up;
                while (nextCursorPoint > CURSOR_NONE) {
                    pauseCtx->cursorShrinkRate = 4.0f;
                    if (KaleidoScope_UpdateQuestStatusPoint(pauseCtx, nextCursorPoint)) {
                        break;
                    }
                    nextCursorPoint = sCursorPointLinks[nextCursorPoint].up;
                }
            }

            
            if (oldCursorPoint != pauseCtx->cursorPoint[PAUSE_QUEST]) {
                pauseCtx->mainState = PAUSE_MAIN_STATE_IDLE;
                Audio_PlaySfx(NA_SE_SY_CURSOR);
            }

            
            if (pauseCtx->cursorPoint[PAUSE_QUEST] != QUEST_HEART_PIECE) {
                if (pauseCtx->cursorPoint[PAUSE_QUEST] <= QUEST_REMAINS_TWINMOLD) {
                    
                    if (CHECK_QUEST_ITEM(pauseCtx->cursorPoint[PAUSE_QUEST])) {
                        cursorItem = ITEM_REMAINS_ODOLWA + pauseCtx->cursorPoint[PAUSE_QUEST];
                    } else {
                        cursorItem = PAUSE_ITEM_NONE;
                    }
                } else if (pauseCtx->cursorPoint[PAUSE_QUEST] == QUEST_BOMBERS_NOTEBOOK) {
                    
                    if (CHECK_QUEST_ITEM(pauseCtx->cursorPoint[PAUSE_QUEST])) {
                        cursorItem = ITEM_BOMBERS_NOTEBOOK;
                    } else {
                        cursorItem = PAUSE_ITEM_NONE;
                    }
                } else if (pauseCtx->cursorPoint[PAUSE_QUEST] == QUEST_SHIELD) {
                    
                    if (GET_CUR_EQUIP_VALUE(EQUIP_TYPE_SHIELD) != EQUIP_VALUE_SHIELD_NONE) {
                        cursorItem = (ITEM_SHIELD_HERO - EQUIP_TYPE_SHIELD) + GET_CUR_EQUIP_VALUE(EQUIP_TYPE_SHIELD);
                    } else {
                        cursorItem = PAUSE_ITEM_NONE;
                    }
                } else if (pauseCtx->cursorPoint[PAUSE_QUEST] == QUEST_SWORD) {
                    
                    if (GET_CUR_EQUIP_VALUE(EQUIP_TYPE_SWORD) != EQUIP_VALUE_SWORD_NONE) {
                        cursorItem =
                            (ITEM_SWORD_KOKIRI - EQUIP_VALUE_SWORD_KOKIRI) + GET_CUR_EQUIP_VALUE(EQUIP_TYPE_SWORD);
                    } else {
                        cursorItem = PAUSE_ITEM_NONE;
                    }
                } else if (pauseCtx->cursorPoint[PAUSE_QUEST] <= QUEST_SONG_SUN) {
                    
                    if (CHECK_QUEST_ITEM(pauseCtx->cursorPoint[PAUSE_QUEST])) {
                        cursorItem = ITEM_WALLET_GIANT + pauseCtx->cursorPoint[PAUSE_QUEST];
                    } else if ((pauseCtx->cursorPoint[PAUSE_QUEST] == QUEST_SONG_LULLABY) &&
                               CHECK_QUEST_ITEM(QUEST_SONG_LULLABY_INTRO)) {
                        cursorItem = ITEM_SONG_LULLABY_INTRO;
                    } else {
                        cursorItem = PAUSE_ITEM_NONE;
                    }
                } else if (pauseCtx->cursorPoint[PAUSE_QUEST] == QUEST_QUIVER) {
                    
                    if (GET_CUR_UPG_VALUE(UPG_QUIVER) != 0) {
                        cursorItem = (ITEM_QUIVER_30 - 1) + GET_CUR_UPG_VALUE(UPG_QUIVER);
                    } else {
                        cursorItem = PAUSE_ITEM_NONE;
                    }
                } else if (pauseCtx->cursorPoint[PAUSE_QUEST] == QUEST_BOMB_BAG) {
                    
                    if (GET_CUR_UPG_VALUE(UPG_BOMB_BAG) != 0) {
                        cursorItem = (ITEM_BOMB_BAG_20 - 1) + GET_CUR_UPG_VALUE(UPG_BOMB_BAG);
                    } else {
                        cursorItem = PAUSE_ITEM_NONE;
                    }
                } else {
                    cursorItem = PAUSE_ITEM_NONE;
                }
            } else {
                
                if ((GET_SAVE_INVENTORY_QUEST_ITEMS >> QUEST_HEART_PIECE_COUNT) != 0) {
                    cursorItem = ITEM_HEART_CONTAINER;
                } else {
                    cursorItem = PAUSE_ITEM_NONE;
                }
            }

            cursor = pauseCtx->cursorPoint[PAUSE_QUEST];
            pauseCtx->cursorItem[pauseCtx->pageIndex] = cursorItem;
            pauseCtx->cursorSlot[pauseCtx->pageIndex] = cursor;

            if ((pauseCtx->debugEditor == DEBUG_EDITOR_NONE) && (pauseCtx->state == PAUSE_STATE_MAIN) &&
                (pauseCtx->mainState == PAUSE_MAIN_STATE_IDLE) && (pauseCtx->cursorSpecialPos == 0)) {
                if ((cursor >= QUEST_SONG_SONATA) && (cursor <= QUEST_SONG_SUN)) {
                    
                    if ((CHECK_QUEST_ITEM(pauseCtx->cursorPoint[PAUSE_QUEST]) ||
                         ((cursor == QUEST_SONG_LULLABY) && !CHECK_QUEST_ITEM(pauseCtx->cursorPoint[PAUSE_QUEST]) &&
                          CHECK_QUEST_ITEM(QUEST_SONG_LULLABY_INTRO))) &&
                        (msgCtx->msgLength == 0)) {
                        
                        

                        if (CHECK_QUEST_ITEM(pauseCtx->cursorPoint[PAUSE_QUEST])) {
                            cursor = pauseCtx->cursorSlot[PAUSE_QUEST];
                        } else {
                            cursor = QUEST_BOMB_BAG;
                        }

                        pauseCtx->ocarinaSongIndex = gOcarinaSongItemMap[cursor - QUEST_SONG_SONATA];
                        sQuestSongPlaybackDelayTimer = 10;

                        for (i = 0; i < 8; i++) {
                            sQuestSongPlayedOcarinaButtons[i] = OCARINA_BTN_INVALID;
                            sQuestSongPlayedOcarinaButtonsAlpha[i] = 0;
                        }

                        sQuestSongPlayedOcarinaButtonsNum = 0;

                        
                        AudioOcarina_SetInstrument(OCARINA_INSTRUMENT_DEFAULT);
                        AudioOcarina_StartDefault((1 << pauseCtx->ocarinaSongIndex) | 0x80000000);

                        
                        pauseCtx->ocarinaStaff = AudioOcarina_GetPlaybackStaff();
                        pauseCtx->ocarinaStaff->pos = 0;
                        pauseCtx->ocarinaStaff->state = 0xFF;

                        pauseCtx->ocarinaButtonsY[OCARINA_BTN_A] = -62;
                        pauseCtx->ocarinaButtonsY[OCARINA_BTN_C_DOWN] = -56;
                        pauseCtx->ocarinaButtonsY[OCARINA_BTN_C_RIGHT] = -49;
                        pauseCtx->ocarinaButtonsY[OCARINA_BTN_C_LEFT] = -46;
                        pauseCtx->ocarinaButtonsY[OCARINA_BTN_C_UP] = -41;

                        pauseCtx->mainState = PAUSE_MAIN_STATE_IDLE_CURSOR_ON_SONG;

                        if (interfaceCtx->aButtonDoActionDelayed != DO_ACTION_DECIDE) {
                            Interface_SetAButtonDoAction(play, DO_ACTION_DECIDE);
                        }

                        
                        AudioOcarina_SetInstrument(OCARINA_INSTRUMENT_OFF);

                        if (gSaveContext.buttonStatus[EQUIP_SLOT_A] == BTN_DISABLED) {
                            gSaveContext.buttonStatus[EQUIP_SLOT_A] = BTN_ENABLED;
                            gSaveContext.hudVisibility = HUD_VISIBILITY_IDLE;
                            Interface_SetHudVisibility(HUD_VISIBILITY_ALL);
                        }
                    } else {
                        if (interfaceCtx->aButtonDoActionDelayed != DO_ACTION_DECIDE) {
                            Interface_SetAButtonDoAction(play, DO_ACTION_DECIDE);
                        }
                        if (gSaveContext.buttonStatus[EQUIP_SLOT_A] != BTN_DISABLED) {
                            gSaveContext.buttonStatus[EQUIP_SLOT_A] = BTN_DISABLED;
                            gSaveContext.hudVisibility = HUD_VISIBILITY_IDLE;
                            Interface_SetHudVisibility(HUD_VISIBILITY_ALL);
                        }
                    }
                } else {
                    if ((cursor == QUEST_BOMBERS_NOTEBOOK) && (pauseCtx->cursorItem[PAUSE_QUEST] != PAUSE_ITEM_NONE)) {
                        if (interfaceCtx->aButtonDoActionDelayed != DO_ACTION_DECIDE) {
                            Interface_SetAButtonDoAction(play, DO_ACTION_DECIDE);
                        }
                        pauseCtx->cursorColorSet = PAUSE_CURSOR_COLOR_SET_BLUE;
                    } else if (interfaceCtx->aButtonDoActionDelayed == DO_ACTION_DECIDE) {
                        Interface_SetAButtonDoAction(play, DO_ACTION_INFO);
                    }

                    if ((pauseCtx->cursorItem[PAUSE_QUEST] != PAUSE_ITEM_NONE) && (msgCtx->msgLength == 0)) {
                        if (gSaveContext.buttonStatus[EQUIP_SLOT_A] == BTN_DISABLED) {
                            gSaveContext.buttonStatus[EQUIP_SLOT_A] = BTN_ENABLED;
                            gSaveContext.hudVisibility = HUD_VISIBILITY_IDLE;
                            Interface_SetHudVisibility(HUD_VISIBILITY_ALL);
                        }

                        if (CHECK_BTN_ALL(CONTROLLER1(&play->state)->press.button, BTN_A) && (msgCtx->msgLength == 0)) {
                            if (pauseCtx->cursorPoint[PAUSE_QUEST] == QUEST_BOMBERS_NOTEBOOK) {
                                play->pauseCtx.bombersNotebookOpen = true;
                                pauseCtx->mainState = PAUSE_MAIN_STATE_BOMBERS_NOTEBOOK_OPEN;
                                Audio_PlaySfx(NA_SE_SY_DECIDE);
                            } else {
                                pauseCtx->itemDescriptionOn = true;
                                if (pauseCtx->cursorYIndex[PAUSE_QUEST] < 2) {
                                    if (pauseCtx->cursorItem[PAUSE_QUEST] < ITEM_REMAINS_ODOLWA) {
                                        Message_PauseMenu_ShowDescription(
                                            play, 0x1737 + pauseCtx->cursorItem[PAUSE_QUEST], 1);
                                    } else {
                                        Message_PauseMenu_ShowDescription(
                                            play, 0x173B + pauseCtx->cursorItem[PAUSE_QUEST], 3);
                                    }
                                } else {
                                    if (pauseCtx->cursorItem[PAUSE_QUEST] < ITEM_REMAINS_ODOLWA) {
                                        Message_PauseMenu_ShowDescription(
                                            play, 0x1737 + pauseCtx->cursorItem[PAUSE_QUEST], 1);
                                    } else {
                                        Message_PauseMenu_ShowDescription(
                                            play, 0x173B + pauseCtx->cursorItem[PAUSE_QUEST], 1);
                                    }
                                }
                            }
                        }
                    } else if (gSaveContext.buttonStatus[EQUIP_SLOT_A] != BTN_DISABLED) {
                        gSaveContext.buttonStatus[EQUIP_SLOT_A] = BTN_DISABLED;
                        gSaveContext.hudVisibility = HUD_VISIBILITY_IDLE;
                        Interface_SetHudVisibility(HUD_VISIBILITY_ALL);
                    }
                }
            } else if (pauseCtx->mainState == PAUSE_MAIN_STATE_SONG_PROMPT) {
                
                if ((pauseCtx->stickAdjX != 0) || (pauseCtx->stickAdjY != 0)) {
                    pauseCtx->mainState = PAUSE_MAIN_STATE_IDLE;
                    AudioOcarina_SetInstrument(OCARINA_INSTRUMENT_OFF);
                }
            } else if ((pauseCtx->mainState == PAUSE_MAIN_STATE_IDLE_CURSOR_ON_SONG) &&
                       CHECK_BTN_ALL(CONTROLLER1(&play->state)->press.button, BTN_A) && (msgCtx->msgLength == 0) &&
                       (cursor >= QUEST_SONG_SONATA) && (cursor <= QUEST_SONG_SUN)) {
                pauseCtx->mainState = PAUSE_MAIN_STATE_SONG_PLAYBACK_INIT;
                sQuestSongPlaybackDelayTimer = 10;
            }

            if (pauseCtx->cursorSpecialPos == 0) {
                if ((pauseCtx->cursorSlot[PAUSE_QUEST] >= 6) && (pauseCtx->cursorSlot[PAUSE_QUEST] < 0x12) &&
                    ((pauseCtx->mainState <= PAUSE_MAIN_STATE_SONG_PLAYBACK) ||
                     (pauseCtx->mainState == PAUSE_MAIN_STATE_SONG_PROMPT) ||
                     (pauseCtx->mainState == PAUSE_MAIN_STATE_IDLE_CURSOR_ON_SONG)) &&
                    (pauseCtx->cursorItem[pauseCtx->pageIndex] != PAUSE_ITEM_NONE)) {
                    pauseCtx->cursorColorSet = PAUSE_CURSOR_COLOR_SET_BLUE;
                    if ((pauseCtx->mainState >= PAUSE_MAIN_STATE_SONG_PLAYBACK) &&
                        (pauseCtx->mainState <= PAUSE_MAIN_STATE_SONG_PROMPT_DONE)) {
                        pauseCtx->cursorColorSet = PAUSE_CURSOR_COLOR_SET_WHITE;
                    }
                }
            }
        } else if (pauseCtx->cursorSpecialPos == PAUSE_CURSOR_PAGE_LEFT) {
            if (pauseCtx->stickAdjX > 30) {
                if (pauseCtx->mainState == PAUSE_MAIN_STATE_SONG_PROMPT) {
                    AudioOcarina_SetInstrument(OCARINA_INSTRUMENT_OFF);
                }

                KaleidoScope_MoveCursorFromSpecialPos(play);

                pauseCtx->cursorPoint[PAUSE_QUEST] = QUEST_BOMBERS_NOTEBOOK;
                if (CHECK_QUEST_ITEM(QUEST_BOMBERS_NOTEBOOK)) {
                    cursorItem = ITEM_BOMBERS_NOTEBOOK;
                } else {
                    cursorItem = PAUSE_ITEM_NONE;
                }

                cursor = pauseCtx->cursorPoint[PAUSE_QUEST];
                pauseCtx->cursorItem[pauseCtx->pageIndex] = cursorItem;
                pauseCtx->cursorSlot[pauseCtx->pageIndex] = cursor;
            }
        } else if (pauseCtx->stickAdjX < -30) {
            if (pauseCtx->mainState == PAUSE_MAIN_STATE_SONG_PROMPT) {
                AudioOcarina_SetInstrument(OCARINA_INSTRUMENT_OFF);
            }

            KaleidoScope_MoveCursorFromSpecialPos(play);

            pauseCtx->cursorPoint[PAUSE_QUEST] = QUEST_REMAINS_GOHT;
            if (CHECK_QUEST_ITEM(pauseCtx->cursorPoint[PAUSE_QUEST])) {
                cursorItem = (ITEM_REMAINS_GOHT - 1) + pauseCtx->cursorPoint[PAUSE_QUEST];
                if (pauseCtx->cursorPoint[PAUSE_QUEST] != QUEST_REMAINS_ODOLWA) {
                    
                    cursorItem = ITEM_MASK_GIANT;
                }
            } else {
                cursorItem = PAUSE_ITEM_NONE;
            }

            cursor = pauseCtx->cursorPoint[PAUSE_QUEST];
            pauseCtx->cursorItem[pauseCtx->pageIndex] = cursorItem;
            pauseCtx->cursorSlot[pauseCtx->pageIndex] = cursor;
        }
    } else if (pauseCtx->mainState == PAUSE_MAIN_STATE_SONG_PLAYBACK_INIT) {
        

        pauseCtx->cursorColorSet = PAUSE_CURSOR_COLOR_SET_BLUE;
        sQuestSongPlaybackDelayTimer--;
        if (sQuestSongPlaybackDelayTimer == 0) {
            for (i = 0; i < 8; i++) {
                sQuestSongPlayedOcarinaButtons[i] = OCARINA_BTN_INVALID;
                sQuestSongPlayedOcarinaButtonsAlpha[i] = 0;
            }
            sQuestSongPlayedOcarinaButtonsNum = 0;

            pauseCtx->ocarinaButtonsY[OCARINA_BTN_A] = -62;
            pauseCtx->ocarinaButtonsY[OCARINA_BTN_C_DOWN] = -56;
            pauseCtx->ocarinaButtonsY[OCARINA_BTN_C_RIGHT] = -49;
            pauseCtx->ocarinaButtonsY[OCARINA_BTN_C_LEFT] = -46;
            pauseCtx->ocarinaButtonsY[OCARINA_BTN_C_UP] = -41;

            if (CHECK_QUEST_ITEM(pauseCtx->cursorPoint[PAUSE_QUEST])) {
                cursor = pauseCtx->cursorSlot[PAUSE_QUEST];
            } else {
                cursor = QUEST_BOMB_BAG;
            }

            AudioOcarina_SetInstrument(OCARINA_INSTRUMENT_DEFAULT);
            AudioOcarina_SetInstrument(OCARINA_INSTRUMENT_DEFAULT);
            pauseCtx->ocarinaSongIndex = gOcarinaSongItemMap[cursor - QUEST_SONG_SONATA];
            AudioOcarina_SetPlaybackSong(pauseCtx->ocarinaSongIndex + 1, 1);
            pauseCtx->mainState = PAUSE_MAIN_STATE_SONG_PLAYBACK;
            pauseCtx->ocarinaStaff = AudioOcarina_GetPlaybackStaff();
            pauseCtx->ocarinaStaff->pos = 0;
        }
    }
}
