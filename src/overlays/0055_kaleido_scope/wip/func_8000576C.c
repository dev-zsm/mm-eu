// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (KaleidoScope_UpdateDungeonCursor), score 2.00 (2 differ, size +0)
#include "generated/mm/z_kaleido_map.h"

void func_8000576C(PlayState* play) {
    s32 pad;
    PauseContext* pauseCtx = &play->pauseCtx;
    MessageContext* msgCtx = &play->msgCtx;
    s16 i;
    s16 oldCursorPoint;

    if (pauseCtx->state == PAUSE_STATE_MAIN) {
        if ((pauseCtx->mainState == PAUSE_MAIN_STATE_IDLE) && (pauseCtx->pageIndex == PAUSE_MAP)) {
            pauseCtx->cursorColorSet = PAUSE_CURSOR_COLOR_SET_WHITE;
            oldCursorPoint = pauseCtx->cursorPoint[PAUSE_MAP];
            if (pauseCtx->stickAdjX > 30) {
                pauseCtx->cursorShrinkRate = 4.0f;
                if (pauseCtx->cursorSpecialPos == PAUSE_CURSOR_PAGE_LEFT) {
                    KaleidoScope_MoveCursorFromSpecialPos(play);
                    pauseCtx->cursorXIndex[PAUSE_MAP] = 0;
                    pauseCtx->cursorSlot[PAUSE_MAP] = pauseCtx->cursorMapDungeonItem;
                    pauseCtx->cursorPoint[PAUSE_MAP] = pauseCtx->cursorMapDungeonItem;
                } else if (pauseCtx->cursorSpecialPos == 0) {
                    if (pauseCtx->cursorXIndex[PAUSE_MAP] == 0) {
                        pauseCtx->cursorXIndex[PAUSE_MAP] = 1;
                        pauseCtx->cursorPoint[PAUSE_MAP] = DUNGEON_STRAY_FAIRIES;
                    } else {
                        if (pauseCtx->cursorPoint[PAUSE_MAP] == DUNGEON_STRAY_FAIRIES) {
                            pauseCtx->cursorPoint[PAUSE_MAP] = DUNGEON_NONE;
                        }

                        while (true) {
                            pauseCtx->cursorPoint[PAUSE_MAP]++;
                            if (pauseCtx->cursorPoint[PAUSE_MAP] == DUNGEON_STRAY_FAIRIES) {
                                KaleidoScope_MoveCursorToSpecialPos(play, PAUSE_CURSOR_PAGE_RIGHT);
                                break;
                            }
                            if (CHECK_DUNGEON_ITEM(pauseCtx->cursorPoint[PAUSE_MAP],
                                                   gSaveContext.dungeonSceneSharedIndex)) {
                                break;
                            }
                        }
                    }
                }
            } else if (pauseCtx->stickAdjX < -30) {
                pauseCtx->cursorShrinkRate = 4.0f;
                if (pauseCtx->cursorSpecialPos == PAUSE_CURSOR_PAGE_RIGHT) {
                    KaleidoScope_MoveCursorFromSpecialPos(play);
                    pauseCtx->cursorXIndex[PAUSE_MAP] = 1;
                    pauseCtx->cursorPoint[PAUSE_MAP] = DUNGEON_MAP;
                    if (!CHECK_DUNGEON_ITEM(DUNGEON_MAP, gSaveContext.dungeonSceneSharedIndex)) {
                        pauseCtx->cursorPoint[PAUSE_MAP]--; 
                        if (!CHECK_DUNGEON_ITEM(DUNGEON_COMPASS, gSaveContext.dungeonSceneSharedIndex)) {
                            pauseCtx->cursorPoint[PAUSE_MAP]--; 
                            if (!CHECK_DUNGEON_ITEM(DUNGEON_BOSS_KEY, gSaveContext.dungeonSceneSharedIndex)) {
                                pauseCtx->cursorSlot[PAUSE_MAP] = DUNGEON_STRAY_FAIRIES;
                                pauseCtx->cursorPoint[PAUSE_MAP] = DUNGEON_STRAY_FAIRIES;
                            }
                        }
                    } else {
                        pauseCtx->cursorSlot[PAUSE_MAP] = pauseCtx->cursorPoint[PAUSE_MAP];
                    }
                } else if (pauseCtx->cursorSpecialPos == 0) {
                    if (pauseCtx->cursorXIndex[PAUSE_MAP] == 0) {
                        KaleidoScope_MoveCursorToSpecialPos(play, PAUSE_CURSOR_PAGE_LEFT);
                    } else if (pauseCtx->cursorPoint[PAUSE_MAP] == DUNGEON_STRAY_FAIRIES) {
                        pauseCtx->cursorXIndex[PAUSE_MAP] = 0;
                        pauseCtx->cursorSlot[PAUSE_MAP] = pauseCtx->cursorMapDungeonItem;
                        pauseCtx->cursorPoint[PAUSE_MAP] = pauseCtx->cursorMapDungeonItem;
                    } else {
                        while (true) {
                            pauseCtx->cursorPoint[PAUSE_MAP]--;
                            if (pauseCtx->cursorPoint[PAUSE_MAP] <= DUNGEON_NONE) {
                                pauseCtx->cursorSlot[PAUSE_MAP] = DUNGEON_STRAY_FAIRIES;
                                pauseCtx->cursorPoint[PAUSE_MAP] = DUNGEON_STRAY_FAIRIES;
                                break;
                            }
                            if (CHECK_DUNGEON_ITEM(pauseCtx->cursorPoint[PAUSE_MAP],
                                                   gSaveContext.dungeonSceneSharedIndex)) {
                                break;
                            }
                        }
                    }
                }
            } else if ((pauseCtx->cursorSpecialPos == 0) && (pauseCtx->stickAdjY > 30)) {
                if (pauseCtx->cursorPoint[PAUSE_MAP] >= DUNGEON_FLOOR_INDEX_4) {
                    for (i = pauseCtx->cursorPoint[PAUSE_MAP] - (DUNGEON_FLOOR_INDEX_4 + 1); i >= 0; i--) {
                        if (GET_DUNGEON_FLOOR_VISITED(((void)0, gSaveContext.dungeonSceneSharedIndex), i) ||
                            MapDisp_IsValidStorey(FLOOR_INDEX_MAX - i)) {
                            pauseCtx->cursorPoint[PAUSE_MAP] = i + DUNGEON_FLOOR_INDEX_4;
                            pauseCtx->cursorShrinkRate = 4.0f;
                            break;
                        }
                    }
                } else if (pauseCtx->cursorPoint[PAUSE_MAP] == DUNGEON_STRAY_FAIRIES) {
                    pauseCtx->cursorXIndex[PAUSE_MAP] = 0;
                    pauseCtx->cursorSlot[PAUSE_MAP] = pauseCtx->cursorMapDungeonItem;
                    pauseCtx->cursorPoint[PAUSE_MAP] = pauseCtx->cursorMapDungeonItem;
                } else {
                    pauseCtx->cursorSlot[PAUSE_MAP] = DUNGEON_STRAY_FAIRIES;
                    pauseCtx->cursorPoint[PAUSE_MAP] = DUNGEON_STRAY_FAIRIES;
                }
            } else if ((pauseCtx->cursorSpecialPos == 0) && (pauseCtx->stickAdjY < -30)) {
                if ((pauseCtx->cursorPoint[PAUSE_MAP] >= DUNGEON_FLOOR_INDEX_4) &&
                    (pauseCtx->cursorPoint[PAUSE_MAP] <= DUNGEON_FLOOR_INDEX_1)) {
                    for (i = pauseCtx->cursorPoint[PAUSE_MAP] - (DUNGEON_FLOOR_INDEX_4 - 1); i <= DUNGEON_FLOOR_INDEX_0;
                         i++) {
                        if (GET_DUNGEON_FLOOR_VISITED(((void)0, gSaveContext.dungeonSceneSharedIndex), i) ||
                            MapDisp_IsValidStorey(FLOOR_INDEX_MAX - i)) {
                            pauseCtx->cursorPoint[PAUSE_MAP] = i + DUNGEON_FLOOR_INDEX_4;
                            pauseCtx->cursorShrinkRate = 4.0f;
                            break;
                        }
                    }

                } else if (pauseCtx->cursorXIndex[PAUSE_MAP] == 0) {
                    pauseCtx->cursorXIndex[PAUSE_MAP] = 1;
                    pauseCtx->cursorPoint[PAUSE_MAP] = DUNGEON_STRAY_FAIRIES;
                } else {
                    if (pauseCtx->cursorPoint[PAUSE_MAP] == DUNGEON_STRAY_FAIRIES) {
                        pauseCtx->cursorPoint[PAUSE_MAP] = DUNGEON_NONE;
                    }

                    while (true) {
                        pauseCtx->cursorPoint[PAUSE_MAP]++;
                        if (pauseCtx->cursorPoint[PAUSE_MAP] == DUNGEON_FLOOR_INDEX_4) {
                            KaleidoScope_MoveCursorToSpecialPos(play, PAUSE_CURSOR_PAGE_RIGHT);
                            break;
                        }
                        if (CHECK_DUNGEON_ITEM(pauseCtx->cursorPoint[PAUSE_MAP],
                                               gSaveContext.dungeonSceneSharedIndex)) {
                            break;
                        }
                    }
                }
            }
            if ((pauseCtx->cursorPoint[PAUSE_MAP] <= DUNGEON_STRAY_FAIRIES) && (pauseCtx->cursorSpecialPos == 0)) {
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

            if ((pauseCtx->cursorXIndex[PAUSE_MAP] == 0) && (pauseCtx->cursorSpecialPos == 0)) {
                pauseCtx->cursorMapDungeonItem = pauseCtx->cursorPoint[PAUSE_MAP];
            }

            if (pauseCtx->cursorSpecialPos == 0) {
                if (CHECK_BTN_ALL(CONTROLLER1(&play->state)->press.button, BTN_A) && (msgCtx->msgLength == 0) &&
                    (pauseCtx->cursorPoint[PAUSE_MAP] == DUNGEON_STRAY_FAIRIES)) {
                    pauseCtx->itemDescriptionOn = true;
                    Message_PauseMenu_ShowDescription(play, 0x17AF, 1);
                } else if (CHECK_BTN_ALL(CONTROLLER1(&play->state)->press.button, BTN_A) && (msgCtx->msgLength == 0) &&
                           CHECK_DUNGEON_ITEM(pauseCtx->cursorPoint[PAUSE_MAP], gSaveContext.dungeonSceneSharedIndex)) {
                    pauseCtx->itemDescriptionOn = true;
                    Message_PauseMenu_ShowDescription(play, 0x17AC + pauseCtx->cursorPoint[PAUSE_MAP], 1);
                }
            }

            if (oldCursorPoint != pauseCtx->cursorPoint[PAUSE_MAP]) {
                Audio_PlaySfx(NA_SE_SY_CURSOR);
            }
        }
    }
}
