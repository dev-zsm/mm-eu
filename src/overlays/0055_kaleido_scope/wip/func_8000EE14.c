// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (KaleidoScope_UpdateCursorSize), score 0.00 (0 differ, size +0)
#include "generated/mm/z_kaleido_scope_NES.h"

void func_8000EE14(PlayState* play) {
    PauseContext* pauseCtx = &play->pauseCtx;
    s16 index;

    pauseCtx->cursorVtx[0].v.ob[0] = pauseCtx->cursorVtx[2].v.ob[0] = -8;
    pauseCtx->cursorVtx[1].v.ob[0] = pauseCtx->cursorVtx[3].v.ob[0] = pauseCtx->cursorVtx[0].v.ob[0] + 16;

    pauseCtx->cursorVtx[0].v.ob[1] = pauseCtx->cursorVtx[1].v.ob[1] = 8;
    pauseCtx->cursorVtx[2].v.ob[1] = pauseCtx->cursorVtx[3].v.ob[1] = pauseCtx->cursorVtx[0].v.ob[1] - 16;

    if (pauseCtx->cursorSpecialPos == 0) {
        switch (pauseCtx->pageIndex) {
            case PAUSE_ITEM:
                pauseCtx->cursorX = sItemMaskCursorsX[pauseCtx->cursorXIndex[PAUSE_ITEM]];
                pauseCtx->cursorY = sItemMaskCursorsY[pauseCtx->cursorYIndex[PAUSE_ITEM]];
                pauseCtx->cursorWidth = 15.0f;
                pauseCtx->cursorHeight = 15.0f;
                break;

            case PAUSE_MAP:
                if (!sInDungeonScene) {
                    if (IS_PAUSE_STATE_OWL_WARP(pauseCtx)) {
                        pauseCtx->cursorX = sOwlWarpWorldMapCursorsX[pauseCtx->cursorPoint[PAUSE_WORLD_MAP]];
                        pauseCtx->cursorY = sOwlWarpWorldMapCursorsY[pauseCtx->cursorPoint[PAUSE_WORLD_MAP]];
                    } else {
                        pauseCtx->cursorX = sWorldMapCursorsX[pauseCtx->cursorPoint[PAUSE_WORLD_MAP]];
                        pauseCtx->cursorY = sWorldMapCursorsY[pauseCtx->cursorPoint[PAUSE_WORLD_MAP]];
                    }
                    if (!IS_PAUSE_STATE_OWL_WARP(pauseCtx)) {
                        pauseCtx->cursorHeight = 10.0f;
                        pauseCtx->cursorWidth = 10.0f;
                    } else {
                        pauseCtx->cursorHeight = 15.0f;
                        pauseCtx->cursorWidth = 15.0f;
                    }
                } else {
                    pauseCtx->cursorX = sDungeonMapCursorsX[pauseCtx->cursorPoint[PAUSE_MAP]];
                    pauseCtx->cursorY = sDungeonMapCursorsY[pauseCtx->cursorPoint[PAUSE_MAP]];
                    if (pauseCtx->cursorSlot[pauseCtx->pageIndex] >= DUNGEON_FLOOR_INDEX_4) {
                        
                        pauseCtx->cursorWidth = 18.0f;
                        pauseCtx->cursorHeight = 12.0f;
                    } else if (pauseCtx->cursorSlot[pauseCtx->pageIndex] == DUNGEON_STRAY_FAIRIES) {
                        
                        pauseCtx->cursorHeight = 12.0f;
                        pauseCtx->cursorWidth = 40.0f;
                    } else {
                        
                        pauseCtx->cursorHeight = 15.0f;
                        pauseCtx->cursorWidth = 15.0f;
                    }
                }
                break;

            case PAUSE_QUEST:
                if (!R_PAUSE_DBG_QUEST_CURSOR_ON) {
                    pauseCtx->cursorX = sQuestStatusCursorsX[pauseCtx->cursorPoint[PAUSE_QUEST]];
                    pauseCtx->cursorY = sQuestStatusCursorsY[pauseCtx->cursorPoint[PAUSE_QUEST]];
                } else {
                    pauseCtx->cursorX = R_PAUSE_DBG_QUEST_CURSOR_X;
                    pauseCtx->cursorY = R_PAUSE_DBG_QUEST_CURSOR_Y;
                }
                pauseCtx->cursorHeight = 17.0f;
                pauseCtx->cursorWidth = 17.0f;
                if (pauseCtx->cursorSlot[pauseCtx->pageIndex] == QUEST_17) {
                    pauseCtx->cursorHeight = 25.0f;
                    pauseCtx->cursorWidth = 25.0f;
                } else if (pauseCtx->cursorSlot[pauseCtx->pageIndex] <= QUEST_SWORD) {
                    pauseCtx->cursorHeight = 18.0f;
                    pauseCtx->cursorWidth = 18.0f;
                } else if ((pauseCtx->cursorSlot[pauseCtx->pageIndex] >= QUEST_SONG_SONATA) &&
                           (pauseCtx->cursorSlot[pauseCtx->pageIndex] <= QUEST_SONG_SUN)) {
                    pauseCtx->cursorHeight = 12.0f;
                    pauseCtx->cursorWidth = 12.0f;
                }
                break;

            case PAUSE_MASK:
                pauseCtx->cursorX = sItemMaskCursorsX[pauseCtx->cursorXIndex[PAUSE_MASK]];
                pauseCtx->cursorY = sItemMaskCursorsY[pauseCtx->cursorYIndex[PAUSE_MASK]];
                pauseCtx->cursorWidth = 15.0f;
                pauseCtx->cursorHeight = 15.0f;
                break;

            default:
                break;
        }

        pauseCtx->cursorSpinPhase += 0x300;
    } else {
        if (pauseCtx->cursorSpecialPos == PAUSE_CURSOR_PAGE_LEFT) {
            pauseCtx->cursorX = -93.0f;
        } else { 
            pauseCtx->cursorX = 101.0f;
        }
        pauseCtx->cursorSpinPhase += 0x300;
        pauseCtx->cursorHeight = 16.0f;
        pauseCtx->cursorWidth = 16.0f;
        pauseCtx->cursorY = -4.0f;
    }

    if (pauseCtx->cursorWidth < pauseCtx->cursorShrinkRate) {
        pauseCtx->cursorWidth = 0;
    } else {
        pauseCtx->cursorWidth -= pauseCtx->cursorShrinkRate;
    }

    if (pauseCtx->cursorHeight < pauseCtx->cursorShrinkRate) {
        pauseCtx->cursorHeight = 0.0f;
    } else {
        pauseCtx->cursorHeight -= pauseCtx->cursorShrinkRate;
    }

    if (pauseCtx->cursorShrinkRate != 0.0f) {
        pauseCtx->cursorShrinkRate -= 1.0f;
    }

    sCursorCirclesX[0] = Math_SinS(pauseCtx->cursorSpinPhase) * pauseCtx->cursorWidth;
    sCursorCirclesX[1] = Math_SinS(pauseCtx->cursorSpinPhase + 0x4000) * pauseCtx->cursorWidth;
    sCursorCirclesX[2] = Math_SinS(pauseCtx->cursorSpinPhase + 0x8000) * pauseCtx->cursorWidth;
    sCursorCirclesX[3] = Math_SinS(pauseCtx->cursorSpinPhase + 0xC000) * pauseCtx->cursorWidth;
    sCursorCirclesY[0] = Math_CosS(pauseCtx->cursorSpinPhase) * pauseCtx->cursorHeight;
    sCursorCirclesY[1] = Math_CosS(pauseCtx->cursorSpinPhase + 0x4000) * pauseCtx->cursorHeight;
    sCursorCirclesY[2] = Math_CosS(pauseCtx->cursorSpinPhase + 0x8000) * pauseCtx->cursorHeight;
    sCursorCirclesY[3] = Math_CosS(pauseCtx->cursorSpinPhase + 0xC000) * pauseCtx->cursorHeight;
}
