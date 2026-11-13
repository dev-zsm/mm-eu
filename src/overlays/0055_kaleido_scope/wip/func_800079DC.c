// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (KaleidoScope_UpdateMaskCursor), score 4.00 (4 differ, size +2)
#include "generated/mm/z_kaleido_mask.h"

void func_800079DC(PlayState* play) {
    Input* input = CONTROLLER1(&play->state);
    PauseContext* pauseCtx = &play->pauseCtx;
    MessageContext* msgCtx = &play->msgCtx;
    u16 vtxIndex;
    u16 cursorItem;
    u16 cursorSlot;
    s16 cursorPoint;
    s16 cursorXIndex;
    s16 cursorYIndex;
    s16 oldCursorPoint;
    s16 moveCursorResult;
    s16 pad2;

    pauseCtx->cursorColorSet = PAUSE_CURSOR_COLOR_SET_WHITE;
    pauseCtx->nameColorSet = PAUSE_NAME_COLOR_SET_WHITE;

    if ((pauseCtx->state == PAUSE_STATE_MAIN) && (pauseCtx->mainState == PAUSE_MAIN_STATE_IDLE) &&
        (pauseCtx->pageIndex == PAUSE_MASK) && !pauseCtx->itemDescriptionOn) {
        moveCursorResult = PAUSE_CURSOR_RESULT_NONE;
        oldCursorPoint = pauseCtx->cursorPoint[PAUSE_MASK];

        cursorItem = pauseCtx->cursorItem[PAUSE_MASK];

        
        if (pauseCtx->cursorSpecialPos == 0) {
            
            pauseCtx->cursorColorSet = PAUSE_CURSOR_COLOR_SET_YELLOW;

            if (ABS_ALT(pauseCtx->stickAdjX) > 30) {
                cursorPoint = pauseCtx->cursorPoint[PAUSE_MASK];
                cursorXIndex = pauseCtx->cursorXIndex[PAUSE_MASK];
                cursorYIndex = pauseCtx->cursorYIndex[PAUSE_MASK];

                
                while (moveCursorResult == PAUSE_CURSOR_RESULT_NONE) {
                    if (pauseCtx->stickAdjX < -30) {
                        
                        pauseCtx->cursorShrinkRate = 4.0f;
                        if (pauseCtx->cursorXIndex[PAUSE_MASK] != 0) {
                            pauseCtx->cursorXIndex[PAUSE_MASK]--;
                            pauseCtx->cursorPoint[PAUSE_MASK]--;
                            moveCursorResult = PAUSE_CURSOR_RESULT_SLOT;
                        } else {
                            pauseCtx->cursorYIndex[PAUSE_MASK]++;

                            if (pauseCtx->cursorYIndex[PAUSE_MASK] >= 4) {
                                pauseCtx->cursorYIndex[PAUSE_MASK] = 0;
                            }

                            pauseCtx->cursorPoint[PAUSE_MASK] =
                                pauseCtx->cursorXIndex[PAUSE_MASK] + (pauseCtx->cursorYIndex[PAUSE_MASK] * 6);

                            if (pauseCtx->cursorPoint[PAUSE_MASK] >= MASK_NUM_SLOTS) {
                                pauseCtx->cursorPoint[PAUSE_MASK] = pauseCtx->cursorXIndex[PAUSE_MASK];
                            }

                            if (cursorYIndex == pauseCtx->cursorYIndex[PAUSE_MASK]) {
                                pauseCtx->cursorXIndex[PAUSE_MASK] = cursorXIndex;
                                pauseCtx->cursorPoint[PAUSE_MASK] = cursorPoint;

                                KaleidoScope_MoveCursorToSpecialPos(play, PAUSE_CURSOR_PAGE_LEFT);

                                moveCursorResult = PAUSE_CURSOR_RESULT_SPECIAL_POS;
                            }
                        }
                    } else if (pauseCtx->stickAdjX > 30) {
                        
                        pauseCtx->cursorShrinkRate = 4.0f;
                        if (pauseCtx->cursorXIndex[PAUSE_MASK] <= 4) {
                            pauseCtx->cursorXIndex[PAUSE_MASK]++;
                            pauseCtx->cursorPoint[PAUSE_MASK]++;
                            moveCursorResult = PAUSE_CURSOR_RESULT_SLOT;
                        } else {
                            pauseCtx->cursorYIndex[PAUSE_MASK]++;

                            if (pauseCtx->cursorYIndex[PAUSE_MASK] >= 4) {
                                pauseCtx->cursorYIndex[PAUSE_MASK] = 0;
                            }

                            pauseCtx->cursorPoint[PAUSE_MASK] =
                                pauseCtx->cursorXIndex[PAUSE_MASK] + (pauseCtx->cursorYIndex[PAUSE_MASK] * 6);

                            if (pauseCtx->cursorPoint[PAUSE_MASK] >= MASK_NUM_SLOTS) {
                                pauseCtx->cursorPoint[PAUSE_MASK] = pauseCtx->cursorXIndex[PAUSE_MASK];
                            }

                            if (cursorYIndex == pauseCtx->cursorYIndex[PAUSE_MASK]) {
                                pauseCtx->cursorXIndex[PAUSE_MASK] = cursorXIndex;
                                pauseCtx->cursorPoint[PAUSE_MASK] = cursorPoint;

                                KaleidoScope_MoveCursorToSpecialPos(play, PAUSE_CURSOR_PAGE_RIGHT);

                                moveCursorResult = PAUSE_CURSOR_RESULT_SPECIAL_POS;
                            }
                        }
                    }
                }

                if (moveCursorResult == PAUSE_CURSOR_RESULT_SLOT) {
                    cursorItem =
                        gSaveContext.save.saveInfo.inventory.items[pauseCtx->cursorPoint[PAUSE_MASK] + ITEM_NUM_SLOTS];
                    if (CHECK_GIVEN_MASK_ON_MOON(pauseCtx->cursorPoint[PAUSE_MASK])) {
                        cursorItem = ITEM_NONE;
                    }
                }
            }
        } else if (pauseCtx->cursorSpecialPos == PAUSE_CURSOR_PAGE_LEFT) {
            if (pauseCtx->stickAdjX > 30) {
                KaleidoScope_MoveCursorFromSpecialPos(play);
                cursorYIndex = 0;
                cursorXIndex = 0;
                cursorPoint = 0; 

                
                while (true) {
                    
                    if ((gSaveContext.save.saveInfo.inventory.items[cursorPoint + ITEM_NUM_SLOTS] != ITEM_NONE) &&
                        !CHECK_GIVEN_MASK_ON_MOON(cursorPoint)) {
                        pauseCtx->cursorPoint[PAUSE_MASK] = cursorPoint;
                        pauseCtx->cursorXIndex[PAUSE_MASK] = cursorXIndex;
                        pauseCtx->cursorYIndex[PAUSE_MASK] = cursorYIndex;
                        moveCursorResult = PAUSE_CURSOR_RESULT_SLOT;
                        break;
                    }

                    
                    cursorYIndex++;
                    cursorPoint += 6;
                    if (cursorYIndex < 4) {
                        continue;
                    }

                    
                    cursorYIndex = 0;
                    cursorPoint = cursorXIndex + 1;
                    cursorXIndex = cursorPoint;
                    if (cursorXIndex < 6) {
                        continue;
                    }

                    
                    KaleidoScope_MoveCursorToSpecialPos(play, PAUSE_CURSOR_PAGE_RIGHT);
                    break;
                }
            }
        } else { 
            
            if (1) {}
            if (pauseCtx->stickAdjX < -30) {
                KaleidoScope_MoveCursorFromSpecialPos(play);
                cursorXIndex = 5;
                cursorPoint = 5; 
                cursorYIndex = 0;

                
                while (true) {
                    
                    if ((gSaveContext.save.saveInfo.inventory.items[cursorPoint + ITEM_NUM_SLOTS] != ITEM_NONE) &&
                        !CHECK_GIVEN_MASK_ON_MOON(cursorPoint)) {
                        pauseCtx->cursorPoint[PAUSE_MASK] = cursorPoint;
                        pauseCtx->cursorXIndex[PAUSE_MASK] = cursorXIndex;
                        pauseCtx->cursorYIndex[PAUSE_MASK] = cursorYIndex;
                        moveCursorResult = PAUSE_CURSOR_RESULT_SLOT;
                        break;
                    }

                    
                    cursorYIndex++;
                    cursorPoint += 6;
                    if (cursorYIndex < 4) {
                        continue;
                    }

                    
                    cursorYIndex = 0;
                    cursorPoint = cursorXIndex - 1;
                    cursorXIndex = cursorPoint;
                    if (cursorXIndex >= 0) {
                        continue;
                    }

                    
                    KaleidoScope_MoveCursorToSpecialPos(play, PAUSE_CURSOR_PAGE_LEFT);
                    break;
                }
            }
        }

        if (pauseCtx->cursorSpecialPos == 0) {
            
            if (ABS_ALT(pauseCtx->stickAdjY) > 30) {
                moveCursorResult = PAUSE_CURSOR_RESULT_NONE;

                cursorPoint = pauseCtx->cursorPoint[PAUSE_MASK];
                cursorYIndex = pauseCtx->cursorYIndex[PAUSE_MASK];

                while (moveCursorResult == PAUSE_CURSOR_RESULT_NONE) {
                    if (pauseCtx->stickAdjY > 30) {
                        
                        moveCursorResult = PAUSE_CURSOR_RESULT_SPECIAL_POS;
                        if (pauseCtx->cursorYIndex[PAUSE_MASK] != 0) {
                            pauseCtx->cursorShrinkRate = 4.0f;
                            pauseCtx->cursorYIndex[PAUSE_MASK]--;
                            pauseCtx->cursorPoint[PAUSE_MASK] -= 6;
                            moveCursorResult = PAUSE_CURSOR_RESULT_SLOT;
                        } else {
                            pauseCtx->cursorYIndex[PAUSE_MASK] = cursorYIndex;
                            pauseCtx->cursorPoint[PAUSE_MASK] = cursorPoint;
                        }
                    } else if (pauseCtx->stickAdjY < -30) {
                        
                        moveCursorResult = PAUSE_CURSOR_RESULT_SPECIAL_POS;
                        if (pauseCtx->cursorYIndex[PAUSE_MASK] < 3) {
                            pauseCtx->cursorShrinkRate = 4.0f;
                            pauseCtx->cursorYIndex[PAUSE_MASK]++;
                            pauseCtx->cursorPoint[PAUSE_MASK] += 6;
                            moveCursorResult = PAUSE_CURSOR_RESULT_SLOT;
                        } else {
                            pauseCtx->cursorYIndex[PAUSE_MASK] = cursorYIndex;
                            pauseCtx->cursorPoint[PAUSE_MASK] = cursorPoint;
                        }
                    }
                }
            }

            cursorSlot = pauseCtx->cursorPoint[PAUSE_MASK];
            pauseCtx->cursorColorSet = PAUSE_CURSOR_COLOR_SET_YELLOW;

            if (moveCursorResult == PAUSE_CURSOR_RESULT_SLOT) {
                cursorItem =
                    gSaveContext.save.saveInfo.inventory.items[pauseCtx->cursorPoint[PAUSE_MASK] + ITEM_NUM_SLOTS];
                if (CHECK_GIVEN_MASK_ON_MOON(pauseCtx->cursorPoint[PAUSE_MASK])) {
                    cursorItem = ITEM_NONE;
                }
            } else if (moveCursorResult != PAUSE_CURSOR_RESULT_SPECIAL_POS) {
                cursorItem =
                    gSaveContext.save.saveInfo.inventory.items[pauseCtx->cursorPoint[PAUSE_MASK] + ITEM_NUM_SLOTS];
                if (CHECK_GIVEN_MASK_ON_MOON(pauseCtx->cursorPoint[PAUSE_MASK])) {
                    cursorItem = ITEM_NONE;
                }
            }

            if (cursorItem == ITEM_NONE) {
                cursorItem = PAUSE_ITEM_NONE;
                pauseCtx->cursorColorSet = PAUSE_CURSOR_COLOR_SET_WHITE;
            }

            if ((cursorItem != PAUSE_ITEM_NONE) && (msgCtx->msgLength == 0)) {
                if (gSaveContext.buttonStatus[EQUIP_SLOT_A] == BTN_DISABLED) {
                    gSaveContext.buttonStatus[EQUIP_SLOT_A] = BTN_ENABLED;
                    gSaveContext.hudVisibility = HUD_VISIBILITY_IDLE;
                    Interface_SetHudVisibility(HUD_VISIBILITY_ALL);
                }
            } else if (gSaveContext.buttonStatus[EQUIP_SLOT_A] != BTN_DISABLED) {
                gSaveContext.buttonStatus[EQUIP_SLOT_A] = BTN_DISABLED;
                gSaveContext.hudVisibility = HUD_VISIBILITY_IDLE;
                Interface_SetHudVisibility(HUD_VISIBILITY_ALL);
            }

            pauseCtx->cursorItem[PAUSE_MASK] = cursorItem;
            pauseCtx->cursorSlot[PAUSE_MASK] = cursorSlot;
            if (cursorItem != PAUSE_ITEM_NONE) {
                
                if ((pauseCtx->debugEditor == DEBUG_EDITOR_NONE) && !pauseCtx->itemDescriptionOn &&
                    (pauseCtx->state == PAUSE_STATE_MAIN) && (pauseCtx->mainState == PAUSE_MAIN_STATE_IDLE) &&
                    CHECK_BTN_ANY(input->press.button, BTN_CLEFT | BTN_CDOWN | BTN_CRIGHT)) {

                    
                    if (CHECK_BTN_ALL(input->press.button, BTN_CLEFT)) {
                        if (((Player_GetCurMaskItemId(play) != ITEM_NONE) &&
                             (Player_GetCurMaskItemId(play) == BUTTON_ITEM_EQUIP(0, EQUIP_SLOT_C_LEFT))) ||
                            ((sMaskPlayerFormItems[GET_PLAYER_FORM] != ITEM_NONE) &&
                             (sMaskPlayerFormItems[GET_PLAYER_FORM] == BUTTON_ITEM_EQUIP(0, EQUIP_SLOT_C_LEFT)))) {
                            Audio_PlaySfx(NA_SE_SY_ERROR);
                            return;
                        }
                    } else if (CHECK_BTN_ALL(input->press.button, BTN_CDOWN)) {
                        if (((Player_GetCurMaskItemId(play) != ITEM_NONE) &&
                             (Player_GetCurMaskItemId(play) == BUTTON_ITEM_EQUIP(0, EQUIP_SLOT_C_DOWN))) ||
                            ((sMaskPlayerFormItems[GET_PLAYER_FORM] != ITEM_NONE) &&
                             (sMaskPlayerFormItems[GET_PLAYER_FORM] == BUTTON_ITEM_EQUIP(0, EQUIP_SLOT_C_DOWN)))) {
                            Audio_PlaySfx(NA_SE_SY_ERROR);
                            return;
                        }
                    } else if (CHECK_BTN_ALL(input->press.button, BTN_CRIGHT)) {
                        if (((Player_GetCurMaskItemId(play) != ITEM_NONE) &&
                             (Player_GetCurMaskItemId(play) == BUTTON_ITEM_EQUIP(0, EQUIP_SLOT_C_RIGHT))) ||
                            ((sMaskPlayerFormItems[GET_PLAYER_FORM] != ITEM_NONE) &&
                             (sMaskPlayerFormItems[GET_PLAYER_FORM] == BUTTON_ITEM_EQUIP(0, EQUIP_SLOT_C_RIGHT)))) {
                            Audio_PlaySfx(NA_SE_SY_ERROR);
                            return;
                        }
                    }

                    if ((Player_GetEnvironmentalHazard(play) >= PLAYER_ENV_HAZARD_UNDERWATER_FLOOR) &&
                        (Player_GetEnvironmentalHazard(play) <= PLAYER_ENV_HAZARD_UNDERWATER_FREE) &&
                        ((cursorSlot == (SLOT_MASK_DEKU - ITEM_NUM_SLOTS)) ||
                         (cursorSlot == (SLOT_MASK_GORON - ITEM_NUM_SLOTS)))) {
                        Audio_PlaySfx(NA_SE_SY_ERROR);
                        return;
                    }

                    if (CHECK_BTN_ALL(input->press.button, BTN_CLEFT)) {
                        pauseCtx->equipTargetCBtn = PAUSE_EQUIP_C_LEFT;
                    } else if (CHECK_BTN_ALL(input->press.button, BTN_CDOWN)) {
                        pauseCtx->equipTargetCBtn = PAUSE_EQUIP_C_DOWN;
                    } else if (CHECK_BTN_ALL(input->press.button, BTN_CRIGHT)) {
                        pauseCtx->equipTargetCBtn = PAUSE_EQUIP_C_RIGHT;
                    }

                    
                    pauseCtx->equipTargetItem = cursorItem;
                    pauseCtx->equipTargetSlot = cursorSlot + ITEM_NUM_SLOTS;
                    pauseCtx->mainState = PAUSE_MAIN_STATE_EQUIP_MASK;
                    vtxIndex = cursorSlot * 4;
                    pauseCtx->equipAnimX = pauseCtx->maskVtx[vtxIndex].v.ob[0] * 10;
                    pauseCtx->equipAnimY = pauseCtx->maskVtx[vtxIndex].v.ob[1] * 10;
                    pauseCtx->equipAnimAlpha = 255;
                    sMaskEquipMagicArrowSlotHoldTimer = 0;
                    sMaskEquipState = EQUIP_STATE_MOVE_TO_C_BTN;
                    sMaskEquipAnimTimer = 10;
                    Audio_PlaySfx(NA_SE_SY_DECIDE);
                } else if ((pauseCtx->debugEditor == DEBUG_EDITOR_NONE) && (pauseCtx->state == PAUSE_STATE_MAIN) &&
                           (pauseCtx->mainState == PAUSE_MAIN_STATE_IDLE) &&
                           CHECK_BTN_ALL(input->press.button, BTN_A) && (msgCtx->msgLength == 0)) {
                    
                    pauseCtx->itemDescriptionOn = true;
                    if (pauseCtx->cursorYIndex[PAUSE_MASK] < 2) {
                        Message_PauseMenu_ShowDescription(play, 0x1700 + pauseCtx->cursorItem[PAUSE_MASK], 3);
                    } else {
                        Message_PauseMenu_ShowDescription(play, 0x1700 + pauseCtx->cursorItem[PAUSE_MASK], 1);
                    }
                }
            }
        } else {
            pauseCtx->cursorItem[PAUSE_MASK] = PAUSE_ITEM_NONE;
        }

        if (oldCursorPoint != pauseCtx->cursorPoint[PAUSE_MASK]) {
            Audio_PlaySfx(NA_SE_SY_CURSOR);
        }
    } else if ((pauseCtx->mainState == PAUSE_MAIN_STATE_EQUIP_MASK) && (pauseCtx->pageIndex == PAUSE_MASK)) {
        pauseCtx->cursorColorSet = PAUSE_CURSOR_COLOR_SET_YELLOW;
    }
}
